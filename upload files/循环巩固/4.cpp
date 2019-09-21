//GFLSPC
//2
//死循环 
#include<iostream>
#include<cstring> 
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	
	for(int i=1;;i++)
	{
		cout<<"好好学编程"<<"*"<<i<<endl;
		if(i==n)
		{
			break;
		 } 
		
	}
	
	/*while(1)
	{
		cout<<"好好学编程"<<endl;
	}*/
	
	
	
	return 0;
 } 
