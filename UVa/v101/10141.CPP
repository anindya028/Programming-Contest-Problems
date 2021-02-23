#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int  main()
{
	int n,p,i,j,r,max,cs=0;
	double d,min;
	char garb[100],ans[100],temp[100];
	while(scanf("%d%d",&n,&p)==2)
	{
		if(!n && !p)break;
		gets(garb);
		if(cs)printf("\n");
		for(i=0;i<n;i++)
			gets(garb);
		for(i=max=0,min=99999999999.99;i<p;i++)
		{
			gets(garb);
			gets(temp);
			sscanf(temp,"%lf%d",&d,&r);
			if(r>max)
			{
				strcpy(ans,garb);
				max=r;
				min=d;
			}
			if(r==max && (d+1e-12)<min)
			{
				strcpy(ans,garb);
				max=r;
				min=d;
			}
			for(j=0;j<r;j++)
				gets(garb);
		}
		printf("RFP #%d\n%s\n",++cs,ans);
	}
	return 0;
}













