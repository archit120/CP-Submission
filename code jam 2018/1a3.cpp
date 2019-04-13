
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
    int64 t, t2;
    cin >> t;
    t2=t;
    #define int long long
    int cookies[101][2];
    while(t--)
    {
        int n, p;
        cin >> n >> p;
        for(int i =0;i<n;i++)
            cin >> cookies[i][0] >> cookies[i][1];
        for(int i =0;i<n;i++)
            if(cookies[i][0] > cookies[i][1])
                swap(cookies[i][0], cookies[i][1]);
        
        double ep = 0;
        double dp = 0;
        double ap = 0;
        for(int i =0;i<n;i++)
            ep+=2*(cookies[i][0] + cookies[i][1]);
        dp = p - ep;
        vector<tuple<double, double> > ranges;
        for(int i =0;i<n;i++)
            ranges.push_back(make_tuple((double)2*cookies[i][0],2* sqrt(pow(cookies[i][0],2) + pow(cookies[i][1],2))));
        sort(ranges.begin(), ranges.end());
        for(int i = 0;i<ranges.size();i++)
        {
            double s0 = 0;
            double s1 = 0;
            for(int j = i; j < ranges.size(); j++)
            {
                s0+=get<0>(ranges[j]), s1+=get<1>(ranges[j]);
                if(s0 > dp) break;
                if(s1 > dp) ap = dp;
                else if( s1 > ap) ap = s1;
                //cout << i << " " << j << " " << s0 << " " << s1 << "\n";
            }
        }
        std::cout << std::fixed;
        std::cout << std::setprecision(6);
        cout << "Case #" << (t2 - t) << ": "<< ep + ap << "\n";
    }
    return 0;
}