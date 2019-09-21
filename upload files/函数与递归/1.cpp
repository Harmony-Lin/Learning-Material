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
	
	
	//void类型没有return 
}

int main()
{
	int a=10;
	cout<<a<<endl;//原来的a 
	a=function1(a);//调用function1 
	cout<<a<<endl;//执行function1之后的a
	
	cout<<b<<endl;//原来的b 
	function2();//调用function2 
	cout<<b<<endl;//执行function2之后的b  
	
	return 0; 
} 
