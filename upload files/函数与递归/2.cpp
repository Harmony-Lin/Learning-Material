#include<iostream>
using namespace std;

int haha(int *m)
{
	int n=*m;
	n+=1;
	return n;
}


int main()
{
	int a=10;
	int* b = &a;
	//cout<<b;
	a=haha(b);
	cout<<a;
	return 0;
	
}
