#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<conio.h>

#define N 4 //������ҵ�x���� 

using namespace std;

char a[40][20]; 
double timestart;//��ʼʱ�� 
int d;//�Ѷ�ѡ��
int nowy=10;//��ǰ���y���� 
int number = 0;

struct s {
	int difficulty;
	int point;
}player[50];

void build()
{
	srand((unsigned)time(NULL));
	bool dire = rand() % 2;
	int l = rand() % 8 + 5;//���� 

	if (dire)
	{
		for (int i = 0; i < l; i++)
		{
			a[39][i] = '|';//����������
		}
	}
	else
	{
		for (int i = 19; 19 - i < l; i--)
		{
			a[39][i] = '|';//���������� 
		}
	}
}

void move()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if(a[0][j]=='|')//��ͷ�� 
			{
				a[0][j]=' ';
			}
			else if (a[j][i]=='|')
			{
				a[j][i] = ' ';//���ԭ����
				a[j-1][i] = '|';//��ǰ��һ��
			}
		}
	}
}

void flush()
{
	system("cls");
	cout<<"############################################"<<endl;//�ϱ߽�� 
	for (int i = 0; i < 20; i++)
	{
		//cout<<i+10;
		cout<<"# ";//��߽�� 
		for (int j = 0; j < 40; j++)
		{
			if(j==N&&i==nowy)
			{
				cout<<"*";
			}
			else
			{
				cout << a[j][i];
			}
		}
		cout <<" #"<< endl;//�ұ߽�� 
	}
	cout<<"############################################"<<endl;//�±߽�� 
	cout << "time:" << " " << time(NULL) - timestart;
}


void score()
{
	system("cls");
	cout << endl << endl << endl;
	int max=0; 
	for(int i=1;i<=number;i++)
	{
		cout << "                    " << "��"<<i<<"��" << endl ;
		cout << "                        " << "�Ѷȣ�"<<player[i].difficulty<<endl; 
		cout << "                        " << "�÷֣�"<<player[i].point << endl << endl;
		max=((player[i].point>max)?player[i].point:max);//�Ƚ����ֵ 
	}
	cout << "                        " << "��߷֣�"<< max << endl << endl;
	system("pause");
	system("cls");
}

void end()
{
	system("cls");
	flush();
	cout<<endl<<"you lose!"<<endl;
	player[number].point= time(NULL) - timestart;//�Է������и�ֵ 
	system("pause");
	system("cls");
	score();
	return;
}





void welcome()
{
	system("cls");
	cout << endl << endl << endl;
	cout <<"                    " << "��ӭ������Ϸ����ײ���Ӑ" << endl<<endl;
	cout << "                  " << "���ߣ�����lazybones�����" << endl << endl;
	system("pause");
	system("cls");
}

void rule()//������������Ѷ� 
{
	system("cls");
	cout << endl << endl << endl;
	cout << "                    " << "�밴�ϼ�����,�¼�����,�Ҽ���ͣ" << endl << endl;
	cout << "                        " << "ʹ�ɻ��ܿ��ƶ�������" << endl << endl;
	//cout << "                            " << "�ո������ͣ" << endl << endl;
	cout << "                      " << "���ڣ��������Ѷȣ�1��5" << endl << endl;
	cout << "                            ��"  ;
	cin >> d;
	player[number].difficulty = d;//�Խṹ�����ѶȽ��и�ֵ
	d = 100 - d * 15;//��d�����ٶȼ������ͨ�������������ֵ���Ե�����Ϸ�ٶȣ� 
	system("cls");
	return;
}

void clean()//��ն�ά���� 
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			a[j][i]=' ';
		}
	}
	return;
}


int main()
{
	welcome();
	
	while (1)
	{
		LOOP1://��һ�ֵĿ�ʼ��Υ�������һ��goto 
		number++;//������һ 
		clean();//����ά������� 
		rule();
		timestart = time(NULL);
		

		int process=0;
		while (1)
		{
			process++;
			if (process%10 == 0)//���������ٶȿ��� 
			{
				build();
			}
			
			move();//�ƶ����� 
			
			
			bool flag = 1;//��������Ƿ��£��������ڻ������޷���յ�ԭ���ƺ���û��ʲô�� 
			long int cl = clock();//������ü����ʱ��ģ������ʱ�䣨d�����ڣ���ȴ��û������룬����ʱ����ִ���������� 
			while ((flag = (clock() - cl <= d)) && !_kbhit());//����м����»�ʱ�䳬���Զ�ǰ��ʱ��������ֹѭ��
			
			char key; 
			if (flag)
			{
				key = _getch();
			}
			
			
			else
			{
				switch(key)
				{
					case 80://���� 
						if(a[N][nowy+1]==' ')
						{
							a[N][nowy]=' ';
							nowy++;
							a[N][nowy]='*';
							break;
						}
						else
						{
							end();
							goto LOOP1;
						}
					case 72://���� 
						if(a[N][nowy-1]==' ')
						{
							a[N][nowy]=' ';
							nowy--;
							a[N][nowy]='*';
							break;
						}
						else
						{
							
						}
						break;
					default://����������,ͣ������ 
						if(a[N][nowy]=='|')
						{
							end();
							goto LOOP1;
						}
						break;
				}
			}
			
			flush();//ˢ����Ļ
		}

	}
	return 0; 
}
