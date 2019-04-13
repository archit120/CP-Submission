
#include <bits/stdc++.h>

using namespace std;



int main()
{
	#define int long long
	#define MOD % 1000000000 + 7
	int n, k;
	cin >> n >> k;
	
	int cpf = 1;
	int cpc = 1;
	int fpf = -1;
	int fpc = -1;	
	bool fs = 0;
	bool cs = 0;
	
	if(k&1)
	{
		int f = floor(n/(double)k);
		int c = ceil(n/(double)k);
		cpf =f*(f-1); cpc = c*(c-1);
		int fs = f;
		int cs = c;
		/*if(f - (k-1)/2 < 1 && (c - (k-1)/2 < 1 || c + (k-1)/2 > n-1))
		{
			cout << "-1";
		//	continue;
		}
		if(f + (k-1)/2 > n-1 && (c - (k-1)/2 < 1 || c + (k-1)/2 > n-1))
		{
			cout << "-1";
		//	continue;
		}*/
		for(int i =1;i<(k-1)/2;i++)
		{
			fs += 2*f;
			cs += 2*c;
			cout << (f-i) << " " << (f+i) << "\n";
			cpf = cpf * (f-i) MOD;
			cpf = cpf*(f-i-1) MOD;
			cpf = cpf* (f+i) MOD;
			cpf = cpf*(f+i-1) MOD;
			cpc = cpc * (c-i) MOD;
			cpc = cpc*(c-i-1) MOD;
			cpc = cpc* (c+i) MOD;
			cpc = cpc*(c+i-1) MOD;
			
		}

			
		if(n - (fs + (f - (k-1)/2)) -f >(k-1)/2)
		{
			int a = f - (k-1)/2;
			int b = n - (fs + (f - (k-1)/2));
			cout << a << "\n" << b << "\n";
			if(a < 1 || b > n-1)
			{
				
			}
			else
			{
				fpf  = cpf* a MOD;
				fpf = fpf*(a-1) MOD;
				fpf = fpf*(b-1) MOD;
				fpf = fpf*b MOD;
			}
		}
		if(f - (n - (fs + f + (k-1)/2)) > (k-1)/2)
		{
			int a = f - (k-1)/2;
			int b = n - (fs + (f - (k-1)/2));
						cout << a << "\n" << b << "\n";

			if(a < 1 || b > n-1)
			{
				
			}
			else
			{
				int tpf =cpf* a MOD;
				tpf = tpf*(a-1) MOD;
				tpf = tpf*(b-1) MOD;
				tpf = tpf*b MOD;
				fpf  = max(fpf, tpf);
			}
		} 
		
		if(n - (cs + (c - (k-1)/2)) -c >(k-1)/2)
		{
			int a = c - (k-1)/2;
			int b = n - (cs + (c - (k-1)/2));
						cout << a << "\n" << b << "\n";

			if(a < 1 || b > n-1)
			{
				
			}
			else
			{
					fpc  = cpc* a MOD;
				fpc = fpc*(a-1) MOD;
				fpc = fpc*(b-1) MOD;
				fpc = fpc*b MOD;
				
			}
		}
		if(c - (n - (cs + c + (k-1)/2)) > (k-1)/2)
		{
			int a = c + (k-1)/2;
			int b = n - (cs + (c + (k-1)/2));
						cout << a << "\n" << b << "\n";

			if(a < 1 || b > n-1)
			{
				
			}
			else
			{
				int tpc =cpc* a MOD;
				tpc = tpc*(a-1) MOD;
				tpc = tpc*(b-1) MOD;
				tpc = tpc*b MOD;
				fpc  = max(fpc, tpc);		
			}
		}
		
		cout << fpc << " "  << fpf; 
	}
	else
	{
	}
	

	return 0;
}
