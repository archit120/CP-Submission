#include <bits/stdc++.h>

using namespace std;

int main()
{
	string h1;
	string h2;
	cin >> h1;
	cin >> h2;
	
	int h11 = stoi(h1.substr(0,2));
	int h22 = stoi(h2.substr(0,2));
	int m1 = stoi(h1.substr(3,2));
	int m2 = stoi(h2.substr(3,2));
	
	int t = ((m2 - m1) + (h22 - h11)*60)/2;
	int h = h11 + (t/60);
	int m = m1 + (t%60);
	if(m>=60)
	{
		h+=m/60;
		m = m %60;
	}
	string out = to_string(h)+":"+to_string(m);
	if(h<10)
		out = "0" + out;
	if(m<10)
		out = out.substr(0,3) + "0" + out.substr(3,1);
	cout << out;
}
