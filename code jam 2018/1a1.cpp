
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

int main()
{
  //  IOS
    int t;
    cin >> t;
    int t2 = t;
    int ar[100][100];
    int ar2[100][100];
    int sv[100];
    int sh[100];
    while (t--)
    {
        int r, c, h, v;
        int tc = 0;
        cin >> r >> c >> h >> v;
        for (int i = 0; i < r; i++)
        {
            string inc;
            sh[i] = 0;
            cin >> inc;
            for (int j = 0; j < c; j++)
            {
                if (inc[j] == '.')
                    ar[i][j] = 0;
                else
                    ar[i][j] = 1, tc = tc + 1;
                sh[i] += ar[i][j];
            }
        }
        if (tc % ((v + 1) * (h + 1)))
        {
            cout << "Case #" << (t2 - t) << ": IMPOSSIBLE\n";
            continue;
        }
        for (int j = 0; j < c; j++)
        {
            sv[j] = 0;
            for (int i = 0; i < r; i++)
                sv[j] += ar[i][j];
          //  cout << sv[j] << "\n";
        }
        int eh = tc / (h + 1);
        int ev = tc / (v + 1);
        int cv = sv[0];
        bool fail = false;
        vector<int> vc;
        vector<int> hc;
        
        for (int i = 1; i < c; i++)
        {
            if (cv == ev)
            {
                cv = 0;
                vc.push_back(i - 1);
            }
            else if (cv > ev)
            {
                fail = true;
                break;
            }
            
            cv += sv[i];
        }
        if (fail)
        {
            cout << "Case #" << (t2 - t) << ": IMPOSSIBLE\n";
            continue;
        }
      //  cout << ev << " " << vc[0] << " " << vc[1]<<"\n";
        int ch = sh[0];
        for (int i = 1; i < r; i++)
        {
            if (ch == eh)
            {
                ch = 0;
                hc.push_back(i - 1);
            }
            else if (ch > eh)
            {
                fail = true;
                break;
            }
            
            ch += sh[i];
        }
        hc.push_back(r);
        vc.push_back(c);
        if (fail)
        {
            cout << "Case #" << (t2 - t) << ": IMPOSSIBLE\n";
            continue;
        }
        int vi = 0;
        int vindex = vc[0];
        for(int i =0;i<h+1;i++)
            for(int j = 0; j<v+1;j++)
                ar2[i][j]=0;
        for(int i =0;i<c;i++)
        {
            int hindex = hc[0];
            int hi = 0;
            if(i-1==vindex)
                vindex = vc[++vi];
            
            //ar2[hi][vi] = 0;
            for(int j =0;j<r;j++)
            {
                if(j-1==hindex)
                {    hindex=hc[++hi];
                    //ar2[hi][vi]=0;
                }
                ar2[hi][vi] += ar[j][i];
                //cout << vindex << hindex << "\n";
            }
        }
        for(int i =0;i<h+1;i++)
        {
            for(int j = 0; j<v+1;j++)
                if(ar2[i][j]!=tc/(h+1)/(v+1))
                    fail=true;
        }
              if (fail)
        {
            cout << "Case #" << (t2 - t) << ": IMPOSSIBLE\n";
            continue;
        }
        cout << "Case #" << (t2 - t) << ": POSSIBLE\n";
    }
}