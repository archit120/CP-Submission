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
	long a[1000][1000];

	long dpr[1000][1000];
	long dpc[1000][1000];
	long cr[1000];
	long r[1000];
	long c[1000];
int main()
{    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#define int long 
	int n, k;
	cin >> n >> k;
	for(int i =0;i<n;i++)
		for(int j =0;j<k;j++)
				cin >> a[i][j];
		
	map<int, int> mapp;
	int rank = 0;
	for(int i =0;i<n;i++)
	{
		mapp.clear();
		for(int j =0;j<k;j++)
			mapp[a[i][j]] = 0;
		rank = 0;
		for(auto it: mapp)
			mapp[it.first] = rank++;
	
		for(int j =0;j<k;j++)
		{
			dpr[i][j] = mapp[a[i][j]];
		}
		r[i] = rank;
	}
	for(int i =0;i<k;i++)
	{
		mapp.clear();
		for(int j =0;j<n;j++)
			mapp[a[j][i]] = 0;
		rank = 0;
		for(auto it: mapp)
			mapp[it.first] = rank++;
		
		for(int j =0;j<n;j++)
		{
			dpc[j][i] = mapp[a[j][i]];
		}
		c[i] = rank;
	}
	
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<k;j++)
		{
			int cl = c[j];
			int rl = r[i];
			int ri = dpr[i][j];
			int ci = dpc[i][j];
			if(ri == rl && ci == cl)
			{
				a[i][j] = max(ri,ci);
			}
			else if(ri < rl && ci == cl)
			{
				if(ci > ri)
					a[i][j] = (rl-ri) + ci;
				else
					a[i][j] = rl;
			}
			else if(ci < cl && ri == rl)
			{
				if(ri > ci)
					a[i][j] = (cl-ci) + ri;
				else
					a[i][j] = cl;
			}
			else
			{
				if(ci < ri)
					a[i][j] = max(rl, (ri-ci)+cl);
				else
					a[i][j] = max(cl, (ci-ri) + rl);
			}
		}
	}
	
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<k;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
