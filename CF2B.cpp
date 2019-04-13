#include <bits/stdc++.h>

using namespace std;

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

long long cabs(long long a)
{
	if(a<0)return a*-1;
	return a;
}

int gcd(long long a, long long b) {
	//if(a==0 || b == 0) return 0;
	
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	#define int long long
	int n;
	cin >> n;
	int a[n];
	int b[n];
	string t;
	cin >> t;
	for(int i =0;i<n;i++)
	{
		
		if(t[i]=='0')
		a[i] = 0;
		else if(t[i]=='1')
		a[i] = 1;
	}
	
		cin >> t;
	for(int i =0;i<n;i++)
	{

		if(t[i]=='0')
		b[i] = 0;
		else if(t[i]=='1')
		b[i] = 1;	}
	
	
	int conly = 0;
	int aonly = 0;
	int ac = 0;
	int none = 0;
	for(int i =0;i<n;i++)
	{
		if(a[i] == b[i] && a[i]==0)
			none++;
		else if(a[i]==b[i] && a[i]==1)
			ac++;
		else if(a[i] == 1 && b[i] == 0)
			conly++;
		else
			aonly++;
	}
	int ac2 = 0;
	int a2 = 0;
	int ac1 = 0;
	int c1 = 0;
	int c2 = 0;
	int a1 = 0;
	int d = 0;
	int found = 0;
	for(int i =0;i<=aonly;i++)
	{
		for(int j =0;j<=ac;j++)
		{
			 ac2 = j;
			 a2 = i;
			 ac1 = ac-j;
			 c1 = a2+ac2-ac1;
			 c2 = conly-c1;
			 a1 = aonly-a2;
			 d = (c2-a1);
			// cout << ac2 << a2 << ac1 << c1 << c2 << a1 << d<< "\n";
			if(cabs(d)<=none && ac1 >= 0 && c1 >=0 && c2>=0 && a1 >=0)
			{
				//cout << none << cabs(d) << "\n";
				found = 1;
					break;
				}
		}
		if(found)
		break;
	}
	if(!found)
	{
		cout << -1;
		return 0;
	}
	int n1 = (d+none)/2;
	int n2 = none - n1;
	int i =0;
		//cout << a1 << ac1 << c1 << n1 << "\n";

	while(i<n)
	{
		if(ac1 > 0 && a[i] == 1 && b[i] == 1)
		{
				cout << i+1;
				ac1--;	if(ac1 + a1 + c1 + n1 != 0)
			cout << " ";
		}
		else if(a1 > 0 && a[i] == 0 && b[i] == 1)
		{
			cout << i+1;
			a1--;	if(ac1 + a1 + c1 + n1 != 0)
			cout << " ";
		}
		else if(c1 > 0 && a[i] == 1 && b[i] == 0)
		{
			cout << i+1;
			c1--;	if(ac1 + a1 + c1 + n1 != 0)
			cout << " ";
		}
		else if(n1 > 0 && a[i] == 0 && b[i] == 0)
		{
			cout << i+1;
			n1--;	if(ac1 + a1 + c1 + n1 != 0)
			cout << " ";
		}
	
		i++;
	}
}
