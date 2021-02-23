//Game DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int num[15],m,n,*w,i,j,flag;
	while(scanf("%d",&n)==1)
	{
		w=(int *)calloc(n+1,sizeof(int));
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&num[i]);
			w[num[i]]=1;
		}
		sort(num,num+m);
		for(i=2;i<=n;i++)
		{
			if(w[i])continue;
			flag=0;
			for(j=0;j<m;j++)
				if(i-num[j]>0)
				{
					if(w[i-num[j]]==2)
						flag=1;
				}
				else break;
			if(flag)w[i]=1;
			else w[i]=2;
		}
		if(w[n]==1)printf("Stan wins\n");
		else printf("Ollie wins\n");
		free(w);
	}
	return 0;
}













