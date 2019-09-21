//GFLSPC
//2
//从小到大 
#include<iostream>

using namespace std;

int main()
{
	int a[10];
	int n;
	cin>>n;//输入数组大小 
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];//输入数组 
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
		cout<<a[i]<<" ";//输出数组 
	} 
	return 0;
 } 
 
 //思考：如何从大到小排序？ 
