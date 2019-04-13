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
int main()
{

#ifndef DEBUG
IOS
#endif
int q;
cin >> q;
while(q--)
{
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	if(l2 != l1)
		cout << l1 << " " << l2 << "\n";
	else 
		cout << l1 << " " << l2+1 << "\n";
}
}
