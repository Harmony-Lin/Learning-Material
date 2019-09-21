#include<iostream>

using namespace std;

int haha(int n)
{
	if(n==0)
	{
		return 1;
		
	}
	else
	{
		return haha(n-1)*n;
		
	}
	
 } 
 
 int main()
 {
 	int a;
 	cin>>a;
 	cout<<haha(a);
 	
 	return 0;
 	
 	
  } 
