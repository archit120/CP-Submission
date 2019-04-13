#include <bits/stdc++.h>

using namespace std;

int between(int difp, int l, int r)
{
	return (difp >= r && difp <=l) || (difp<= r && difp >= l);
}
int main()
{
	#define int long long
	int t;
	cin >> t;
	while(t--)
	{
		string s2,e2;
		int s,e,l,r;
		cin >> s2 >> e2;
		cin>> l >> r;
		
		if (s2 == "monday")
					s = 0;
		if (s2 == "tuesday")
					s = 1;
		if (s2 == "wednesday")
					s = 2;
		if (s2 == "thursday")
					s = 3;
		if (s2 == "friday")
					s = 4;
		if (s2 == "saturday")
					s = 5;
		if (s2 == "sunday")
					s = 6;
		if (e2 == "monday")
					e = 0;
		if (e2 == "tuesday")
					e = 1;
		if (e2 == "wednesday")
					e = 2;
		if (e2 == "thursday")
					e = 3;
		if (e2 == "friday")
					e = 4;
		if (e2 == "saturday")
					e = 5;
		if (e2 == "sunday")
					e = 6;
		
		
		int difp = abs(e-s+1);
		if(e-s > 0)
			difp = (e-s+1);
		else
			difp = (e-s+8);
		int r2 = r;
		int l2 =l;
		if(between(difp, l, r) && between(difp+7, 0, r-l+1))
		{
			cout << "many" << "\n";
		}
		else if(between(difp,l,r))
		{
			cout << 7* ((r-l)/7) + difp;
		}
		else
		{
			cout << "impossible" << "\n";
		}
		
	}
}
