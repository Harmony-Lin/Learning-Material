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
			bit[9] = z % 10;//�����ÿ����λ���ĸ�λ


			int sum = 0;
			int sum1 = 1;

			for (int j=1;j<10;j++)
			{
				sum += bit[j];
				sum1 *= bit[j];
			}

			if (sum == 45 && sum1 == 362880)//������
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
bool a[10];//a[i]��ʾ��i�����Ѿ��ù���
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
    for(i=192;i<=327;i++)//��һ������С192�����327����ʵ��֪��������¼���˵�Ǵ�123-329�ĵ������������ֵ����΢��������
    {
        //memset(a,false,sizeof(a));//������� 
        for(int k=0;k<10;k++)
        	a[k]=0;
		v=0;//����
        a[i*a%10]=a[i*a/10%10]=a[i*a/100]=a[i*b%10]=a[i*b/10%10]=a[i*b/100]=a[i*c%10]=a[i*c/10%10]=a[i*c/100]=1;//�൱�ڰ�i����ֳ��˸�λ��ʮλ����λ���ֱַ��1��2��3���õ��Ÿ����� 
        for(j=1;j<=9;j++) 
			v+=a[j];//v��ʾ1-9��Щ�����Ƿ�ȫ������
			
        if(v==9) 
			cout<<i*a<<" "<<i*b<<" "<<i*c<<endl;//������˾����
    }
	return 0;
}
/*
��Ŀ����
��1��2,3,4,5,6,7,8,9��9�����ֳ����飬�ֱ����������λ������ʹ��������λ���ı�����A:B:C���������������������������λ�������޽⣬�����No!!!����


���������ʽ
�����ʽ��
��������A B C��

�����ʽ��
�����У�ÿ��3�����֡�����ÿ�е�һ�������������С�

�����������
��������#1�� 
1 2 3
�������#1�� 
192 384 576
219 438 657
273 546 819
327 654 981
˵��
��֤A<B<C
*/
