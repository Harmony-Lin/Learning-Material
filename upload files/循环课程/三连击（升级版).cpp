//@GWPC
//OJ:luogu
//P1618

/*
#include<iostream>

using namespace std;

int main()
{
	int a, b, c;
	
	bool flag = 0;
	cin >> a >> b >> c;//a:b:c     a<b<c
	int a1 = a;
	for (int a1 = a; a1 <= 999; a1+=a)//big cycle
	{
		int x = a1;
		int y = a1 / a * b;
		int z = a1 / a * c;//count x y z 

		if (x <= 999 && y <= 999 && z <= 999)
		{
			int bit[10];

			bit[1] = x / 100; //100
			bit[2] = x / 10 % 10;//10
			bit[3] = x % 10;//1

			bit[4] = y / 100;
			bit[5] = y / 10 % 10;
			bit[6] = y % 10;

			bit[7] = z / 100;
			bit[8] = z / 10 % 10;
			bit[9] = z % 10;//分离出每个三位数的各位


			int sum = 0;
			int sum1 = 1;

			for (int j=1;j<10;j++)
			{
				sum += bit[j];
				sum1 *= bit[j];
			}

			if (sum == 45 && sum1 == 362880)//成立了
			{
				flag = 1;
				cout << x << " " << y << " " << z << endl;
			}

		}


	}
	if (!flag)
	{
		cout << "No!!!";
	}

	return 0;
}
*/

#include<iostream> 
#include<cstring>
using namespace std;
int i,j,v;
bool a[10];//a[i]表示第i个数已经用过了
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
    for(i=192;i<=327;i++)//第一个数最小192，最大327。其实不知道的情况下简单来说是从123-329的但是算出来是最值就稍微改了下下
    {
        //memset(a,false,sizeof(a));//清空数组 
        for(int k=0;k<10;k++)
        	a[k]=0;
		v=0;//清零
        a[i*a%10]=a[i*a/10%10]=a[i*a/100]=a[i*b%10]=a[i*b/10%10]=a[i*b/100]=a[i*c%10]=a[i*c/10%10]=a[i*c/100]=1;//相当于把i给拆分成了个位、十位、百位，又分别乘1、2、3，得到九个数。 
        for(j=1;j<=9;j++) 
			v+=a[j];//v表示1-9这些数字是否全部齐了
			
        if(v==9) 
			cout<<i*a<<" "<<i*b<<" "<<i*c<<endl;//如果齐了就输出
    }
	return 0;
}
/*
题目描述
将1，2,3,4,5,6,7,8,9共9个数分成三组，分别组成三个三位数，且使这三个三位数的比例是A:B:C，试求出所有满足条件的三个三位数，若无解，输出“No!!!”。


输入输出格式
输入格式：
三个数，A B C。

输出格式：
若干行，每行3个数字。按照每行第一个数字升序排列。

输入输出样例
输入样例#1： 
1 2 3
输出样例#1： 
192 384 576
219 438 657
273 546 819
327 654 981
说明
保证A<B<C
*/
