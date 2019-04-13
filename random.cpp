#include <stdio.h>

int main()
{
	int n, x;
	scanf("%d %d", &n, &x);
	int p =1;
	int cp = x;
	int out = 1;
	while(p<=n)
	{
		if(p&n)
			out*=cp;
		cp=cp*cp;
		p=p*2;
	}
	printf("%d",out);
	return true;
}
