//GFLSPC
//2
//��С���� 
#include<iostream>

using namespace std;

int main()
{
	int a[10];
	int n;
	cin>>n;//���������С 
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];//�������� 
	} 
	 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i] < a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";//������� 
	} 
	return 0;
 } 
 
 //˼������δӴ�С���� 
