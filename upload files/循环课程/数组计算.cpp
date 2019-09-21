#include<iostream>

using namespace std;

int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	double ans1;
	for(int i=0;i<n;i++)
	{
		ans1+=a[i];
	}
	ans1/=n;
	cout<<"Æ½¾ùÊý"<<ans1<<endl; 
	
	int ans2;
	int b[100];
	for(int i=0;i<n;i++)
	{
		b[i]=a[i];
		
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;i++)
		{
			if(b[i]>=b[j])
			{
				b[j]-=b[i];
				b[i]+=b[j];
				b[j]=b[i]-b[j];
			}
		}
	}
	
	
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<endl;
	}
}
	/*
	if(n%2==0)
	{
		cout<<(b[n/2]+b[n/2+1])/2<<endl;
	}
	else
	{
		cout<<b[(n+1)/2]<<endl;
	}
	

}
	
	*/

	/*
		#include<iostream>
#include<cstdio>
int a[100001],ll[200001],rr[200001],n,b,num,ans;
inline int readint()
{
    int i=0,f=1;
    char ch;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
    for(;ch>='0' && ch<='9';ch=getchar())
        i=(i<<3)+(i<<1)+ch-'0';
    return i*f;
}
int main()
{
	register int i,j;
	n=readint();
	b=readint();
	for(i=1;i<=n;++i)
	{
		a[i]=readint();
		if(a[i]==b)
		{
			num=i;
			a[i]=0;
		}
		else if(a[i]>b) a[i]=1;
		else a[i]=-1;
	}
	auto int l,r;
	l=r=n;
	for(i=num;i>0;--i)
	{
		l+=a[i];
		++ll[l];
	}
	for(i=num;i<=n;++i)
	{
		r+=a[i];
		++rr[r];
	}
	int len=2*n;
	for(i=0;i<=len;++i) 
		ans+=(ll[i]*rr[len-i]);
	printf("%d\n",ans);
	return 0;
	
 } 
 
 
 
 */
 
