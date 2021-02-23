#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int t,i,n,m;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
		if(n==m)printf("%d\n",((n+1)/2)*((n+1)/2+1)/2);
		else printf("%d\n",((n+1)/2)*((m+1)/2));
	}
	return 0;
}













