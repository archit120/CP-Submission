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

    int a[200000];
    int s[200000];
    
    int s0[200001];
    int s1[200001];
int main()
{
	#define int long long
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    int c =0;
    for(int i =0;i<n;i++)
    {
		cin >>a[i];
		if(i&1)
		{
			s1[i] = a[i];
			s0[i] = s0[i-1];
			if(i>1)
				s1[i]+=s1[i-2];
		}
		else{
			s0[i]=a[i];
			if(i>0)
			{
					s0[i]+=s0[i-2];
					s1[i] = s1[i-1];
			}
		}
		s[i] = a[i];
		if(i>0)
			s[i]+=s[i-1];
	}
	int a1,a0;
	n=n-1;
	for(int i =0;i<=n;i++)
	{
		
		if(i>0)
		{
			a1 = s1[i-1] + s0[n] - s0[i];
			a0 = s0[i-1] + s1[n] - s1[i];
		}
		else 
		{
			a1 = s0[n] - s0[0];
			a0 = s1[n];
		}
		if(a1==a0)	c++;
		//cout << a0 << " " << a1 << "\n";
	}
	cout << c;
}
