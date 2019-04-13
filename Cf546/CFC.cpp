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
void transpose(int x, int y, int k)
{
		//cout << x << " " << y << " " << k << "\n";	

	if(y<0 || x<0 || x+k>501 || y+k>501)		return;
	//cout << x << " " << y << " " << k << "\n";	
	for(int i = x; i-x < k ; i++)
		for(int j=y;j-y<k;j++)
			c[j-y][i-x] = a[i][j];
	for(int i = x; i-x < k ; i++)
		for(int j=y;j-y<k;j++)
			a[i][j] = c[i-x][j-y];
}
int main()
{
	#define int long
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    	for(int j =0;j<m;j++)
    		cin >> a[i][j];
    for(int i = 0;i<n;i++)
    	for(int j =0;j<m;j++)
    		cin >> b[i][j];
    if(a[0][0]!= b[0][0] || a[n-1][n-1] != b[n-1][n-1])
    {
    	cout << "NO";
    	return 0;
	}
    for(int i =0;i<n;i++)
    {
    	int wc = 0;
    	int y,x=i;
    	for(int j =0;j<m;j++)
    	{
    		if(a[i][j] != b[i][j])
    		{
    			 y=j-1;
    			 wc=2;
    			while(y+wc < n && x+wc<n && a[x][y+wc] == b[x+wc][y] && b[x][y+wc] == a[x+wc][y])
    				wc++;
    			
    			transpose(x,y,wc);
    			//j++;
    			wc = 0;
    			
			}
			
		}
			
	}
	
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<m;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				cout << "NO";
				return 0;
			}
			
		//	cout << a[i][j] << " " << b[i][j] << " ";
		}
		//cout << "\n";
	}
	
	cout << "YES";
	return 0;
}
