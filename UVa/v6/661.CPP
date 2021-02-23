#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,m,c,*con,*flag,i,max,sum,temp,cs=0;
	while(scanf("%d%d%d",&n,&m,&c)==3 && n)
	{
        	max=sum=0;
		con=(int *)calloc(n+1,sizeof(int));
		flag=(int *)calloc(n+1,sizeof(int));
		for(i=1;i<=n;i++)scanf("%d",&con[i]);
		for(i=0;i<m;i++)
		{
			scanf("%d",&temp);
			if(flag[temp])
			{
				flag[temp]=0;
				sum-=con[temp];
			}
			else
			{
				flag[temp]=1;
				sum+=con[temp];
			}
			if(sum>max)max=sum;
		}
		if(max>c)printf("Sequence %d\nFuse was blown.\n\n",++cs);
		else printf("Sequence %d\nFuse was not blown.\nMaximal power consumption was %d amperes.\n\n",++cs,max);
        }
	return 0;
}













