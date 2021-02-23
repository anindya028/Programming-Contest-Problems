#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	double sum,a0,an,c;
	int	n,i,t,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		if(i)
			printf("\n");
		scanf("%d%lf%lf",&n,&a0,&an);
		sum=0;
		for(j=0;j<n;j++)
		{
			scanf("%lf",&c);
			sum+=(n-j)*c;
		}
		printf("%.2lf\n",(n*a0 + an - 2*sum)/(n+1));
	}
	return 0;
}













