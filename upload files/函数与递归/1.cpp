#include<iostream>
using namespace std;
 
int b=10; 



int function1(int m)
{
	m++;
	
	return m; 
}

void function2()
{
	b+=1;
	
	
	//void����û��return 
}

int main()
{
	int a=10;
	cout<<a<<endl;//ԭ����a 
	a=function1(a);//����function1 
	cout<<a<<endl;//ִ��function1֮���a
	
	cout<<b<<endl;//ԭ����b 
	function2();//����function2 
	cout<<b<<endl;//ִ��function2֮���b  
	
	return 0; 
} 
