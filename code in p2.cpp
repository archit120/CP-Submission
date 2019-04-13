
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

typedef vector<tuple<int, int, int>> rn;

int create_string(string& s, rn c)
{
    int t = 0;
    int ms = 0;
    for(auto j : c)
    {
        int st = get<0>(j), et = get<1>(j);
        if(et==st)
        {
            ms = max(ms, 1);
            s+="1";
        }
        else
        {
            int d = et - st;
            if(get<2>(j))
              ms = max(ms, d- (d/2) + 1);
            for(int i =0;i<=d/2;i++)
                s+="1";
            for(int i = d/2 + 1;i<=d;i++)
                s+="0";
        }
    }
    return ms;
}

void interpret_input(string inp, rn prev, rn &c)
{
    int exp = get<2>(prev[0]);
    int s0 = 0, s1 = 0;
    int st = get<0>(prev[0]), et = get<1>(prev[0]);
    int sid = 0;
    for (int i = 0; i < inp.size(); i++)
    {
        if(!exp)
        {
            c.push_back(prev[sid]);
            sid++;
            s0 = 0, s1 = 0;

            exp = get<2>(prev[sid]);
            s0 = 0, s1 = 0;
            st = get<0>(prev[sid]), et = get<1>(prev[sid]);
            i--;
            continue;
        }
        if (inp[i] == '0')
            s0++;
        else
            s1++;
        exp--;
        if (!exp)
        {
            int d = et-st;
            if(d==0)
                c.push_back(prev[sid]);
            else
            {
                
                c.push_back(make_tuple(st, st+ d / 2, s1));
                c.push_back(make_tuple(st + d / 2 + 1, et, s0));
            }
           
                sid++;
                if(sid<prev.size())
                {
                s0 = 0, s1 = 0;

                exp = get<2>(prev[sid]);
                s0 = 0, s1 = 0;
                st = get<0>(prev[sid]), et = get<1>(prev[sid]);
                }
        }
    }
    while(sid<prev.size())
    {
        c.push_back(prev[sid++]);
    }

}
int main()
{
    //IOS

    int t;
    cin >> t;
    while (t--)
    {
        int n, b, f;
        cin >> n >> b >> f;
        int identified = 0;
        rn miss;
        string out = "";
        string inp = "";
        for (int i = 0; i < n / 2; i++)
            out += "1";
        for (int i = n / 2; i < n; i++)
            out += "0";
        vector<int> s;
        cout << out << "\n";
        cin >> inp;
        int s0 = 0, s1 = 0;
        for (char c : inp)
            if (c == '0')
                s0++;
            else
                s1++;
        miss.push_back(make_tuple(0, n / 2 - 1, s1));
        miss.push_back(make_tuple(n / 2, n - 1, s0));
      /* for(auto j : miss)
            {
                cout << get<0>(j) << " " << get<1>(j) << " " << get<2>(j)<<"\n";
            }*/
        int ms = n/2;
        while(ms > 1)
        {
            string s = "";
            ms = create_string(s, miss);
            cout << s <<"\n";
            cin >> s;
            rn nm;
            interpret_input(s, miss, nm);
            miss = nm;
            /*for(auto j : miss)
            {
                cout << get<0>(j) << " " << get<1>(j) << " " << get<2>(j)<<"\n";
            }*/
            ms = create_string(s, miss);

            //cout << ms << "\n";
        }

        for(auto j : miss)
        {
            if(!get<2>(j))
            {
                for(int i =get<0>(j);i<=get<1>(j);i++)
                    cout << i<< " ";
            }
        }
        cout << "\n";
        int verdict;
        cin >> verdict;
        if(verdict==-1)
            break;
    }
}