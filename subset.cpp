#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i =0;i<(1<<n+1);i++)
	{
		if(i==0)	cout <<"phi";
		else
			for(int b = 0;b<n+1;b++)
				if (i & (1<<b))
					cout << b << " ";
					
		cout<<"\n";
	}
}
