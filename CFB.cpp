#include <bits/stdc++.h>

using namespace std;

#define min(x,y) ((x)<(y)?(x):(y))

int main()
{
	#define int long long
	int n, k;
	cin >> n >> k;
	int mod[100];
	for(int i =0;i<k; i++)
		mod[i] = 0;
	for(int i =0;i<n;i++)
	{
		int t;
		cin >> t;
		t = t%k;
		mod[t]++;
	}
	int count = mod[0]/2;
//	cout << mod[0];
	for(int i=1;i<k;i++)
	{
		if(i+i!=k)
			count += min(mod[i],mod[k-i]);
		else
			count+=mod[i]/2;
		mod[i]=0;
		mod[k-i]=0;
	}
	cout << count*2;
}
