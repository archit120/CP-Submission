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
	for(int i =0;i<n;i++)
	{
		cin >> a[i];
	}
		for(int i =0;i<n;i++)
	{
		cin >> b[i];
	}
	map<tuple<int,int>, int> vals;
	int sc = 0;
	for(int i =0;i<n;i++)
	{	

		int g= gcd(cabs(a[i]),cabs(b[i]));

		if(g==0) g=1;
		int ai = a[i]/g;
		int bi = b[i]/g;
		//cout << ai << bi ;
		if(bi < 0)
		{
			bi*=-1;
			ai*=-1;
		}
		if(ai == 0 && bi == 0)
			sc++;
		if(bi == 0)
			ai = 0;
		auto k = make_tuple(ai,bi);
		if(!vals.count(k))
			vals.insert(pair<tuple<int,int>, int>(k, 0));
		if(ai != 0 || (ai ==0 && bi ==0))
			vals[k]++;
		
	}
	auto s = make_tuple(0,0);
	int mc = 0;
	for (auto it = vals.begin(); it != vals.end(); it++ )
	{
		if(it->first!=s)
			mc = max(mc, it->second+sc);
		else
			mc = max(mc, it->second);
	}

	cout << mc;
}
