#include <stdio.h>
#define s(x) x*x

using namespace std;

int main()
{
	float a = 1.3;
	if ( a== 1.3) printf("a");
	if ( a== (float)1.3) printf("b");
	if ( a== (double)1.3) printf("c");
	double f = 1.3;
	if ( f== 1.3) printf("d");
	 a = 1.625;
	if ( a== 1.625) printf("e");
	if ( a== (float)1.625) printf("f");
	int c = 1, d =2 , e= 3;
	c = (d=e, e=c, e = d);
	printf("%d", c);
	return 0;
}
