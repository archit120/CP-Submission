
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

vector<int> v1[101];
int v2[101];
int v4[101];
int v3[101];
int main()
{
    IOS
    int n, m, k;
    cin >> n >> m >> k;
    for(int i =0;i<n;i++)
    {
        cin >> v2[i];
    }
    for(int i =0;i<n;i++)
    {
        int v;
        cin >> v;
        v--;
        v1[v].push_back(v2[i]);
        v4[i] = v;
    }
    for(int i =0;i<m;i++)
    {
        sort(v1[i].begin(), v1[i].end(), greater<int>());
    }
    for(int i =0;i<k;i++)
    {    
        cin >> v3[i];
        v3[i]--;
    }
    int ans = 0;
    for(int i =0;i<m;i++)
    {
        int c = 0;
        for(int d = 0;d<v1[i].size();d++)
        {
            //cout << v1[i][d] << "\n";
            for(int e = 0;e<k;e++)
                if(v1[i][d] == v2[v3[e]] && d!=0)
                { 
                    //cout << v1[i][d] << " "<< v2[v3[e]]<<"\n";
                       ans++;
                }
        }
        ans+=c;
    }
    cout << ans;
}