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
int v[200000];
vector<int> e[200000];

void dfs_1(int t, int c) //reachability
{
	if(v[t])	return;
	v[t] = c;
	for(int i =0;i<e[t].size();i++)
		dfs_1(e[t][i], c);
}
void dfs_2(int t, int c)
{
	if(v[t])	return;
	v[t] = 1;
	cout << t+1 << " " << c+1 << "\n";
	for(int i =0;i<e[t].size();i++)
		dfs_2(e[t][i], t);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m, d;
	cin >> n >> m >> d;
	for(int i =0;i<n;i++)
	{		v[i] = 0;
			e[i].clear();
		}
	for(int i =0;i<m;i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	v[0] = 1;
	
	map<int, vector<int> > minr;
	for(int i =0;i<e[0].size();i++)
	{
		dfs_1(e[0][i], e[0][i]);
		
		minr[v[e[0][i]]].push_back(e[0][i]);
	}
	if(minr.size() > d || e[0].size() < d){
		cout << "NO";
		return 0;
	}
	for(int i =0;i<n;i++)
	{		v[i] = 0;	}
	cout << "YES\n";
	//cout << minr.size() << "\n";
	int extra  = d - minr.size();
	vector<int> newe;
	for(auto it:minr)
	{
		int t= it.second.size();
		//cout << t << " " <<extra << "\n";
		while(--t && extra)
		{
			newe.push_back(it.second[t]);
			extra--;
		}
		newe.push_back(it.second[0]);
	}
	e[0] = newe;
	queue<int> bfs;
	bfs.push(0);
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
