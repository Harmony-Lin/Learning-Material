#include<iostream>





//���亯����䣬ʵ�����¹��ܣ�

/*
1.����������a,b; 
2.�ú������� a��b�η�
3.����������
*/ 

using namespace std;

int function1(int m,int k)
{
	int sum=1; 
	for(int i=1;i<=k;i++)
	{
	 	sum=sum*m;
	}
	
	return sum;
 } 
int main()
{
	int a,b;
	cin>>a>>b;
	int ans;
	//��ε��ú����� 
	ans=function1(a,b);
	cout<<ans;
	return 0; 
 } 
