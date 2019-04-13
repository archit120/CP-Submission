#include<bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define ld long double
#define endl '\n'
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)
#define trace(x) cerr << #x << ": " << x << " " << endl;

long long  gcd(long long a, long long b) {
	    return b == 0 ? a : gcd(b, a % b);
}
typedef long long int ll;

int cs[200001];
int c1[3];
int c2[3];
int c3[3];
int main()
{

#ifndef DEBUG
IOS
#endif
int n;
cin >> n;
	for(int i =0;i<n;i++)
	{
		char c;
		cin >> c;
		switch(c)
		{case 'R':cs[i]=0;break;
		case 'G': cs[i] = 1;break;
		case 'B':cs[i] =2;break;
		}
	}
	for(int i = 0;i<n;i+=3)c1[cs[i]]++;
	for(int i = 1;i<n;i+=3)c2[cs[i]]++;
	for(int i = 2;i<n;i+=3)c3[cs[i]]++;
	
	int minc = -1;
	int p1,p2,p3;
	for(int c11 = 0;c11<3;c11++)
	{
		for(int c22 = 0; c22 < 3; c22++)
		{
			if(c11 == c22)	continue;
			int c33 = 3 - c11 - c22;
			if(c33 < 0)	continue;
			int cost = c1[c22] + c1[c33] + c2[c11] + c2[c33] + c3[c11] + c3[c22];
			if(cost<minc || minc==-1)
			{
				minc = cost;
				p1 = c11, p2=c22,p3=c33;
			}
		}
	}
	cout << minc << "\n";
	for(int i =0;i<n;i++)
	{
		if(i%3==0)
		{
			switch(p1)
			{
				case 0:	cout << 'R'; break;
				case 1:	cout << 'G'; break;
				case 2:	cout << 'B'; break;
			}
		}
		if(i%3==1)
		{
			switch(p2)
			{
				case 0:	cout << 'R'; break;
				case 1:	cout << 'G'; break;
				case 2:	cout << 'B'; break;
			}
		}
		if(i%3==2)
		{
			switch(p3)
			{
				case 0:	cout << 'R'; break;
				case 1:	cout << 'G'; break;
				case 2:	cout << 'B'; break;
			}
		}
	}
		
}
