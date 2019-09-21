#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	char a[500];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		//cout<<(int)a[i]<<endl;
		printf("%d\n",a[i]);
	}
	return 0;
 } 
 
 
 
 /*
 
 14
WELCOMEtoGWPC!
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
