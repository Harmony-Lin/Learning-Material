#include<iostream>





//补充函数语句，实现以下功能：

/*
1.输入两个数a,b; 
2.用函数计算 a的b次方
3.将结果输出。
*/ 

using namespace std;

int function1(int m,int k)
{
	int sum=1; 
	for(int i=1;i<=k;i++)
	{
	 	sum=sum*m;
	}
	
	return sum;
 } 
int main()
{
	int a,b;
	cin>>a>>b;
	int ans;
	//如何调用函数？ 
	ans=function1(a,b);
	cout<<ans;
	return 0; 
 } 
