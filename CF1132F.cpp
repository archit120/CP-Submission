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

char s[501];
int dp[501][501];

int retc(int a, int b, int c)
{
	int su = dp[a][b] + dp[b+1][c] + 1;
	if(s[b]==s[c+1] || s[c] == s[c+1])
		return su-1;
	return su;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	for(int i =1;i<=n;i++)
		cin >> s[i];
	for(int i = 0;i<n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			if(j-i < 1)	continue;
			if(i==0)
				dp[j][j] = 1;
			else if(i==1)
				dp[j-1][j] = (s[j]==s[j-1]) ? 1 : 2;
			else
			{
				dp[j-i][j] = retc(j-i, j-2, j-1);
				for(int k = j-i;k<j;k++)
				{
					dp[j-i][j] = min(dp[j-i][j], retc(j-i, k, j-1));
				}
			}
		}
	}
	cout << dp[1][n];
}
