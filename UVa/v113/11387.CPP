//Graph
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;
	

int main()
{
	int n,i;
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		if(n%2 || n==2 )
		{
			printf("Impossible\n");
			continue;
		}
		printf("%d\n",n+n/2);
		for(i=1;i<=n;i++)
			if(i==n)	
				printf("%d %d\n",i,(i+1)%n);
			else
				printf("%d %d\n",i,i+1);

		for(i=1;i<=n/2;i++)
			if(i!=n/2)
				printf("%d %d\n",i,(i+n/2)%n);
			else
				printf("%d %d\n",i,i+n/2);
	}
	return 0;
}
