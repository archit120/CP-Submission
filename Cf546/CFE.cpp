#include <iostream>
#include <tuple>
using namespace std;

#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

long long cabs(long long a)
{
	if (a < 0)return a * -1;
	return a;
}

long long  gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

#define N 100000
long long segtree[4 * N + 4];
long long K[N + 1];
long long Ks[N + 1];
long long Ks2[N + 1];
long long A[N + 1];
tuple<long long, long long> lazy[4 * N + 4];

long long create_tree(long long Si, long long l, long long r)
{
	if (l > r)	return 0;
	if (l == r)
	{
		segtree[Si] = A[l];
		return A[l];
	}
	long long s = create_tree(Si * 2, l, (l + r) / 2) + create_tree(Si * 2 + 1, (l + r) / 2 + 1, r);
	segtree[Si] = s;
	return s;
}

long long query_tree(long long Si, long long l, long long r, long long ql, long long qr)
{
	if (l > r)return 0;
	if (get<1>(lazy[Si]))
	{
		if (l != r)
		{
			lazy[2 * Si] = lazy[Si];
			lazy[2 * Si + 1] = lazy[Si];
		}
		long long s = Ks2[r - 1] - (r-l+1)*Ks[get<1>(lazy[Si]) - 1];
		if (l > 1)
			s += (r - l + 1)*get<0>(lazy[Si]) - Ks2[l - 2];
		else
			s+= (r - l + 1)*get<0>(lazy[Si]);

		segtree[Si] = s;
		lazy[Si] = make_tuple(0, 0);
	}
	if (l > qr || r < ql)	return 0;
	if (l >= ql && r <= qr)
	{
		return segtree[Si];
	}
	return query_tree(Si * 2, l, (l + r) / 2, ql, qr) + query_tree(Si * 2 + 1, (l + r) / 2 + 1, r, ql, qr);
}

long long update_tree(long long Si, long long l, long long r, long long ql, long long qr, long long a)
{
	if (get<1>(lazy[Si]))
	{
		query_tree(Si, l, r, l, r); //Push lazy prop hax
	}
	if (l > r)return segtree[Si] ;
	if (l > qr || r < ql)	return segtree[Si];
	if (l >= ql && r <= qr)
	{
		segtree[Si] = Ks2[r - 1]- (r - l + 1)*Ks[ql-1];
		
		if (l > 1)
			segtree[Si] += (r - l + 1)*a - Ks2[l - 2];
		else
			segtree[Si] += (r - l + 1)*a ;
		if (l != r)
		{
			lazy[2 * Si] = make_tuple(a, ql);
			lazy[2 * Si + 1] = make_tuple(a, ql);
			
		}
		return segtree[Si];
	}
	long long s = update_tree(Si * 2, l, (l + r) / 2, ql, qr, a) + update_tree(Si * 2 + 1, (l + r) / 2 + 1, r, ql, qr, a);
	segtree[Si] = s;
	return s;
}

long long find_inversion(long long newa, long long i, long long n)
{
	long long low = i;
	long long high = n;
	long long mid = (low + high);
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++)
		cin >> A[i];

	for (long long i = 1; i <= n - 1; i++)
	{
		cin >> K[i];
		Ks[i] = Ks[i - 1] + K[i];
		Ks2[i] = Ks2[i - 1] + Ks[i];
	}
	
	
	create_tree(1, 1, n);

	long long q; cin >> q;
	while (q--)
	{
		char c;
		long long a, b;
		cin >> c;
		cin >> a >> b;
		
		if (c == 's')
		{
		
			cout << query_tree(1, 1, n, a, b) << "\n";
		}
		else
		{
			long long newa = query_tree(1, 1, n, a, a) + b;
			int t = find_inversion(newa, a, n);
			//cout << t << "\n";
			update_tree(1, 1, n, a, t, newa);
		}
	}
}
