//p1055
//@GWPC
#include<iostream>

using namespace std;
int main() {
	char a[14];
	long long ans = 0;
	cin >> a;
	int b[10] = { a[0],a[2],a[3],a[4],a[6],a[7],a[8],a[9],a[10],a[12] };
	
	/*for (int j = 0; j < 10; j++)
	{
	switch (b[j])
		{
			case 48:
				b[j] = 0;
				break;
			case 49:
				b[j] = 1;
				break;
			case 50:
				b[j] = 2;
				break;
			case 51:
				b[j] = 3;
				break;
			case 52:
				b[j] = 4;
				break;
			case 53:
				b[j] = 5;
				break;
			case 54:
				b[j] = 6;
				break;
			case 55:
				b[j] = 7;
				break;
			case 56:
				b[j] = 8;
				break;
			case 57:
				b[j] = 9;
				break;
			case 88:
				b[j] = 10;
		}
	}*/
	
	for(int j=0;j<10;j++)
		b[j]-=48;
	
	if(b[9]==88)
	{
		b[9]=10;
	}
	else
	{
		b[9]-=48;
	}
	
	
	
	for (int i = 1; i < 10; i++)
	{
		ans += (b[i - 1] * i);
	}
	ans = ans % 11;
	if (ans == b[9])
	{
		cout << "Right";
	}
	else
	{
		for(int k=0;k<12;k++)
		cout << a[k];
		if (ans == 10) {
			cout << "X";
		}
		else
		{
			cout << ans;
		}
	}
	return 0;
}

