#include <bits/stdc++.h>

using namespace std;

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
long long get_length(tuple<long long, long long> v)
{
	return get<1>(v) - get<0>(v);
}
int main()
{
	#define int long long
	int n, k;
	cin >> n >>k;
	int ps[n];
	for(int i =0;i<n;i++)
	{
		cin >> ps[i];
	}
	int dp[n][k+1];
	vector<tuple<int, int> >vals;
	sort(ps, ps+n);
	int si = 0;
	int ei = 0;
	while(++ei<n)
	{
		if(ps[ei]-ps[si]>5)
		{
			vals.push_back(make_tuple(si, ei));
			while(ps[ei] - ps[si] > 5)si++;
		}
	}
	vals.push_back(make_tuple(si, ei));
	int mc = 0;
	int maxk[k+1];
	for(int i =0;i<=k;i++)
		maxk[i]=0;
	for(int i =0;i<vals.size();i++)
	{
		dp[i][1] = get_length(vals[i]);		
		mc = max(mc, dp[i][1]);
		for(int l = 2;l<=k; l++)
		{
			dp[i][l] = 0;
			if(i==0)	continue;
			int t = i-1;
			while(t>=0 && i-t<=5)
			{
			
			//handle overlapping segments first, must be in previous 5 
				if(get<1>(vals[t]) <= get<0>(vals[i])) //entire
					dp[i][l] = max(dp[i][l], dp[t][l-1] +  get_length(vals[i]));
				else //break the previous tuple
					dp[i][l] = max(dp[i][l], dp[t][l-1] + (get<1>(vals[i]) - get<1>(vals[t])));
				t--;
			}
			if(i<6){mc = max(mc, dp[i][l]);
				continue;}
			maxk[l-1] = max(maxk[l-1], dp[i-6][l-1]);
			dp[i][l] = max(maxk[l-1]+get_length(vals[i]), dp[i][l]);
			mc = max(mc, dp[i][l]);

		}
	}
	
	cout << mc;
}
