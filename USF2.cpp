#include <bits/stdc++.h>

using namespace std;


int main()
{
	#define int long long
	int t = 0;
	
	int c[100001],d[100001] ;
	for(int i =2;i<100001;i++)
	{
	c[i]=0;d[i]=1;
	}
	
	for(int i =2;i<100001;i++)
	{
		
		if(!c[i])
		{
			for(int j = i*2;j<100001;j+=i)
			{
				c[j]++;
				d[j] = d[j]*i;
			}
			c[i] += 1;
			d[i] *= c[i];
		}
	}
	d[1] = 0;
	cin >> t;
	while(t--)
	{

		int n;
		cin >> n;
		
		int* ar = new int[n];
		int* dp = new int[n];
		for(int i =0;i<n;i++)
		{
			cin >> ar[i];
			ar[i] = d[ar[i]];
			dp[i]=0;
		}
		sort(ar,ar+n,greater<int>());
		int maxl = 0;
		for(int i =0;i<n;i++)
		{	if(ar[i]!=0)
			{
				dp[i]= 1;
				for(int j =i-1;j>=0;j--)
				{				
					if(!(ar[j] % ar[i]))
						dp[i]++;
					
				}
			}
			else
				dp[i] = 0;
			//cout << ar[i] << " " << dp[i] << " " << c[ar[i]]<<"\n";
			maxl = max(dp[i]*c[ar[i]], maxl);
		}
		cout << maxl << "\n";
		delete ar; delete dp;
	}	
}
