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
int ec[200000];
int v[200000];
vector<int> e[200000];


int main()
{
	#define int long long
	int n, m;
	cin >> n >> m;
	int mev = 0;
	int me = 0;
	for(int i =0;i<n;i++)
	{		v[i] = 0;
			ec[i] = 0;
			e[i].clear();
		}
	for(int i =0;i<m;i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		ec[a]++;
		ec[b]++;
		e[a].push_back(b);
		e[b].push_back(a);
		if(ec[a] > me)
			me = ec[a], mev = a;
		if(ec[b] > me)
			me = ec[b], mev = b;
	}
	queue<int> bfs;
	bfs.push(mev);
	while(!bfs.empty())
	{
		int t = bfs.front();
		bfs.pop();
		v[t] = 1;
		for(int i =0;i<e[t].size();i++)
		{
			if(v[e[t][i]])	continue;
			cout << t+1 << " " << e[t][i] +1<< "\n";
			bfs.push(e[t][i]);
			v[e[t][i]] = 1;
		}
	}
	
}
