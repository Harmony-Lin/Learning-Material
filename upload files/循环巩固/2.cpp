//GFLSPC
//2

#include<iostream>

using namespace std;

int main(){
	int a[10];
	int n;
	cin>>n;//���������С 
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];//�������� 
	 } 
	 
	 
	for(int j=n-1;j>=0;j--)
	{
		cout<<a[j]<<" ";
	 } 
	 
	 return 0;
}

