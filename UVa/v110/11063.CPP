//Easy DP
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int n,*num,*sum,i,j,flag,cs=0;
	while(scanf("%d",&n)==1)
	{
        	flag=1;
		num=(int *)calloc(n,sizeof(int));
		sum=(int *)calloc(22000,sizeof(int));
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]<1)flag=0;
			if(i)
			{
				if(num[i]<num[i-1])flag=0;
			}
			for(j=0;j<=i;j++)
			{
				if(!sum[num[i]+num[j]])sum[num[i]+num[j]]=1;
				else flag=0;
			}
		}
		if(flag)printf("Case #%d: It is a B2-Sequence.\n\n",++cs);
		else printf("Case #%d: It is not a B2-Sequence.\n\n",++cs);
		free(num);
		free(sum);
        }
	return 0;
}













