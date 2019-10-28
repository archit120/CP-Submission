
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
    string s;
    cin >> s;
    #define int long long
    int ct1 = 1;
    for(int i = 1;i<s.size();i++)
        if(s[i]=='1')ct1++;
    int ct = s.size() / 2 + (s.size()%2 == 1 && ct1!=1? 1 : 0);
    cout << ct;
}