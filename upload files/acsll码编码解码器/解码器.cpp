/*
 
 破译以下信息：
 （提示：强制类型转换） 
87
69
76
67
79
77
69
116
111
71
87
80
67
33
*/






#include<iostream>
using namespace std;

int main()
{
	int a[500];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<(char)a[i];
	}
	return 0;
}
