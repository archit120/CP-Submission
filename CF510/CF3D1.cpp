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
	    return b == 0 ? a : gcd(b, a % b);
}
int v[100];
int v2[101];
int dp[100][10000]
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int s =0;
	for(int i =0;i<n;i++)
	{
			cin >> v[i];
			v2[v[i]]++;
			s+=v[i];
	}
	int t = s- m;
	if(t<0){
		cout << -1;
		return 0;
	}
	for(int j = m;j>0;j--)
	{
		int ms = 0;
		for(int k = 1;k<=j;k++)
		{
			
		}
	}
}

