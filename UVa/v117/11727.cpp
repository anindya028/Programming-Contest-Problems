#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int a[3],cs,t;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		printf("Case %d: %d\n",cs+1,a[1]);
	}
	return 0;
}