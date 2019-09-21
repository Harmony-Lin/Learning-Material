//@GWPC
//P1553 
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s;//要进行操作的字符 
    char p=0;//储存符号的char 
    int cnt=0; //记录第一个数长度
    cin>>s;//string类型和char类型的数组都允许直接cin或cout。 
    for(int i=0;i<s.size();i++)//.size()是string类中的一个成员函数，用于返回string的长度。 
    {
        if(s[i]>='0'&&s[i]<='9')
		{
		cnt++;//记录第一个数长度
		} 
        else    //遇到符号，记录，跳出 
        {
            p=s[i];//将符号赋值给p。 
            break;
        } 
    }
    
    int x=cnt;//记下第一个数末后一个的位置，也就是符号的位置，如果是分数或小数就要用
	
    cnt--;//不管最后一个是什么数，永远保留 
    
    while(s[cnt]=='0'&&cnt>0) 
		cnt--;//去除多余前导0；
	 
    for(int i=cnt;i>=0;i--)//输出第一个数 
       cout<<s[i];
       
    if(p==0)
	{
    	return 0;//无符号return 0 
	} 	
    else if(p=='%')
	{
	  	cout<<p;//如果是百分数就在末尾输出百分号 
	 	return 0;
	} 
    else
	{
    	cout<<p;//其他的输出原来的符号后继续 
	} 
	  
    int m=s.size()-1;
    
    while(s[x+1]=='0'&&x<m-1)
	{
		x++;//去除末尾0
	}
	
    while(s[m]=='0'&&m>x+1)
	{
		m--; //去除多余前导0
	}
	for(int i=m;i>x;i--)
	{//输出第二个数 
        cout<<s[i];
    }
    
    return 0; 
}
