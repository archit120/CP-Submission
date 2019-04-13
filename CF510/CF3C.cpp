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
int mat[21][21];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, v;
    cin >> n;
    map<int, int> mp;
    for(int i =0;i<n*n;i++)
    {
		cin >> v;
		if(mp.find(v) == mp.end())
			mp[v]=0;
		mp[v]++;
	}
	int of = 0;
	int c2 = 0;
	int c4  =0;
	for(auto it : mp)
	{
		int t = it.second;
		if(t % 4)
		{
			if(n&1 && !of && t%2 == 1)
			{
				of = it.first;
				t--;
			}
			
			else if(n&1 && t%4!=2 || !(n&1))
			{
				cout << "NO";
				return 0;
			}
		}
		
		c4+=t/4;
		c2+=(t%4)/2;
	}
	if(n&1 && !of || c2&1)
	{
		cout << "NO";
		return 0;
	}
	if(n&1)
	{
		int b4 = ((n-1) - c2)/2;
		//c4= n-1;
		c2 = n-1;
		c4 = (n/2)*(n/2);
		mat[(n-1)/2][(n-1)/2] = of;
		queue<int> tc4;
		queue<int> tc2;
		//cout << c4 << " " << c2 << "\n";
		//first fill in those which are c4
		for(auto it : mp)
		{
			int t= it.second;
			if(it.first==of)t--;
			//cout << t << "\n";
			while(t%2==0 && c4 && t>=4)
			{
				//cout << it.first << " c4  " << c4 << "\n";
				tc4.push(it.first);
				t-=4;
				c4--;
			}
			while(t%2 == 0 && c2 && t>=2)
			{
						//		cout << it.first << " c4  " << c2 << "\n";

				tc2.push(it.first);
				t-=2;
				c2--;
			}
		}
		if(c4!=0 || c2!=0)
		{
				cout << "NO";
				return 0;
		}
		for(int x = 0;x<n/2;x++)
		{
			for(int y = 0;y<n/2;y++)
			{
				mat[x][y] = tc4.front();
				mat[n-1-x][n-1-y] = tc4.front();
				mat[n-1-x][y] = tc4.front();
				mat[x][n-y-1] = tc4.front();
				tc4.pop();
			}
		}
		for(int x = 0;x<n/2;x++)
		{
			mat[x][n/2] = tc2.front();
			mat[n-1-x][n/2] = tc2.front();
			tc2.pop();
			mat[n/2][x] = tc2.front();
			mat[n/2][n-1-x] = tc2.front();
			tc2.pop();
		}
	}
	else
	{
		c4 = n*n/4;
		queue<int> tc4;
		for(auto it : mp)
		{
			int t= it.second;
			while(t%2==0 && c4 && t>=4)
			{
				tc4.push(it.first);
				t-=4;
				c4--;
				//cout << it.first << " " << c4 << "\n";
			}
		}
		if(c4!=0)
		{
				cout << "NO";
				return 0;
		}
		for(int x = 0;x<n/2;x++)
		{
			for(int y = 0;y<n/2;y++)
			{
				mat[x][y] = tc4.front();
				mat[n-1-x][n-1-y] = tc4.front();
				mat[n-1-x][y] = tc4.front();
				mat[x][n-y-1] = tc4.front();
				tc4.pop();
			}
		}
	}
	cout<<"YES\n";
	for(int i =0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}
