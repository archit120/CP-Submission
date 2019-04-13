
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
int hours[2*100000 + 1];

int main()
{
    IOS
    
    int n;
    cin >> n;
    int out = 0;
    for(int i =0;i<n;i++)
        cin >> hours[i];

    for(int i =0;i<n;i++)
    {
        if(hours[i]==1)
        {
            int j =i+1;
            for(j =i+1;j<n;j++)
                if(hours[j]==0) break;
            out = max(out, j-i);
            i = j;
        }
    }

    if(hours[0]==1)
    {
        int t1 = 0;
        int i = n-1;
        for( i =n-1;i>=0;i--)
            if(hours[i]==0) break;
        i = n-1 - i;
        int j =0;
        for(j =0;j<n;j++)
            if(hours[j]==0) break;
        if(i!=n)
            out = max(out, j+i);
    }
    cout << out;
}