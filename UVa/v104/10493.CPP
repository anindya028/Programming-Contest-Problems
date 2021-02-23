#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		if(!n || !m)
			break;
		if(n==1)
		{
			if(m==1)printf("%d %d Multiple\n",n,m);
			else printf("%d %d Impossible\n",n,m);
			continue;
		}
		if((m*n-1)%(n-1)!=0)printf("%d %d Impossible\n",n,m);
		else printf("%d %d %d\n",n,m,(m*n-1)/(n-1));
	}
	return 0;
}













