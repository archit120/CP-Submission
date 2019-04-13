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

ll diva[10001];
int main()
{

#ifndef DEBUG
IOS
#endif
int n;
cin >> n;
int i =0;
	forn(0,n,i)
	{
		cin >> diva[i];
	}
	sort(diva, diva+n);
	ll y= diva[n-1];
	
	forn(0,n,i)
		if(y%diva[i]==0)
		{
			if(diva[i] == diva[i+1])	i++;
			diva[i] = 0;
		}
	sort(diva, diva+n);
	ll x =  diva[n-1];
	
	cout << x << " " << y;
}
