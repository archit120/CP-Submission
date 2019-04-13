#include <iostream>
#include <tuple>
#include <limits.h>
using namespace std;

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
long cabs(long a)
{
	if (a < 0)return a * -1;
	return a;
}

long  gcd(long a, long b) {
	return b == 0 ? a : gcd(b, a % b);
}
long add(long a, long x)
{
	if ((x > 0) && (a > LONG_MAX - x)) 
	{
		cout << "OVERFLOW";
	}
if ((x < 0) && (a < LONG_MIN - x)) cout<<"UNDERFLOW";
	return a+x;
}

#define N 100000
long segtree[4 * N + 4];
long K[N + 1];
long Ks[N + 1];
long Ks2[N + 1];
long A[N + 1];
tuple<long, long> lazy[4 * N + 4];

long create_tree(long Si, long l, long r)
{
	if (l > r)	return 0;
	if (l == r)
	{
		segtree[Si] = A[l];
		return A[l];
	}
	long s = add(create_tree(Si * 2, l, (l + r) / 2), create_tree(Si * 2 + 1, (l + r) / 2 + 1, r));
	segtree[Si] = s;
	return s;
}

long query_tree(long Si, long l, long r, long ql, long qr)
{
	if (l > r)return 0;
	if (get<0>(lazy[Si]))
	{
		if (l != r)
		{
			lazy[2 * Si] = lazy[Si];
			lazy[2 * Si + 1] = lazy[Si];
		}
		long s = add(Ks2[r - 1], - (r-l+1)*Ks[get<1>(lazy[Si]) - 1]);
		s= add(s, (r - l + 1)*get<0>(lazy[Si]));
		if (l > 1)
			s = add(s, -Ks2[l - 2]);
		segtree[Si] = s;
		lazy[Si] = make_tuple(0, 0);
	}
	if (l > qr || r < ql)	return 0;
	if (l >= ql && r <= qr)
	{
		return segtree[Si];
	}
	return add(query_tree(Si * 2, l, (l + r) / 2, ql, qr), query_tree(Si * 2 + 1, (l + r) / 2 + 1, r, ql, qr));
}

long update_tree(long Si, long l, long r, long ql, long qr, long a)
{
	if (get<0>(lazy[Si]))
	{
		query_tree(Si, l, r, l, r); //Push lazy prop hax
	}
	if (l > r)return segtree[Si] ;
	if (l > qr || r < ql)	return segtree[Si];
	if (l >= ql && r <= qr)
	{
		segtree[Si] = add(Ks2[r - 1],- (r - l + 1)*Ks[ql-1]);
		segtree[Si] = add(segtree[Si], (r - l + 1)*a );
		if (l > 1)
			segtree[Si] = add(segtree[Si], -Ks2[l - 2]);
		if (l != r)
		{
			lazy[2 * Si] = make_tuple(a, ql);
			lazy[2 * Si + 1] = make_tuple(a, ql);
			
		}
		return segtree[Si];
	}
	long s = add(update_tree(Si * 2, l, (l + r) / 2, ql, qr, a), update_tree(Si * 2 + 1, (l + r) / 2 + 1, r, ql, qr, a));
	segtree[Si] = s;
	return s;
}

long find_inversion(long newa, long i, long n)
{
	long low = i;
	long high = n;
	long mid = (low + high);
	while (high-low>1)
	{
		mid = (low + high) / 2;
		if (query_tree(1, 1, n , mid, mid) < newa + Ks[mid - 1] - Ks[i - 1])
			low = mid;
		else
			high = mid;
	}
	if (query_tree(1, 1, n, high, high) < newa + Ks[high - 1] - Ks[i - 1])
		return high;
	return low;
}
int main()
{
#define int long
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	int n;
//	cout << add(LONG_LONG_MAX, -LONG_LONG_MIN-1);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];

	for (int i = 1; i <= n - 1; i++)
	{
		cin >> K[i];
		Ks[i] = add(Ks[i - 1], K[i]);
		Ks2[i] = add(Ks2[i - 1], Ks[i]);
	}
	create_tree(1, 1, n);

	int q; cin >> q;
	while (q--)
	{
		char c;
		int a, b;
		cin >> c;
		cin >> a >> b;

		if (c == 's')
		{
			cout << query_tree(1, 1, n, a, b) << "\n";
		}
		else
		{
			int newa = add(query_tree(1, 1, n, a, a), b);
			int t = find_inversion(newa, a, n);
			//cout << t << "\n";
			update_tree(1, 1, n, a, t, newa);
		}
	}
}
