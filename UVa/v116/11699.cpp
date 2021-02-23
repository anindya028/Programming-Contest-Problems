#pragma warning (disable:4996)
#include<stdio.h>
#include<string.h>

char grid[16][16];
int val[16];

#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

int main()
{
	int i,j;
	while(scanf("%s",grid[0])==1)
	{
		if(!strcmp(grid[0],"END"))
			break;
		for(i=1;i<15;i++)
			scanf("%s",grid[i]);
		
		for(i=0;i<15;i++)
		{
			val[i]=0;
			for(j=0;j<15;j++)
				if(grid[i][j]=='#')
					val[i] += (1<<j);
		}

		int ans = 200;
		for(i=0;i<(1<<15);i++)
		{
			int cnt1 = 0,cnt2=0;
			int col = 0;
			for(j=0;j<15;j++)
				if(!(i & 1<<j))
					col |= val[j];
				else
					cnt1++;
			for(j=0;j<15;j++)
				if(col & 1<<j)
					cnt2++;
			ans = Min(ans,Max(cnt1,cnt2));
		}
		printf("%d\n",ans);
	}
	return 0;
}