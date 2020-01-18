#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<conio.h>

#define N 4 //¿ØÖÆÍæ¼ÒµÄx×ø±ê 

using namespace std;

char a[40][20]; 
double timestart;//¿ªÊ¼Ê±¼ä 
int d;//ÄÑ¶ÈÑ¡Ôñ
int nowy=10;//µ±Ç°Íæ¼Òy×ø±ê 
int number = 0;

struct s {
	int difficulty;
	int point;
}player[50];

void build()
{
	srand((unsigned)time(NULL));
	bool dire = rand() % 2;
	int l = rand() % 8 + 5;//³¤¶È 

	if (dire)
	{
		for (int i = 0; i < l; i++)
		{
			a[39][i] = '|';//Éú³ÉÉÏÖù×Ó
		}
	}
	else
	{
		for (int i = 19; 19 - i < l; i--)
		{
			a[39][i] = '|';//Éú³ÉÏÂÖù×Ó 
		}
	}
}

void move()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if(a[0][j]=='|')//µ½Í·ÁË 
			{
				a[0][j]=' ';
			}
			else if (a[j][i]=='|')
			{
				a[j][i] = ' ';//Çå³ıÔ­À´µÄ
				a[j-1][i] = '|';//ÏòÇ°ÍÆÒ»¸ö
			}
		}
	}
}

void flush()
{
	system("cls");
	cout<<"############################################"<<endl;//ÉÏ±ß½ç¿ò 
	for (int i = 0; i < 20; i++)
	{
		//cout<<i+10;
		cout<<"# ";//×ó±ß½ç¿ò 
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
		cout <<" #"<< endl;//ÓÒ±ß½ç¿ò 
	}
	cout<<"############################################"<<endl;//ÏÂ±ß½ç¿ò 
	cout << "time:" << " " << time(NULL) - timestart;
}


void score()
{
	system("cls");
	cout << endl << endl << endl;
	int max=0; 
	for(int i=1;i<=number;i++)
	{
		cout << "                    " << "µÚ"<<i<<"¾Ö" << endl ;
		cout << "                        " << "ÄÑ¶È£º"<<player[i].difficulty<<endl; 
		cout << "                        " << "µÃ·Ö£º"<<player[i].point << endl << endl;
		max=((player[i].point>max)?player[i].point:max);//±È½Ï×î´óÖµ 
	}
	cout << "                        " << "×î¸ß·Ö£º"<< max << endl << endl;
	system("pause");
	system("cls");
}

void end()
{
	system("cls");
	flush();
	cout<<endl<<"you lose!"<<endl;
	player[number].point= time(NULL) - timestart;//¶Ô·ÖÊı½øĞĞ¸³Öµ 
	system("pause");
	system("cls");
	score();
	return;
}





void welcome()
{
	system("cls");
	cout << endl << endl << endl;
	cout <<"                    " << "»¶Ó­½øÈëÓÎÏ·¡°±ğ×²Öù×Ó" << endl<<endl;
	cout << "                  " << "×÷Õß£º¹ãÍâlazybones±à³ÌÉç¾" << endl << endl;
	system("pause");
	system("cls");
}

void rule()//Êä³ö¹æÔò²¢ÊäÈëÄÑ¶È 
{
	system("cls");
	cout << endl << endl << endl;
	cout << "                    " << "Çë°´ÉÏ¼üÏòÉÏ,ÏÂ¼üÏòÏÂ,ÓÒ¼üĞüÍ£" << endl << endl;
	cout << "                        " << "Ê¹·É»ú±Ü¿ªÒÆ¶¯µÄÖù×Ó" << endl << endl;
	//cout << "                            " << "¿Õ¸ñ¼ü¿ÉÔİÍ£" << endl << endl;
	cout << "                      " << "ÏÖÔÚ£¬ÇëÊäÈëÄÑ¶È£º1¡ª5" << endl << endl;
	cout << "                            £º"  ;
	cin >> d;
	player[number].difficulty = d;//¶Ô½á¹¹ÌåÄÚÄÑ¶È½øĞĞ¸³Öµ
	d = 100 - d * 15;//¶Ôd½øĞĞËÙ¶È¼ä¸ô´¦Àí£¨Í¨¹ıµ÷ÕûÕâÀïµÄÊıÖµ¿ÉÒÔµ÷ÕûÓÎÏ·ËÙ¶È£© 
	system("cls");
	return;
}

void clean()//Çå¿Õ¶şÎ¬Êı×é 
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
		LOOP1://ĞÂÒ»¾ÖµÄ¿ªÊ¼£¬Î¥¹æµØÓÃÁËÒ»¸ögoto 
		number++;//¾ÖÊı¼ÓÒ» 
		clean();//½«¶şÎ¬Êı×éÇå¿Õ 
		rule();
		timestart = time(NULL);
		

		int process=0;
		while (1)
		{
			process++;
			if (process%10 == 0)//Éú³ÉÖù×ÓËÙ¶È¿ØÖÆ 
			{
				build();
			}
			
			move();//ÒÆ¶¯Öù×Ó 
			
			
			bool flag = 1;//ÓÃÀ´¼ì²âÊÇ·ñ°´ÏÂ£¬µ«ÊÇÓÉÓÚ»º³åÇøÎŞ·¨Çå¿ÕµÄÔ­ÒòËÆºõ²¢Ã»ÓĞÊ²Ã´ÓÃ 
			long int cl = clock();//Õâ¸öÊÇÓÃ¼ì²â¼ì²âÊ±¼äµÄ£¬ÔÚÕâ¶ÎÊ±¼ä£¨dºÁÃëÄÚ£©»áµÈ´ıÓÃ»§µÄÊäÈë£¬ÆäËûÊ±¼äÔòÖ´ĞĞÆäËû´úÂë 
			while ((flag = (clock() - cl <= d)) && !_kbhit());//Èç¹ûÓĞ¼ü°´ÏÂ»òÊ±¼ä³¬¹ı×Ô¶¯Ç°½øÊ±¼ä¼ä¸ôÔòÖÕÖ¹Ñ­»·
			
			char key; 
			if (flag)
			{
				key = _getch();
			}
			
			
			else
			{
				switch(key)
				{
					case 80://ÏòÉÏ 
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
					case 72://ÏòÏÂ 
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
					default://°´ÁËÆäËûµÄ,Í£ÔÚÄÇÀï 
						if(a[N][nowy]=='|')
						{
							end();
							goto LOOP1;
						}
						break;
				}
			}
			
			flush();//Ë¢ĞÂÆÁÄ»
		}

	}
	return 0; 
}
