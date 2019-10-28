
#include<bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<int, int> PII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    IOS
    #define int long long
    int n, l, r;
    cin >> n >> l >> r;
    int on = 1;
    int maxsum =  (on << (r)) - 1 + ((on << (r-1)))*(n-r);
    int minsum =  1*(n-l) + (on << l) -1;
    cout << minsum << " " << maxsum;
    
}