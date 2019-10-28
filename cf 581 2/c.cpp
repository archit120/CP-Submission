
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MP make_pair
#define PB push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

long long gr[101][101];
long long dist[101][101];

long long path[1000000 + 1];
long long fpath[1000000 + 1];
int main()
{
    IOS
#define int long long
        int n;
    cin >> n;
    REP(i, n)
    {
        string s;
        cin >> s;
        REP(j, n)
        gr[i][j] = s[j] - '0';
    }

    int m;
    cin >> m;

    REP(i, m)
    {
        int j;
        cin >> j;
        path[i] = j - 1;
    }

    fpath[0] = path[0];
    int flen = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = gr[i][j];
            if (dist[i][j] == 0)
                dist[i][j] = LONG_MAX;
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for(int i =0;i<n;i++)
        dist[i][i]=0;
    int li = path[0];
    int li2 = 0;
    for (int j = 1; j < m - 1; j++)
    {
        //cout <<  << "\n";
        if (dist[li][path[j + 1]] < j - li2+1)
        {
            fpath[flen++] = path[j];
            li = path[j];
            li2 = j;
        }
    }
    fpath[flen++] = path[m - 1];
    cout << flen << "\n";
    REP(i, flen)
    cout << fpath[i] + 1 << " ";
}