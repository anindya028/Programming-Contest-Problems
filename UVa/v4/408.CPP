#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int *flag,count,prev,cur,i,step,mod;
	while(scanf("%d%d",&step,&mod)==2)
	{
		flag=(int *)calloc(mod,sizeof(int));
		prev=0;
		flag[0]=count=1;
		for(i=1;i<mod;i++)
		{
			cur=(prev+step)%mod;
			if(!flag[cur])count++;
			flag[cur]=1;
			prev=cur;
		}
		if(count==mod)printf("%10d%10d    Good Choice\n\n",step,mod);
		else printf("%10d%10d    Bad Choice\n\n",step,mod);
		free(flag);
	}
	return 0;
}













