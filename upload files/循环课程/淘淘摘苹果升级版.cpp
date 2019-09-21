//@GWPC
//OJ:luogu
//p1478 
#include<iostream>
using namespace std;

int m[5001];//height
int mm[5001];//fonce


int main()
{
	

	int n, s, a, b;
	cin >> n >> s;
	
	cin >> a >> b;
	a += b;//only a can be used;taoytao`s final height
	for (int i = 0; i < n; i++)//输入
	{
		cin >> m[i] >> mm[i];
	}

	if (n == 0)//极品数据
	{
		cout << 0;
		return 0;
	}

	
	for (int j = 0; j < n; j++)//order the fonce s-b
	{
		for (int k = 0; k < n ; k++)
		{
			if (mm[j] < mm[k])
			{
				mm[j] -= mm[k];
				mm[k] += mm[j];
				mm[j] = mm[k] - mm[j];//交换力

				m[j] -= m[k];
				m[k] += m[j];
				m[j] = m[k] - m[j];//交换高
			}
		}
	}

	
	

	int ans = 0;

	for (int f = 0; f <= 5001;f++)
	{
		if (a < m[f])//高判断
		{
			continue;
		}

		s -= mm[f];//减力

		if (s >= 0)
		{
			ans++;
		}
		else
		{
			cout << ans;
			break;
		}

	}


	return 0;
}








/*题目描述
又是一年秋季时，陶陶家的苹果树结了n个果子。陶陶又跑去摘苹果，这次她有一个a公分的椅子。当他手够不着时，他会站到椅子上再试试。

这次与NOIp2005普及组第一题不同的是：陶陶之前搬凳子，力气只剩下s了。当然，每次摘苹果时都要用一定的力气。陶陶想知道在s<0之前最多能摘到多少个苹果。

现在已知n个苹果到达地上的高度xi，椅子的高度a，陶陶手伸直的最大长度b，陶陶所剩的力气s，陶陶摘一个苹果需要的力气yi，求陶陶最多能摘到多少个苹果。

输入输出格式
输入格式：
第1行：两个数 苹果数n，力气s。

第2行：两个数 椅子的高度a，陶陶手伸直的最大长度b。

第3行~第3+n-1行：每行两个数 苹果高度xi，摘这个苹果需要的力气yi。

输出格式：
只有一个整数，表示陶陶最多能摘到的苹果数。

输入输出样例
输入样例#1： 
8 15
20 130
120 3
150 2
110 7
180 1
50 8
200 0
140 3
120 2
输出样例#1： 
4
说明
所有数据：n<=5000 a<=50 b<=200 s<=1000

      xi<=280  yi<=100
*/
