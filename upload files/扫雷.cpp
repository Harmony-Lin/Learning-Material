//#include"pch.h"
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<Windows.h>

#define N 3 //用来控制屏幕居中值

using namespace std;

int choose1,choose2;//用户选择的难度
int final_score = 0;//总分
int s = 1;//局数
char a[35][35];//定义全局棋盘，先全部定义为未选状态。即下划线：95。这个是在游戏结束后给用户看的
char b[35][35];//这个是用户在游戏上实时看到的界面，也全部定义为下划线。
int rest;//剩下的小旗数

struct result{//记录成绩
	float t;
	int difficulty;
	int size;
	bool win;
}res[20];

void welcome()//欢迎以及选择难度。
{
	cout << endl << endl << endl << endl;
	cout << "                                          " << "欢迎来到扫雷游戏" << endl << endl;
	cout << "                                  " << "作者：广州外国语学校编程社茹法锐" << endl << endl;
	cout << "                                            " << "请输入两个数选择游戏难度：" << endl;
	cout << "                                             " << "1.20个地雷" << endl;
	cout << "                                             " << "2.40个地雷" << endl;
	cout << "                                             " << "3.90个地雷" << endl;
	cout << endl;
	cout << "                                             " << "1.10x10大小" << endl;
	cout << "                                             " << "2.20x20大小" << endl;
	cout << "                                             " << "3.30x30大小" << endl;
	cout << endl;

	LOOP1:cin >> choose1>>choose2;

	if (choose1 < 0 || choose2 < 0 || choose1>3 || choose2>3)
	{
		cout << "输入错误，请输入两个1~3的整数，用空格隔开" << endl;
		goto LOOP1;
	}

	system("cls");//清屏

	switch (choose1)//将用户选择的难度转化为雷数
	{
		case 1:
			res[s].difficulty = 20;
			break;
		case 2:
			res[s].difficulty = 40;
			break;
		case 3:
			res[s].difficulty = 90;
			break;
	}
	rest = res[s].difficulty;//将雷数赋值给剩余雷数

	res[s].size = choose2 * choose2 * 100;//整个棋盘的大小

	return;
}

void tell_rule()
{
	cout << endl << endl << endl << endl;
	cout << "                                             " << "请输入三个字符来表示您的操作" << endl << endl;
	cout << "                                       " << "第一个字符：要操作位置的横坐标（数字）" << endl<<endl;
	cout << "                                     " << "第二个字符：要操作位置的纵坐标（小写字母）" << endl << endl;
	cout << "                                 " << "第三个字符：操作类型：1.踩下  2.插小旗 3.拔小旗" << endl << endl;
	system("pause");
	system("cls");
}

void build()//将雷生成，并写入二维数组 a
{
	for (int i = 0; i < choose2 * 10; i++)
	{
		for (int j = 0; j < choose2 * 10; j++)
		{
			a[i][j] = 95;
			b[i][j] = 95;
		}
	}

	srand((unsigned)time(NULL));//初始化时间种子

	int m, n;
	for (int i = 0; i < res[s].difficulty; i++)
	{
		
		
		m = rand() % choose2*10;//横坐标
		n = rand() % choose2*10;//纵坐标

		while (1)
		{
			if (a[m][n] != 79)
			{
				a[m][n] = 79;//79为大写字母O
				break;//如果和之前的没有重复，直接写入
			}

			int temp = rand() % 4;//否则的话用随机数看看上下左右选哪个好
			switch (temp)
			{
			case 0:
				m++;
				if (m > choose2 * 10)
				{
					m -= 4;
				}
				break;
			case 1:
				m--;
				if (m < 0)
				{
					m += 4;
				}
				break;
			case 2:
				n++;
				if (n > choose2 * 10)
				{
					n -= 4;
				}
				break;
			case 3:
				n--;
				if (n < 0)
				{
					n += 4;
				}
				break;
			}
		}
	}
	return;
}

void show_b()//用户在使用时每输入一次就刷新一次二维数组 b。
{
	int p = 0;//位于屏幕上方的数字坐标
	char q = 97;//位于屏幕左边的字母坐标
	cout << "   ";
	for (p = 0; p < choose2 * 10; p++)//输出上坐标
		cout << setw(N) << p;
	cout << endl;

	for (int i = 0; i < choose2 * 10; i++)
	{
		cout << setw(N) << q;
		q++;
		for (int j = 0; j < choose2 * 10; j++)
		{
			cout << setw(N) << b[j][i];
		}
		cout << endl;
	}
	cout << endl<<"剩余小旗数" << rest << endl<<endl;
}

void lose()
{

	int p = 0;//位于屏幕上方的数字坐标
	char q = 97;//位于屏幕左边的字母坐标
	cout << "   ";
	for (p = 0; p < choose2 * 10; p++)//输出上坐标
		cout << setw(N) << p;
	cout << endl;

	for (int i = 0; i < choose2 * 10; i++)
	{
		cout << setw(N) << q;
		q++;
		for (int j = 0; j < choose2 * 10; j++)
		{
			if (b[j][i] == 33)//用户标了雷
			{
				if (a[j][i] == 95)//没有雷
				{
					cout << setw(N) << "X";
					continue;
				}
				if (a[j][i] == 79)//有雷
				{
					cout << setw(N) << "O";
					continue;
				}
			}
			cout << setw(N) << a[j][i];
		}
		cout << endl;
	}
	system("pause");//写到这里
	return;
}

void ask()
{
	int x,type;
	char y;
	cout << endl;
	while (1)//一直问用户直到得到合法输入
	{
		LOOP2:cout << "请输入:" << endl;
		cin >> x >> y >> type;
		y -= 'a';//将用户输入的字母转换为数字
		if (x<0 || x>=choose2 * 10 || (int)y < 0 || (int)y >= choose2 * 10)//输入压根不合法
		{
			cout << "输入非法" << endl;
			cout << "请输入三个字符来表示您的操作" << endl;
			cout << "第一个字符：要操作位置的横坐标（数字）" << endl;
			cout << "第二个字符：要操作位置的纵坐标（小写字母）" << endl;
			cout << "第三个字符：操作类型：1.踩下  2.插小旗 3.拔小旗" << endl;
			system("pause");
		}
		else
		{
			break;
		}
	}

	if (type == 1)//踩下
	{
		if (b[x][y] == 33)//标了雷
			rest++;

		if (a[x][y] == 79)//有雷
		{
			system("cls");
			cout << "you lose!" << endl;
			Sleep(5000);
			system("cls");
			lose();
		}

		int sum = 0;//周边的雷数,有越界bug
		if (a[x + 1][y] == 79)
			sum++;
		if (a[x - 1][y] == 79)
			sum++;
		if (a[x][y + 1] == 79)
			sum++;
		if (a[x][y - 1] == 79)
			sum++;
		if (a[x + 1][y + 1] == 79)
			sum++;
		if (a[x + 1][y - 1] == 79)
			sum++;
		if (a[x - 1][y + 1] == 79)
			sum++;
		if (a[x - 1][y - 1] == 79)
			sum++;

		b[x][y] = sum + 48;//将下划线变为数字
		return;
	}

	if (type == 2)//插小旗
	{
		if (b[x][(int)y] != 95)//不是未知
		{
			goto LOOP2;//去提示错误那里
		}
		else
		{
			b[x][(int)y] = 33;//将下划线变为感叹号
			rest--;//剩余小旗数减一
		}
		return;
	}

	if (type == 3)//拔小旗
	{
		if (b[x][y] != 33)//不是小旗
		{

			goto LOOP2;
		}
		else
		{
			b[x][y] = 95;//将感叹号变回下划线
			rest++;//剩余小旗数加一
		}
	}
	return;
}

int main()//主函数
{
	system("mode con cols=300 lines=40");//改变宽高
	system("color 0f");//改变颜色
	cout << (char)182;
	while (1)
	{
		s++;//局数加一
		welcome();//欢迎以及选择难度。
		tell_rule();//输出游戏规则。
		build();//随机生成地雷。
		
		while (1)
		{
			show_b();

			ask();

			system("cls");
		}
	}
}