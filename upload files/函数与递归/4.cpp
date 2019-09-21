#include<iostream>
using namespace std;

int haha(int m,int n)
{
	if(m>n)
		return m;
	else
		return n;
 } 

int main()
{
	int a,b;
	int result;
	cin>>a>>b;
	result=haha(a,b);
	cout<<result;
	return 0;
	
 } 
