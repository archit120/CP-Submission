
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
    int n;
    cin >> n;
    int32 q[2*100000 + 1];
    int32 p[2*100000 + 1];
    int32 m = n+1;
    for(int i =0;i<n-1;i++)
    {
        cin >> q[i];
        m = min(m, q[i]);
    }
    p[0] = 0;
    vector<int> p2;
    p2.push_back(0);
    for(int i =0;i<n-1;i++)
    {
        p[i+1] = q[i] + p[i];
        p2.push_back(p[i+1]);
    }
    sort(p2.begin(), p2.end());
    int d = n - p2[n-1];
    for(int i =1;i<=n;i++)
    {

        if(p2[i-1] + d != i)
        {
           cout<<-1;
            return 0;
        }
    }
    for(int i =0;i<n;i++)
    {
        cout << p[i] + d << " ";
    }
}