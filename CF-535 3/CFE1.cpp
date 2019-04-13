#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define endl '\n'
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;

long long  gcd(long long a, long long b) {
	    return b == 0 ? a : gcd(b, a % b);
}
typedef long long int ll;

long vals[301];
long valsb[301];
tuple<long, long, long> out[301];

long delta(long n)
{
	long ma = valsb[0];
	long mi = valsb[0];
	for(int i =0;i<n;i++)
	{
		ma = max(ma, valsb[i]);
		mi = min(mi, valsb[i]);
	}
	return ma-mi;
}
int main()
{
	
	#ifndef DEBUG
	IOS
	#endif
	#define int long
	int n, m;
	cin >> n >> m;
	for(int i =0;i<n;i++)
		cin >> vals[i];
	for(int i =0;i<m;i++)
	{
		int c,d;
		cin >> c >> d;
		c--;d--;
		out[i] = make_tuple(c,d, i);
	}
	if(n==1)
	{
		cout << 0 << "\n" << 0;
		return 0;
	}	for(int j =0;j<n;j++)
			valsb[j] = vals[j];
	int maxd = delta(n);
	sort(out, out+m);
	int si =0;
	int ei = 0;
	int dold = -2*1000000 + 1;
	int num = 0;
	int sme = 0;
	for(int si = 0;si<m;si++)	
	{
		for(int ei = si;ei<m;ei++)
		{
		
			for(int j =0;j<n;j++)
				valsb[j] = vals[j];
			for(int j =si;j<=ei;j++)
			{
				for(int k = get<0>(out[j]); k <= get<1>(out[j]);k++)
					valsb[k]--;
			}
			int dold = delta(n);
			maxd = max(dold, maxd);
			if(maxd==dold)
			{
				num = (ei-si+1);
				sme = si;
			}		
		}	
	}
	
	cout << maxd << "\n" << num << "\n";
	for(int i = sme; i<num+sme;i++)
	{
		cout << get<2>(out[i]) + 1 << " ";
	}
}
