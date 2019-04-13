
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

#define N 200000
#define int long long
vector<tuple<int, int> > edges[N];

int parent[N];
int ssize[N];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    ssize[v] = 1;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ssize[a] < ssize[b])
            swap(a, b);
        parent[b] = a;
        ssize[a] += ssize[b];
    }
}
#undef int
int main()
{
    IOS
    #define int long long
    int n, m;
    cin >> n >> m;
    for(int i =0 ;i<n;i++)
        make_set(i);
    for(int i =0;i<m;i++)
    {
        int c,d,e;
        cin >> c >> d >> e;
        c--;d--;
        edges[c].push_back(make_tuple(d,-e));
        edges[d].push_back(make_tuple(c,-e));
    }
    priority_queue<tuple<int, int, int>> pq;
    //Start with vertice 0

    for(auto t: edges[0])
    {
        pq.push(make_tuple(get<1>(t), get<0>(t), 0));
    }
    int c = 0;
    while(pq.size())
    {
        auto p1 = pq.top();
        pq.pop();
        while(pq.size() && get<0>(pq.top()) == get<0>(p1) && get<1>(pq.top()) == get<1>(p1))
        {
            c++;pq.pop();
        }
        int id = get<1>(p1);
        if(find_set(id) == find_set(0))
            continue;

       // cout <<get<2>(p1) << " " << get<1>(p1) << "\n";

        union_set(0, id);
        for(auto t : edges[id])
            if(find_set(id) != find_set(get<0>(t)))
                pq.push(make_tuple(get<1>(t), get<0>(t), id));
    }
    cout << c;

}