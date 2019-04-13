
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
#define int long long
void print_num(int i )
{
    for(int j =0;j<18;j++)
        cout << i <<" ";
    cout << "\n";
}

int read_remainder(int i)
{
    int s = 0;
    for(int j=0;j<18;j++)
        {
            int t;
            cin >> t;
            s+=t;
        }
    return s% i;
}
int crt(int num[], int rem[], int k) 
{ 
    int x = 1; 
    while (true) 
    { 
        
        int j; 
        for (j=0; j<k; j++ ) 
            if (x%num[j] != rem[j]) 
               break; 
  
        if (j == k) 
            return x; 
  
        x++; 
    } 
  
    return x; 
} 

#undef int
int main()
{
    #define int long long
    //IOS
    int t, t2, n, m;
    cin >> t >> n >> m;
    t2 =t;
    int r[6];
    int num[6]={18,5,7,11,13,17};

    while(t--)
    {
        print_num(2);
        read_remainder(2);
        print_num(18);
        r[0] = read_remainder(18);
        print_num(5);
        r[1] = read_remainder(5);
        print_num(7);
        r[2] = read_remainder(7);
        print_num(11);
        r[3] = read_remainder(11);
        print_num(13);
        r[4] = read_remainder(13);
        print_num(17);
        r[5] = read_remainder(17);

        cout << crt(num, r, 6) <<"\n";

        int out;
        cin >> out;
        if(out!=1)
            break;
    }
    
}