
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

#define int long long
int ct[100000 + 1][2];
signed main()
{
    IOS
        string s;
    cin >> s;
    if(s=="0")
    {
        cout << s;
        return 0;
    }
    if(s=="1")
    {
        cout << 0;
        return 0;
    }
    int ol = 0;
    int zl = 0;
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] == '1')
            ol = max(ol + 1, zl + 1);
        else
            zl++;
        ol = max(ol, zl);
        ct[j][0] = zl;
        ct[j][1] = ol;
    }
    string s2;
    zl = ol;
    ct[s.size() - 1][0] = zl;
    for (int i = s.size() - 2; i >= 0; i--)
    {
        if (ct[i + 1][1] == ct[i][1])
            ct[i][0] = ct[i + 1][0] - 1;
        else
            ct[i][0] = min(ct[i][1], ct[i + 1][0]);
    }

    if (ct[0][0])
        s2 += '0';
    else
        s2 += '1';

    REP(i, s.size())
    {
        if (i == 0)
            continue;
        if(ct[i-1][0] < ct[i][0])   s2+='0';
        else s2 += '1';
    }

    
    cout << s2;
}