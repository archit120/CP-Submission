#include <bits/stdc++.h>

using namespace std;


int main()
{
	#define int long long
	int t = 0;
	
	int c[100001] ;
	for(int i =2;i<100001;i++)
	{
	c[i]=0;}
	
	for(int i =2;i<100001;i++)
	{
		
		if(!c[i])
		{
			for(int j = i*2;j<100001;j+=i)
			{
				c[j]++;
			}
			c[i] += 1;
		}
	}
/*	while(t--)
	{
		int ar[100001];
		int dp[100001];

		int n;
		cin >> n;
		for(int i =0;i<n;i++)
		{
			cin >> ar[i];
			dp[i]=0;
		}
		sort(ar,ar+n,greater<int>());
		int maxl = 0;
		for(int i =0;i<n;i++)
		{
			dp[i]= 1;
			for(int j =i-1;j>=0;j--)
			{
				if(!(ar[j] % ar[i]))
					dp[i] = max(dp[j] + 1, dp[i]);
				
			}
			maxl = max(dp[i]*c[i], maxl);
		}
		cout << maxl << "\n";
	}*/
}
