
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
int64 cs[1001][3];

#define max(a,b) (a) > (b) ? (a) : (b)
bool check(int64 t, int64 r, int64 b, int64 c)
{
    vector<int64> ca;
    for(int64 i =0;i<c;i++)
        ca.push_back(max(0, min(cs[i][0], (int64)((t-cs[i][2])/cs[i][1]))));
    sort(ca.rbegin(), ca.rend());
    int64 handle = 0;
    for(int64 i=0;i<r;i++)
    {    handle+=ca[i];
    //cout << ca[i] << "\n";
    }
    if(handle<b)    return 0;
    return 1;
}
#undef int

int main()
{
    IOS
    int64 t, t2;
    cin >> t;
    t2=t;

    while(t--)
    {
        int64 r,b,c;
        cin >> r >> b >> c; 
        for(int64 i =0;i<c;i++)
        {
            int64 m,s,p;
            cin >> m >> s >> p;
            cs[i][0] = m;
            cs[i][1] = s;
            cs[i][2] = p;
        }
        int64 tmax = -1;
        int64 tmin = 1;
        while(!check(tmin, r, b, c) && tmin)
        {    tmin = tmin*2;
           // cout << tmin << "\n";
        }
        tmax = tmin;
        tmin = tmin/2;
        while(tmax-tmin>1)
        {
           // cout << tmax << " " << tmin << "\n";
            int64 mid = (tmax+tmin)/2;
            if(check(mid, r, b, c))
                tmax = mid;
            else
                tmin = mid;
            
        }
        if(tmax != tmin)
        {
            if(check(tmin, r, b, c)) tmax = tmin;
            else tmin = tmax;
        }
        cout << "Case #" << (t2 - t) << ": "<<tmin<<"\n";
    }
    
}