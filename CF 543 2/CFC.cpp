
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

int a[150];
int sid[100];
char p[1001*150][100];
int main()
{
    IOS
    int n, k;
    cin >> n >> k;
    for(int i =0;i<n;i++)
        cin >> a[i];
    int cminid = 0;
    int cmaxid = 0;
    for(int i =0;i<min(n,k);i++)
    {
        p[a[i]][i]=1;
        sid[i] = 0;
        cmaxid++;
    }
    //cmaxid++;
    int ans = 0;
    for(int t = 1;cminid<n;t++)
    {
        int rd = (int)(0.5+(100.0*cminid)/n);
        int lans = 0;
       // cout << rd << " " << cminid << " " << cmaxid << "\n";
        //if(rd > cminid && rd < cmaxid)
         //   ans++;
        for(int i =0;i<k;i++)
        {
            if(sid[i] >=0)
            {
                if(t-sid[i] == rd)
                    lans=max(lans,1);
                //cout << rd << " " << sid[i] << " " << t << "\n";
   
            }
            if(p[t][i])
            {
                cminid++;
                if(cmaxid<n)
                {   p[t+a[cmaxid]][i]=1;
                    sid[i]=t;
                    cmaxid++;
                }
                else
                {
                    sid[i]=-1;
                }
                
            }
        }
        ans+=lans;
    }
    cout << ans;
}
