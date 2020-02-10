//广州外国语学校Lazybones编程社学习资料  自制简易c++游戏之一——别撞柱子
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>
const int N = 4;//控制玩家的x坐标 
using namespace std;
char a[40][20];//储存地图
double timestart;//开始时间 
int d;//难度选择
int nowy = 10;//当前玩家y坐标 
int number = 0;//局数

struct s {//结构体用于储存每一局的得分
	int difficulty;//这一局的难度
	int point;//这一局的分数
}player[50];

void build()//生成柱子
{
	srand((unsigned)time(NULL));
	bool dire = rand() % 2;
	int l = rand() % 8 + 8;//长度 

	if (dire)
	{
		for (int i = 0; i < l; i++)
		{
			a[39][i] = '|';//生成上柱子
		}
	}
	else
	{
		for (int i = 19; 19 - i < l; i--)
		{
			a[39][i] = '|';//生成下柱子 
		}
	}
}

void move()//移动柱子
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (a[0][j] == '|')//到头了 
			{
				a[0][j] = ' ';
			}
			else if (a[j][i] == '|')
			{
				a[j][i] = ' ';//清除原来的
				a[j - 1][i] = '|';//向前推一个
			}
		}
	}
}

void flush()
{
	system("cls");
	cout << "############################################" << endl;//上边界框 
	for (int i = 0; i < 20; i++)
	{
		cout << "# ";//左边界框 
		for (int j = 0; j < 40; j++)
		{
			if (j == N && i == nowy)
			{
				cout << "*";
			}
			else
			{
				cout << a[j][i];
			}
		}
		cout << " #" << endl;//右边界框 
	}
	cout << "############################################" << endl;//下边界框 
	cout << "time:" << " " << time(NULL) - timestart;
}

void score()//输出得分
{
	system("cls");
	cout << endl << endl << endl;
	for (int i = 1; i <= number; i++)
	{
		cout << "                    " << "第" << i << "局" << endl;
		cout << "                        " << "难度：" << player[i].difficulty << endl;
		cout << "                       " << "得分：" << player[i].point << endl << endl;
	}

	system("pause");
	system("cls");
}

void end()//当一局结束时
{
	system("cls");
	flush();
	cout << endl << "you lose!" << endl;
	nowy = 10;//初始化玩家位置
	player[number].point = time(NULL) - timestart;//对分数进行赋值 
	system("pause");
	system("cls");
	score();//输出得分的函数
	return;
}

void welcome()//欢迎界面的输出
{
	cout << endl << endl << endl;
	cout << "                    " << "欢迎进入游戏“别撞柱子”" << endl<<endl;
	cout << "                  " << "作者：广外lazybones编程社" << endl << endl;
	system("pause");
	system("cls");
}

void rule()//输出规则并输入难度 
{
	system("cls");
	cout << endl << endl << endl;
	cout << "                    " << "请按上键向上,下键向下,右键悬停" << endl << endl;
	cout << "                        " << "使飞机避开移动的柱子以及上下边缘" << endl << endl;
	cout << "                            " << "空格键可暂停" << endl << endl;
	cout << "                      " << "现在，请输入难度：1—5" << endl << endl;
	cout << "                            ：";
	cin >> d;
	player[number].difficulty = d;//对结构体内难度进行赋值
	d = 100 - d * 10;//对d进行速度间隔处理（通过调整这里的数值可以调整游戏速度） 
	system("cls");
}

void clean()//清空二维数组 
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			a[j][i] = ' ';
		}
	}
	return;
}


int main()
{
	welcome();//输出欢迎界面

	while (1)
	{
	LOOP1://新一局的开始，“违规”地用了一个goto的标签 
		number++;//局数加一 
		clean();//将二维数组清空 
		rule();
		timestart = time(NULL);
		int process = 0;//控制速度
		char key = 0;
		while (1)
		{
			process++;
			if (process % 15 == 0)//生成柱子速度控制 
			{
				build();
			}

			if (process % 2 == 1)//移动柱子速度控制 
			{
				move();
			}
			bool flag = 1;//用来检测是否按下
			long int cl = clock();//这个是用检测检测时间的，在这段时间（d毫秒内）会等待用户的输入，其他时间则执行其他代码 
			while ((flag = (clock() - cl <= d)) && !_kbhit());//如果有键按下或时间超过自动前进时间间隔则终止循环

			if (flag)//如果有按键
			{
				key = _getch();//对当前方向进行重新赋值
			}
			switch (key)
			{
			case 80://向上 
				if (a[N][nowy + 1] == ' ' && nowy != 19)
				{
					a[N][nowy] = ' ';
					nowy++;
					a[N][nowy] = '*';
					break;
				}
				else
				{
					end();//结束本局，输出得分
					goto LOOP1;//跳出死循环，开始下一局
				}
			case 72://向下 
				if (a[N][nowy - 1] == ' ' && nowy != 0)
				{
					a[N][nowy] = ' ';
					nowy--;
					a[N][nowy] = '*';
					break;
				}
				else
				{
					end();//结束本局，输出得分
					goto LOOP1;//跳出死循环，开始下一局
				}
				break;
			default://按了其他的,停在那里 
				if (a[N][nowy] == '|')//正面撞上了
				{
					end();//结束本局，输出得分
					goto LOOP1;//跳出死循环，开始下一局
				}
				break;
			}
			flush();//刷新屏幕
		}
	}
}
