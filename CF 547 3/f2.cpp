
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

int a[1501];
int s[1501];
int main()
{
    IOS
    int n;
    cin >> n;
    for(int i =0;i<n;i++)
        cin >> a[i];
    s[0] = 0;
    for(int i =1;i<n+1;i++)
        s[i]=s[i-1]+a[i-1];

    map<int, vector<tuple<int, int> > > sums;

    for(int i = 0;i<n;i++)
    {
        for(int j =i;j<n;j++)
        {
            if(sums.find(s[j+1]-s[i])==sums.end())
                sums.insert({s[j+1]-s[i], vector<tuple<int, int> >()});
            sums[s[j+1]-s[i]].push_back(make_tuple(j,i));
        }
    }

    int maxct  =0;
    vector<tuple<int, int> > out;
    for(auto it = sums.begin(); it!=sums.end(); it++)
    {
        
        auto v =it->second;
        sort(v.begin(), v.end());
        vector<tuple<int, int> > tout;
        int lc = -1;
        int c = 0;
        for(auto j : v)
        {
            if(get<1>(j) > lc)
            {
                c++;
                lc = get<0>(j);
                tout.push_back(make_tuple(get<1>(j), get<0>(j)));
            }
        }
        if(c>maxct)
            maxct=c, out=tout;
    }

    cout << maxct <<"\n";
    for(auto j : out)
    {
        cout << get<0>(j) + 1 << " " << get<1>(j) + 1 << "\n";
    }
    
}