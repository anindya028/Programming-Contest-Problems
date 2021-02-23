#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define inf 1000000000
int main()
{
	int i,j,k,tr[50][50],rh[50][50],ht[50][50],t[50],r[50],h[50],nt,nr,nh,st,sr,sh,min;
	while(scanf("%d%d%d",&nt,&nr,&nh)==3)
	{
		for(i=0;i<nt;i++)
		{
			scanf("%d",&t[i]);
			for(j=0;j<nr;j++)
				scanf("%d",&tr[i][j]);
		}
		for(i=0;i<nr;i++)
		{
			scanf("%d",&r[i]);
			for(j=0;j<nh;j++)
				scanf("%d",&rh[i][j]);
		}
		for(i=0;i<nh;i++)
		{
			scanf("%d",&h[i]);
			for(j=0;j<nt;j++)
				scanf("%d",&ht[i][j]);
		}
		min=inf;
		for(i=0;i<nt;i++)
			for(j=0;j<nr;j++)
				for(k=0;k<nh;k++)
					if(!tr[i][j] && !rh[j][k] && !ht[k][i])
					{
						if((t[i]+r[j]+h[k])<min)
						{
							min=t[i]+r[j]+h[k];
							st=i;
							sr=j;
							sh=k;
						}
					}
		if(min==inf)printf("Don't get married!\n");
		else printf("%d %d %d:%d\n",st,sr,sh,min);
	}
	return 0;
}













