#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,p,ans,i;
	while(scanf("%d",&n)==1)
	{
        	if(!n)break;
		scanf("%d",&ans);
		for(i=2;i<=n;i++)
		{
			scanf("%d",&p);
			ans=ans^p;
		}
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}













