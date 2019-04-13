 
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
 
int dp[10000][10000];

int recur(int n, int k)
{
    if(dp[n][k])    return dp[n][k];
    if(n<=1)    return 1;
    else if(k==1)   return n;
    int gans = n;
    int chosen = 0;
    for(int i =1;i<n;i++)
    {
        int ans = max(recur(i, k-1), recur(n-i, k)) + 1;
        gans = min(gans, ans);
        if(gans==ans)
            chosen = i;
    }
    //cout << n << " " << k << " " << chosen << "\n";
    dp[n][k] = gans;
    return gans;
}

int recur_binary(int n, int k)
{
    if(dp[n][k])    return dp[n][k];
    if(n<=1)    return 1;
    else if(k==1)   return n;
    int low = 1, high = n, mid = (1+n)/2;
    while(low!=high)
    {
        int ans = max(recur(mid, k-1), recur(n-mid, k)) + 1;
        int ans2 = max(recur(high, k-1), recur(n-high, k)) + 1;
        int ans3 = max(recur(low, k-1), recur(n-low, k)) + 1;
        if(low==high-1)
            if(ans2<ans3)
                low=high;
            else
                high=low;
        else if(ans2>= ans)
            high = mid;
        else if(ans3 >= ans)
            low = mid;
    
        mid = (high+low)/2;
    }

    dp[n][k] =  max(recur(mid, k-1), recur(n-mid, k)) + 1;;
    return dp[n][k] ;
}

 int main()
 {
     IOS
    int n = 7, k=2;
    // cout << recur(n,k) - 1 ;
      for(int i =0;i<10000;i++)
        for(int j = 0;j<10000;j++)
            dp[i][j] = 0;
     cout<<" "<< recur_binary(n,k)-1; //we dont need to explicity drop an egg on the last floor
 }