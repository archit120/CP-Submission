
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

int gd[20][20];
stack<tuple<int, int> > moves;
int r, c;
bool dfs(int caller, int i, int j)
{
    set<tuple<int, int>> pl;
    gd[i][j] = caller;
    for(int k=0;k<r;k++)
        for(int l = 0;l<c;l++)
        {
            if(k==i)    continue;
            if(l==j)    continue;
            if(k+l==i+j)    continue;
            if(i-k == j-l)  continue;
            if(gd[k][l])    continue;
            pl.insert(make_tuple(k,l));
        }

    if(pl.size() ==0 && caller==r*c)
    {
        moves.push(make_tuple(i+1,j+1));
        return true;
    }
    else if(pl.size()==0)
    {    
        gd[i][j]= 0 ;
        return false;
    }
    bool as = false;
    for(auto t:pl)
    {
        if(dfs(caller+1, get<0>(t), get<1>(t)))
        {    as=true;
        break;
        }
    }
    if(as)
    {   
        moves.push(make_tuple(i+1,j+1)); return true;}
    gd[i][j] = 0;
    return false;
}

int main()
{
    IOS
    int t, t2;
    cin >> t;
    t2 = t;
    while(t--)
    {
        cin >> r >> c;
        for(int i =0;i<r;i++)
        {
            for(int j =0;j<c;j++)
            {
                gd[i][j]=0;
            }
        }
        while(moves.size())
            moves.pop();
        for(int i =0;i<r;i++)
        {
            for(int j =0;j<c;j++)
            {
                if(dfs(1,i,j))
                {
                    cout << "Case #" << (t2-t) <<": " << "POSSIBLE\n";
                    //cout << i+1 << " " << j+1 << "\n";
                    while(moves.size())
                    {
                        auto tp = moves.top();
                        cout << get<0>(tp) << " " << get<1>(tp) << "\n";
                        moves.pop();
                    }
                    goto next;
                }
            }
        }
        cout << "Case #" << (t2-t) <<": " << "IMPOSSIBLE\n";
        next:
        t=t;
    }
    
}