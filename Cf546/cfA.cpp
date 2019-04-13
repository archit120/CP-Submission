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

int v[101];
int ve[101];
int main()
{
	#define int long long
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    int c = 0;
    for(int i =0;i<n;i++)
    {
		cin >> v[i] >> ve[i];
	}
    cin >> k;
    for(int i =0;i<n;i++)
    {
    	if(ve[i] >= k || v[i] >= k)
    		c++;
	}
	cout << c;
}
