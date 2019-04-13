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

int main()
{
	#define int long long
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, a, b, c, x, y;
    cin >> q;
    while(q--)
    {
    	cin >> n >> a >> b;
    	if(b-2*a<=0)
    	{
    		y = n/2;
    		x = n-2*y;
		}
		else
		{
			y=0;
			x=n;
		}
		if(y<0)x=n;
		c = y*b + x*a;
		cout << c << "\n";
	}
}
