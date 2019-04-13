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

long p[300000];
vector<long> a[300000];
vector<long> b[300000];
int main()
{
	#define int long
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for(int i = 0;i<n;i++)
    {
		cin >> p[i];
		mp[p[i]] = i;
		p[i] = i;
	}
    for(int j =1;j<=m;j++)
    {
    	int u,v;
    	cin >> u >> v;
    	u = mp[u];
    	v = mp[v];
    	b[u].push_back(v);
    	a[v].push_back(u);
    	
    //	cout << u << " " << v << "\n";
	}
    sort(a[n-1].begin(), a[n-1].end());
    int c = a[n-1].size(); // max possible
   /* for(int i  = a[n-1].size() - 1; i>=0;i--)
	{
		if(n-1-a[n-1][i]!=c+1)
		{
			cout << a[n-1][i] <<" "<<i<<" " << c <<"\n";
				break;
		}
		c++;
	}*/
	//cout << c << "\n";
	int t = 0;
	//set<int> missing;
	for(int i = 0;i<c;i++)
	{
		int lc=0;
		int id = a[n-1][a[n-1].size() - 1 -i ];
		sort(b[id].begin(), b[id].end());
		for(int j = b[id].size()-1;j>=0;j--)
		{
			//cout << b[id][j] <<" "<<j << " " <<id<<" " << c << " " << i << "\n";
			if( b[id][j] <= id)
				break;
			lc++;
		}
		//cout << id << " " << lc << " " << n-1-id-t <<"\n";
		if(lc>=n-1-id-t)
		{
			t++;
			//cout << id <<"\n";
			missing.insert(id);
		}
		
	}
	cout << t;
	return 0;
} 
