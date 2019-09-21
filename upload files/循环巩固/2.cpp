//GFLSPC
//2

#include<iostream>

using namespace std;

int main(){
	int a[10];
	int n;
	cin>>n;//输入数组大小 
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];//输入数组 
	 } 
	 
	 
	for(int j=n-1;j>=0;j--)
	{
		cout<<a[j]<<" ";
	 } 
	 
	 return 0;
}

