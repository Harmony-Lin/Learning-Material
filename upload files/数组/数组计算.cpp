#include<iostream>

using namespace std;

int main()
{
	int a[1000];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];//���� 
	}
	
	double ans1;//Why Double?
	for(int i=0;i<n;i++)
	{
		ans1+=a[i];//ȫ�������� 
	}
	ans1/=n;//���� 
	cout<<"ƽ����"<<ans1<<endl; 
	

	float b[1000];//�¶���һ�����飬���ᶪʧԭ�������� 
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
	}//���������������֮һ����ð�����򣨴Ӵ�С�� 
	//�������� b �������� a �����Ӵ�С����İ汾�ˡ� 
	
	/*for(int i=0;i<n;i++)
	{
		cout<<b[i]<<endl;
	}*///��Щ�����������鿴�����״̬�ģ��ڵ��Ե�ʱ������õõ�������ֱ�ӿ���ע�͵��Ϳ����ˡ�
	
	if(n%2==0)
	{
		cout<<"��λ��:"<<(b[n/2]+b[n/2-1])/2<<endl; 
	}
	else
	{
		cout<<"��λ��:"<<b[(n+1)/2-1]<<endl; 
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
			if(temp>max)//����ǰ���Ļ�Ҫ�� 
			{
				c=1;//�𰸸�����1
				ans2[0]=b[i];//���Լ�д��� 
				max=temp;//������󳤶� 	
			}
			else if(temp==max)
		 	{
		 		ans2[c]=b[i];
		 		c++;
			} 
		}
		
	}
	
	cout<<"������";
	for(int i=0;i<c;i++)
	{
		cout<<ans2[i]<<" ";
	}
	
	return 0;
}

