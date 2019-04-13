#include <bits/stdc++.h>

using namespace std;

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

long long cabs(long long a)
{
	if(a<0)return a*-1;
	return a;
}

long long  gcd(long long a, long long b) {
	    return b == 0 ? a : gcd(b, a % b);
}

long a[501][501];
long b[501][501];
long c[501][501];
int main()
{
	#define int long
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    	for(int j =0;j<m;j++)
    		cicn >>ap[i[j];;
    for(int i = 0;i<n;i++)
    	for(int j =0;j<m;j++)
    		cin >> b[i][j];
    vector<int> d[n+m-1];
    vector<int> e[n+m-1];
    for(int s = 0;s<n+m-1;s++)
    {
		for(int i = 0;i<n;i++)
	    {
	    	int j = s - i;
	    	if(j<0 || j>= m)	continue;
	    	//cout << i << " " << j <<"\n";
	    	d[s].push_back(a[i][j]);
	    	e[s].push_back(b[i][j]);
		}
		//cout << s << "\n";
	}
	
	for(int s=0;s<n+m-1;s++)
	{
		sort(d[s].begin(), d[s].end());
		sort(e[s].begin(), e[s].end());
		for(int i =0;i<d[s].size();i++)
		{
			if(d[s][i]!=e[s][i])
			{
				cout << "NO";
				return 0;
			}
		}
	}
		cout << "YES";
				return 0;
}
