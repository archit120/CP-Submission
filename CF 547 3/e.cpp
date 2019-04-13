
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
    int64 H;
    int64 n;
    cin >> H >> n;
    int64 hp[2*100000 + 1];
    int64 ts = 0;
    int64 m3 = INT64_MIN;
    for(int i =0;i<n;i++)
    {    cin >> hp[i];
        ts-=hp[i];
        m3 = max(ts, m3);
        if(ts>=H)
        {
            cout << i+1;
            return 0;
        }
    }
    if(ts<=0)  {
        cout << -1;
        return 0;
    }
   // cout << H << " " << m3 << " " << ts <<"\n";
    int64 out = (H-m3)/ts;
    if((H-m3) % ts) out++;
    H=H - ts*out;
    out*=n;
   // cout << out << " " << H << "\n";
    int64 s1 = 0;
    if(out==0)
    {
        cout << out; return 0;
    }
    for(int i =0;i<n;i++)
    {
        s1-=hp[i];
        //cout << i <<"  " << s1 << "\n";
        if(s1>=H)
        {
            cout << out + i + 1 ;
            return 0;
        }
    }
    
   
    return -1;
}