//Simulation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

int main()
{
	char s[100][100];
	int dis[100][100],i,j,r,c,p,nr,nc,pr,pc;
	while(scanf("%d%d%d",&r,&c,&p)==3)
	{
		if(!r && !c && !p)
			break;
		for(i=0;i<r;i++)
			scanf("%s",s[i]);
		p--;
		for(i=0;i<=r;i++)
			for(j=0;j<=c;j++)
				dis[i][j]=-1;
		pr=0,pc=p;
		dis[pr][pc]=0;
		while(1)
		{
			if(s[pr][pc]=='N')
			{
				nr=pr-1;
				nc=pc;
			}
			else if(s[pr][pc]=='S')
			{
				nr=pr+1;
				nc=pc;
			}
			else if(s[pr][pc]=='E')
			{
				nr=pr;
				nc=pc+1;
			}
			else
			{
				nr=pr;
				nc=pc-1;
			}
			if(nr<0 || nr==r || nc<0 || nc==c)
			{
				printf("%d step(s) to exit\n",dis[pr][pc]+1);
				break;
			}
			if(dis[nr][nc]>=0)
			{
				printf("%d step(s) before a loop of %d step(s)\n",dis[nr][nc],dis[pr][pc]+1-dis[nr][nc]);
				break;
			}
			dis[nr][nc]=dis[pr][pc]+1;
			pr=nr;
			pc=nc;
		}
	}
	return 0;
}
