
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
    IOS int n;
    cin >> n;
    int ls[150000 + 1];
    int rs[150000 + 1];

    string s;
    cin >> s;
    for (int j = 0; j < n; j++)
    {
        if(s[j]=='?')
            ls[j] = 27;
        else
            ls[j] = s[j]-'a';
    }
    cin >> s;
    for (int j = 0; j < n; j++)
    {
        if(s[j]=='?')
            rs[j] = 27;
        else
            rs[j] = s[j]-'a';
    }

    map<int, vector<int> > rss;
    map<int, vector<int> > lss;

    for(int j=0;j<n;j++)
    {
        
        if(lss.find(ls[j]) == lss.end())
        {
            vector<int> t;
            lss.insert({ls[j], t});
        }
        lss[ls[j]].push_back(j);

        if(rss.find(rs[j]) == rss.end())
        {
            vector<int> t;
            rss.insert({rs[j], t});
        }
        rss[rs[j]].push_back(j);
    }

    vector<int> leftovers_left;
    vector<int> leftovers_right;
    
    vector<tuple<int, int> >output;

    for(auto it = lss.begin(); it!=lss.end();it++)
    {
        int id = it->first;
        if(id==27)  continue;

        if(rss.find(id)!=rss.end())
        {
            vector<int> av = rss[id];
            vector<int> bv = it->second;
            for(int i =0;i<min(av.size(), bv.size());i++)
            {
                output.push_back(make_tuple(bv[i], av[i]));
            }
            if(av.size() < bv.size())
            {
               // leftovers_left.insert({id, vector<int>()});
                for(int i =av.size();i<bv.size();i++)
                {
                    leftovers_left.push_back(bv[i]);
                }
            }
            else if(bv.size() < av.size())
            {
                for(int i =bv.size();i<av.size();i++)
                {
                    leftovers_right.push_back(av[i]);
                }
            }
        }
        else
        {
            leftovers_left.insert(leftovers_left.end(), it->second.begin(), it->second.end());
        }
    }

    for(auto it = rss.begin(); it!=rss.end();it++)
    {
        int id = it->first;
        if(id==27)  continue;
        if(lss.find(id)==lss.end())
        {
            leftovers_right.insert(leftovers_right.end(), it->second.begin(), it->second.end());
        }
    }

    //match leftovers_right
    int mleft = lss[27].size();
    for(auto j : leftovers_right)
    {   
        if(!mleft)  break;
        output.push_back(make_tuple(lss[27][mleft-1], j));
        mleft--;
    }
    int mreft = rss[27].size();
    for(auto j : leftovers_left)
    {   
        if(!mreft)  break;
        output.push_back(make_tuple(j, rss[27][mreft-1]));
        mreft--;
    }

    if(mleft > 0 && mreft > 0)
    {
        for(int i =0;i<min(mleft, mreft);i++)
            output.push_back(make_tuple(lss[27][i], rss[27][i]));
    }

    cout << output.size() << "\n";
    for(auto t: output)
    {
        cout << get<0>(t)+1 << "  " << get<1>(t)+1 << "\n";
    }
}