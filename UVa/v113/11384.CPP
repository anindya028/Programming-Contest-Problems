//Very good Math
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;
	

int main()
{
	int n;
	while(scanf("%d",&n)==1)
		printf("%.0lf\n",1.+floor(log(n)/log(2) + 1e-7));
	return 0;
}
