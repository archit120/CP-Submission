#include <bits/stdc++.h>

using namespace std;

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

int main()
{
	#define int long long
	int n;
	cin >> n;
	int ps[n];
	for(int i =0;i<n;i++)
	{
		cin >> ps[i];
	}
	sort(ps, ps+n);
	int mc = 0;
	int lc = 1;
	int si = 0;
	int ei = 0;
	while(++ei<n)
	{
		if(ps[ei]-ps[si]>5)
		{
			mc = max(mc,lc);
			while(ps[ei] - ps[si] > 5)si++;
			lc = ei - si;
		}
		lc++;
	}
	mc = max(mc,lc);
	cout << mc;
}
