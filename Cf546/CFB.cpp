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

int main()
{
	#define int long long
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    //k--;
    if(k>n/2 && n!=2) k = n-k+1;
    else if(n==2 && k==2) k = 1;
    k--;
    int m = (2*k) + (n-1-k); //movement;
    //cout << m;
    m+=n+1;
    m+=n;
    cout << m;
}
