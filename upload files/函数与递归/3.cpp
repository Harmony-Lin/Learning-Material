#include<iostream>
//#include<math.h>//ǿ���math.h�⣬�и�����ѧ����ר�ú��� 

using namespace std;
int abs(int m)
{
	if(m>=0)
	{
		return m;
	}
	else if(m<0)
	{
		return -m;
	}
}

int main(){
	/*float a=-1.12;
	int b=floor(a);
	int c=ceil(a);*/
	int m=-9;
	int d=abs(m);
	cout<<d;
	return 0;
	
	
}
