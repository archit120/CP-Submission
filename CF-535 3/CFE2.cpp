
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

#define N 100000

tuple<int, int> segtree[4 * (N + 1)];
tuple<int, int, int> out[400];
int lazy[4 * (N + 1)];
int v[N + 1];

tuple<int, int> create_segtree(int si, int l, int r)
{
    lazy[si] = 0;
    if (l == r)
        return segtree[si] = make_tuple(v[l], v[l]);
    auto t1 = create_segtree(2 * si, l, (l + r) / 2);
    auto t2 = create_segtree(2 * si + 1, (l + r) / 2 + 1, r);
    return segtree[si] = make_tuple(min(get<0>(t1), get<0>(t2)), max(get<1>(t1), get<1>(t2)));
}

tuple<int, int> query_segtree(int si, int l, int r, int ql, int qr)
{
    if (lazy[si])
    {
        segtree[si] = make_tuple(get<0>(segtree[si]) + lazy[si], get<1>(segtree[si]) + lazy[si]);
        if (l != r)
        {
            lazy[2 * si] += lazy[si];
            lazy[2 * si + 1] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (l > qr || r < ql)
        return make_tuple(INT_MAX, INT_MIN);
    if (ql <= l && qr >= r)
        return segtree[si];
    auto t1 = query_segtree(2 * si, l, (l + r) / 2, ql, qr);
    auto t2 = query_segtree(2 * si + 1, (l + r) / 2 + 1, r, ql, qr);
    return make_tuple(min(get<0>(t1), get<0>(t2)), max(get<1>(t1), get<1>(t2)));
}

void update_segtree(int si, int l, int r, int ql, int qr, int s)
{
    if (lazy[si])
        query_segtree(si, l, r, l, r);
    if (l > qr || r < ql)
        return;
    if (ql <= l && qr >= r)
    {
        segtree[si] = make_tuple(get<0>(segtree[si]) + s, get<1>(segtree[si]) + s);
        if (l != r)
        {
            lazy[2 * si] += s;
            lazy[2 * si + 1] += s;
        }
        return;
    }
    update_segtree(2 * si, l, (l + r) / 2, ql, qr, s);
    update_segtree(2 * si + 1, (l + r) / 2 + 1, r, ql, qr, s);
    auto t1 = segtree[2 * si];
    auto t2 = segtree[2 * si + 1];
    segtree[si] = make_tuple(min(get<0>(t1), get<0>(t2)), max(get<1>(t1), get<1>(t2)));
}

int main()
{
    IOS int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> v[i + 1];
    for (int i = 0; i < m; i++)
    {
        int c, d;
        cin >> c >> d;
        out[i] = make_tuple(c, d, i);
    }
    if (n == 1)
    {
        cout << 0 << "\n"
             << 0;
        return 0;
    }
    create_segtree(1, 1, n);
    auto r = query_segtree(1, 1, n, 1, n);
    int maxd = get<1>(r) - get<0>(r);
    sort(out, out + m);
    int num = 0;
    int sme = 0;
    for (int si = 0; si < m; si++)
    {
        for (int ei = si; ei < m; ei++)
        {
            update_segtree(1, 1, n, get<0>(out[ei]), get<1>(out[ei]), -1);
            r = query_segtree(1, 1, n, 1, n);
            int d = get<1>(r) - get<0>(r);
            // cout << d << "\n";

            if (d > maxd)
            {
                num = (ei - si + 1);
                sme = si;
                maxd = d;
            }
        }
        for (int ei = si; ei < m; ei++)
            update_segtree(1, 1, n, get<0>(out[ei]), get<1>(out[ei]), 1);
    }

    cout << maxd << "\n"
         << num << "\n";
    for (int i = sme; i < num + sme; i++)
    {
        cout << get<2>(out[i]) + 1 << " ";
    }
}
