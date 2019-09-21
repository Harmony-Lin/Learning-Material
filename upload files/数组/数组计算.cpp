#include<iostream>

using namespace std;

int main()
{
	int a[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];//输入 
	}
	
	double ans1;//Why Double?
	for(int i=0;i<n;i++)
	{
		ans1+=a[i];//全部加起来 
	}
	ans1/=n;//除法 
	cout<<"平均数"<<ans1<<endl; 
	

	float b[1000];//新定义一个数组，不会丢失原来的数据 
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(b[i]>=b[j])
			{
				b[j]-=b[i];
				b[i]+=b[j];
				b[j]=b[i]-b[j];
			}
		}
	}//进行最基本的排序之一——冒泡排序（从大到小） 
	//于是数组 b 就是数组 a 经过从大到小排序的版本了。 
	
	/*for(int i=0;i<n;i++)
	{
		cout<<b[i]<<endl;
	}*///这些代码是用来查看数组的状态的，在调试的时候可能用得到，所以直接跨行注释掉就可以了。
	
	if(n%2==0)
	{
		cout<<"中位数:"<<(b[n/2]+b[n/2-1])/2<<endl; 
	}
	else
	{
		cout<<"中位数:"<<b[(n+1)/2-1]<<endl; 
	}
	
	
	
	int ans2[MAX];
	int temp=0;
	int max=0;
	int c=0;
	for(int i=1;i<n;i++)
	{
		if(b[i]==b[i-1])
		{
			temp++;
		}
		else
		{
			temp=0;
			if(temp>max)//比以前最多的还要多 
			{
				c=1;//答案个数归1
				ans2[0]=b[i];//将自己写入答案 
				max=temp;//更改最大长度 	
			}
			else if(temp==max)
		 	{
		 		ans2[c]=b[i];
		 		c++;
			} 
		}
		
	}
	
	cout<<"众数：";
	for(int i=0;i<c;i++)
	{
		cout<<ans2[i]<<" ";
	}
	
	return 0;
}

