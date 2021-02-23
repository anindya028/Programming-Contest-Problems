#include<stdio.h>
#include<string.h>

int cnt[105][105];

int main()
{
	int i,j,x1,x2,y1,y2,cs,t,a,b,c;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(i=x1;i<x2;i++)
			for(j=y1;j<y2;j++)
				cnt[i][j]++;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(i=x1;i<x2;i++)
			for(j=y1;j<y2;j++)
				cnt[i][j]++;
		a=b=c=0;
		for(i=0;i<100;i++)
			for(j=0;j<100;j++)
				a+=(cnt[i][j]==2),
				b+=(cnt[i][j]==1),
				c+=(cnt[i][j]==0);
		printf("Night %d: %d %d %d\n",cs+1,a,b,c);
	}
	return 0;
}