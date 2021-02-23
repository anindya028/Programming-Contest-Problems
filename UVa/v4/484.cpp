#include<stdio.h>
#include<stdlib.h>
int flag[100000];
int flagm[100000];
int main()
{
	int ans[10000],n,i=0,j;
	while(scanf("%d",&n)==1)
	{
		if(n>=0)
		{
			if(!flag[n])
			{
				ans[i]=n;
				i++;
			}
			flag[n]++;
		}
		else
		{
			if(!flagm[n*(-1)])
			{
				ans[i]=n;
				i++;
			}
			flagm[n*(-1)]++;
		}
	}
	for(j=0;j<i;j++)
	{
		if(ans[j]>=0)printf("%d %d\n",ans[j],flag[ans[j]]);
		else printf("%d %d\n",ans[j],flagm[ans[j]*(-1)]);
	}
	return 0;
}