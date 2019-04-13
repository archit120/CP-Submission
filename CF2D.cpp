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
	    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	#define int long long
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	string ss = "";
	int lps[b.size()];
	lps[0] = 0;
	int len = 0;
	for(int i =1;i<b.size();i++)
	{
		if(b[i]==b[len])
			lps[i] = ++len;
		else
		{
			while(b[i] != b[len] && len !=0)
				len=lps[len-1];
			if(b[i]==b[len])
				lps[i] = ++len;
			else
				lps[i] = len;
		}
	}
	
	int cl = lps[b.size() - 1];
	int a1=0, b1 = 0, a0 =0 ,b0 = 0, c1=0,c0=0;
	for(int i =0;i<a.size();i++)
	{
		if(a[i]=='1')a1++;
		else	a0++;
	}
	for(int i =0;i<b.size();i++)
	{
		if(b[i]=='1')b1++;
		else	b0++;
	}
	ss = "";
	for(int i = cl;i<b.size();i++)
	{
		if(b[i]=='1')c1++;
		else	c0++;
		ss+=b[i];
	}
	int l = 0;
	if(a1 == 0 && b1 == 0) l = a0/b0;
	else if(a0 == 0 && b0 == 0) l = a1/b1;
	else if(b1!=0 && b0 != 0) l = min(a1/b1, a0/b0);
	l = min(1,l);
	string c;
	for(int i = 0;i<l;i++)
		c+=b;
	a0 -= b0*l;
	a1 -= b1*l;
	if(l==1)
	{
	
		l = 0;
		if(a1 == 0 && c1 == 0 && c0!=0) l = a0/c0;
		else if(a0 == 0 && c0 == 0 && c1!=0) l = a1/c1;
		else if(c1!=0 && c0 != 0) l = min(a1/c1, a0/c0);
		
		for(int i = 0;i<l;i++)
			c+=ss;
	}
	for(int i = 0;i<a1-c1*l;i++)
		c+="1";
	for(int i = 0;i<a0-c0*l;i++)
		c+="0";
	cout << c;
}
