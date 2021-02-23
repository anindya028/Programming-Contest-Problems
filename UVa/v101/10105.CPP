#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int  main()
{
	int n,k,i,fact[13],co[13],ans;
	fact[0]=1;
	for(i=1;i<13;i++)
		fact[i]=fact[i-1]*i;
	while(scanf("%d%d",&n,&k)==2)
	{
		for(i=0;i<k;i++)
			scanf("%d",&co[i]);
		ans=fact[n];
		for(i=0;i<k;i++)
			ans/=fact[co[i]];
		printf("%d\n",ans);
	}
	return 0;
}













