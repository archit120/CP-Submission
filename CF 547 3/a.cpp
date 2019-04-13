
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
    int64 a, b;
    cin >> a >> b;
    if(b<a || b%a)
    {
        cout << -1;
        return 0;
    } 

    int64 d = b/a;
    int c= 0;
    while( !(d%2) || !(d%3))
    {
        if(d%2) d=d/3;
        else d=d/2;
        c++;
    }
    if(d!=1)
    {
cout << -1;
        return 0;
    } 
    cout << c;
    return 0;
}