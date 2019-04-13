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

int cs[200001];
int dp[200001][3];
int out[200001];
int main()
{

#ifndef DEBUG
IOS
#endif
int n;
cin >> n;
for(int i =0;i<n;i++)
	{
		char c;
		cin >> c;
		switch(c)
		{case 'R':cs[i]=0;break;
		case 'G': cs[i] = 1;break;
		case 'B':cs[i] =2;break;
		}
	}
	if(n==1)
	{
		cout << 0 << "\n";

		switch(cs[0])
		{
			case 0:	cout << 'R'; break;
			case 1:	cout << 'G'; break;
			case 2:	cout << 'B'; break;
		}
		return 0;
	}
	
	for(int i =0;i<n;i++)
	{
		if(i==0)
			dp[i][0] = dp[i][1] = dp[i][2] = 1;
		else
		{
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + 1;
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + 1;
			dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + 1;		
		}
		dp[i][cs[i]]--;
	}
	
	#ifdef DEBUG
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<3;j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
	#endif
	int c0 = min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
	cout << c0 << "\n";
	for(int i =n-1;i>=0;i--)
	{
		for(int j=0;j<3;j++)
		{
			if(dp[i][j] == c0)
			{
				if(i < n-1 && j==out[i+1])continue;
				if(j!=cs[i])	c0--;
				out[i] = j;
				break;
			}
		}
	}
	for(int i =0;i<n;i++)
	{
		switch(out[i])
		{
			case 0:	cout << 'R'; break;
			case 1:	cout << 'G'; break;
			case 2:	cout << 'B'; break;
		}
	}	
}

