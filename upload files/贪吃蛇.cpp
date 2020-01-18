//#include"pch.h"//可以被vs2017编译通过
#include <stdlib.h>  //srand函数的库
#include <conio.h>  //_getch函数
#include <time.h>  //time函数的库（用于生成随机数）
#include <iostream>  //基本输入输出

#define  N 22  //使用一个全局定量来规定游戏区的大小，是值得学习的做法。因为这样方便随时修改。

using namespace std;


//以下是全局变量：
int gameover;//输赢状态

int food_x, food_y; // 随机出米  

int x, y;//这是蛇头的坐标

long start;

//=======================================  
//类的实现与应用initialize(初始化）
//=======================================  

//下面定义贪吃蛇的坐标类  
class snake_position
{
public://必须定义为公用

	int x, y;//x表示行，y表示列  

	snake_position() {};

	void initialize(int &);//坐标初始化  

};

snake_position position[(N - 2)*(N - 2) + 1]; //定义贪吃蛇坐标类数组，有(N-2)*(N-2)个坐标  

void snake_position::initialize(int &j)//也是初始化
{
	x = 1;
	y = j;
}


//下面定义贪吃蛇的棋盘图  

class snake_map
{
private:

	char s[N][N];//定义贪吃蛇棋盘，包括墙壁。

	int grade, length;//级数和长度

	int gamespeed; //前进时间间隔  

	char direction; // 初始情况下，向右运动  

	int head, tail;

	int score;//分数

	bool gameauto;//是否选择自动升级模式

public:

	snake_map(int h = 4, int t = 1, int l = 4, char d = 77, int s = 0) :length(l), direction(d), head(h), tail(t), score(s) {}

	void initialize();   //声明函数  

	void show_game();

	int updata_game();

	void setpoint();

	void getgrade();

	void display();


};

//定义初始化函数，将贪吃蛇的棋盘图进行初始化  

void snake_map::initialize()
{
	int i, j;

	for (i = 1; i <= 3; i++)

		s[1][i] = '*';

	s[1][4] = '#';

	for (i = 1; i <= N - 2; i++)

		for (j = 1; j <= N - 2; j++)

			s[i][j] = ' '; // 初始化贪吃蛇棋盘中间空白部分  （先全部设为空白）

	for (i = 0; i <= N - 1; i++)

		s[0][i] = s[N - 1][i] = '-'; //初始化贪吃蛇棋盘上下墙壁  

	for (i = 1; i <= N - 2; i++)

		s[i][0] = s[i][N - 1] = '|'; //初始化贪吃蛇棋盘左右墙壁  
}


//============================================  
//输出贪吃蛇棋盘信息  

void snake_map::show_game()//输出函数
{

	system("cls"); // 清屏  

	int i, j;//二维数组输出

	cout << endl;

	for (i = 0; i < N; i++)
	{

		cout << '\t';//先空一行

		for (j = 0; j < N; j++)
		{
			cout << s[i][j] << ' '; // 输出贪吃蛇的全部内容
		}
		//下面是在右边的提示
		if (i == 2) cout << "\t等级：" << grade;
		if (i == 6) cout << "\t速度：" << gamespeed;
		if (i == 10) cout << "\t得分：" << score << "分";
		if (i == 14) cout << "\t暂停：按一下空格键";
		if (i == 18) cout << "\t继续：按两下空格键";

		cout << endl;
	}
}


void snake_map::getgrade()//输入选择等级  
{
	cin >> grade;

	while (grade > 7 || grade < 1)//如果遇到非法输入
	{
		cout << "请输入数字1-7选择等级，输入其他数字无效" << endl;

		cin >> grade;
	}
	switch (grade)
	{
	case 1: gamespeed = 1000; gameauto = 0; break;

	case 2: gamespeed = 800; gameauto = 0; break;

	case 3: gamespeed = 600; gameauto = 0; break;

	case 4: gamespeed = 400; gameauto = 0; break;

	case 5: gamespeed = 200; gameauto = 0; break;

	case 6: gamespeed = 100; gameauto = 0; break;

	case 7: grade = 1; gamespeed = 1000; gameauto = 1; break;

	}
}


void snake_map::display()//输出等级，得分情况以及称号  
{

	cout << "\n\t\t\t\t等级：" << grade;

	cout << "\n\n\n\t\t\t\t速度：" << gamespeed;

	cout << "\n\n\n\t\t\t\t得分：" << score << "分";

}


void snake_map::setpoint()//随机产生米  
{
	srand((unsigned)time(NULL));

	do{

		food_x = rand() % (N - 2) + 1;

		food_y = rand() % (N - 2) + 1;

	} while (s[food_x][food_y] != ' ');

	s[food_x][food_y] = '*';
}

char key;

int snake_map::updata_game()
{
	gameover = 1;

	key = direction;

	start = clock();

	while ((gameover = (clock() - start <= gamespeed)) && !_kbhit());//如果有键按下或时间超过自动前进时间间隔则终止循环  



	if (gameover)
	{

		_getch();

		key = _getch();
	}

	if (key == ' ')
	{
		while (_getch() != ' ') {};//这里实现的是按空格键暂停，按空格键继续的功能，但不知为何原因，需要按两下空格才能继续。这是个bug。  
	}
	else//排除其他情况，就是方向键
	{
		direction = key;
	}

	switch (direction)//按照上下左右的指示改变蛇头方向
	{
		case 72: x = position[head].x - 1; y = position[head].y; break; // 向上  
				
		case 80: x = position[head].x + 1; y = position[head].y; break; // 向下  

		case 75: x = position[head].x; y = position[head].y - 1; break; // 向左  

		case 77: x = position[head].x; y = position[head].y + 1; break; // 向右  

		default:gameover = 0;//不是方向键，即非法输入，那么你输了。
	}

	
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1)   // 碰到墙壁  
	{
		gameover = 0;//那么你输了
	}
	else if (s[x][y] != ' ' && !(x == food_x && y == food_y))    // 蛇头碰到蛇身  
	{
		gameover = 0;//那么你输了
	}
	else if (x == food_x && y == food_y)// 吃米，长度加1  
	{ 
		length++;//长度加一

		if (length >= 8 && gameauto)//如果是自动升级

		{

			length -= 8;

			grade++;

			if (gamespeed >= 200)//如果没有升到顶级
				gamespeed -= 200; // 改变贪吃蛇前进速度  
			else
				gamespeed = 100;//最高速，不能再快了

		}

		s[x][y] = '#';  //更新蛇头  

		s[position[head].x][position[head].y] = '*'; //吃米后将原先蛇头变为蛇身  

		head = (head + 1) % ((N - 2)*(N - 2));   //取蛇头坐标  

		position[head].x = x;//更新蛇头横坐标

		position[head].y = y;//更新蛇头纵坐标

		show_game();//调用输出函数，输出新的内容到屏幕

		gameover = 1;

		score += grade * 20;  //加分  

		setpoint();   //新产生米  

	}
	else// 没吃到米  
	{ 
		s[position[tail].x][position[tail].y] = ' ';//将蛇尾置空  

		tail = (tail + 1) % ((N - 2) * (N - 2));//更新蛇尾坐标  

		s[position[head].x][position[head].y] = '*';  //将蛇头更为蛇身  

		head = (head + 1) % ((N - 2) * (N - 2));

		position[head].x = x;//更新蛇头横坐标

		position[head].y = y;//更新蛇头纵坐标

		s[position[head].x][position[head].y] = '#'; //更新蛇头  

		gameover = 1;//没输

	}

	return gameover;//返回gameover的值，判断是否输了
}
//====================================  
//主函数部分  
//====================================  
int main()
{
	char ctn = 'y';//用来判断是否要再来一局

	int nodead;

	cout << "\n\n\n\n\n\t\t\t 欢迎进入贪吃蛇游戏!" << endl;//欢迎界面;  

	cout << "\n\n\n\t\t\t 按任意键马上开始……" << endl;//准备开始;;  

	_getch();//输入一个任意键

	while (ctn == 'y')//主循环，如果一直“再来一局”就一直执行下去
	{
		system("cls"); // 清屏  

		snake_map snake;//生成类

		snake.initialize();//调用初始化函数

		cout << "\n\n请输入数字选择游戏等级：" << endl;
		cout << "\n\n\n\t\t\t1.等级一：速度 1000 \n\n\t\t\t2.等级二：速度 800 \n\n\t\t\t3.等级三：速度 600 ";
		cout << "\n\n\t\t\t4.等级四：速度 400 \n\n\t\t\t5.等级五：速度 200 \n\n\t\t\t6.等级六：速度 100 \n\n\t\t\t7.自动升级模式" << endl;
		snake.getgrade();//获取等级  

		for (int i = 1; i <= 4; i++)
		{
			position[i].initialize(i);//初始化坐标  
		}

		snake.setpoint();  // 产生第一个米  

		do{
			snake.show_game();

			nodead = snake.updata_game();

		} while (nodead);

		system("cls"); //清屏  

		cout << "\n\n\n\t\t\t\tGameover！\n\n" << endl;

		snake.display();//输出等级/得分情况  

		cout << "\n\n\n\t\t    是否选择继续游戏？输入 y 继续，n 退出" << endl;

		cin >> ctn;

	}

	return 0;//程序结束
}

