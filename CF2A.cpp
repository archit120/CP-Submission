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
	for(int i =0;i<n;i++)
	{
		cin >> a[i];
	}
	int mc=0;
	vector<int> vals;
	int lc = 1;
	int t = a[0];
	for(int i =1;i<n;i++)
	{
		if(a[i] == t)
			lc++;
		else
		{
			vals.push_back(lc);
			t = a[i];
			lc = 1;
		}
	}
	vals.push_back(lc);

	for(int i =0;i<vals.size()-1;i++)
	{
		mc = max(mc,min(vals[i],vals[i+1]));
	}
	cout << mc*2;
}
