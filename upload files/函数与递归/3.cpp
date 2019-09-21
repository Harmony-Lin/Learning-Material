#include<iostream>
//#include<math.h>//强大的math.h库，有各种数学计算专用函数 

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
