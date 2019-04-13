
#include <bits/stdc++.h>

using namespace std;



int main()
{
	#define int long long
	#define MOD % 1000000000 + 7
	int n, k;
	cin >> n >> k;
	
	int cp = 1;
	int fp = -1;
	
	if(k&1)
	{
		int t = (int)(((double)n)/k + 0.5);
		cp = t;
		cp = cp * (t-1) MOD;
		int* vals = new int[k]();
		vals[(k-1)/2] = t;
		for(int i =1;i<(k-1)/2;i++)		
		{
			vals[(k-1)/2 - i] = t-i;
			vals[(k-1)/2 + i] = t + i;
		}
		
		int left = n - t*(k-2);
		
		if(t - (left - (t+(k-1)/2)) >= (k-1)/2)
		{
			int a = t+(k-1)/2;
			int b = left - a;
			vals[k-1] = a;
			vals[0] = b;
			while(vals[0]!=vals[1])
			{
				if(vals[0]*vals[1] < (vals[0]+1)*(vals[1]-1))
				{
					vals[0]++;
					vals[1]--;
				}
				else
					break;
			}
		}
		
		
		if((left - (t-(k-1)/2)) - t >= (k-1)/2)
		{
			int a = t-(k-1)/2;
			int b = left - a;
			vals[0] = a;
			vals[k-1] = b;
			while(vals[k-1]!=vals[k-2])
			{
				if(vals[k-1]*vals[k-2] < (vals[k-1]-1)*(vals[k-2]+1))
				{
					vals[k-2]++;
					vals[k-1]--;
				}
				else
					break;
			}
		}
		
		for(int i =0;i<k;i++)
			cout << vals[i] << " ";
		
	}
	else
	{
		int t = (int)(((double)n)/k + 0.5);
		int* vals = new int[k]();
		vals[k/2] = vals[(k/2)-1] = t;
		for(int i =1;i<(k-1)/2;i++)		
		{
			vals[(k/2)] = t-i;
			vals[(k-1)/2 + i] = t + i;
		}
		
		int left = n - t*(k-2);
		
		if(t - (left - (t+(k-1)/2)) >= (k-1)/2)
		{
			int a = t+(k-1)/2;
			int b = left - a;
			vals[k-1] = a;
			vals[0] = b;
			while(vals[0]!=vals[1])
			{
				if(vals[0]*vals[1] < (vals[0]+1)*(vals[1]-1))
				{
					vals[0]++;
					vals[1]--;
				}
				else
					break;
			}
		}
		
		
		if((left - (t-(k-1)/2)) - t >= (k-1)/2)
		{
			int a = t-(k-1)/2;
			int b = left - a;
			vals[0] = a;
			vals[k-1] = b;
			while(vals[k-1]!=vals[k-2])
			{
				if(vals[k-1]*vals[k-2] < (vals[k-1]-1)*(vals[k-2]+1))
				{
					vals[k-2]++;
					vals[k-1]--;
				}
				else
					break;
			}
		}
		
		for(int i =0;i<k;i++)
			cout << vals[i] << " ";
	}

		

	return 0;
}
