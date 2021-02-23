#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct player
{
	int w,l;
}*p;
int main()
{
	int n,k,g,i,p1,p2,cs=0;
	char s1[15],s2[15];
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		scanf("%d",&k);
		if(cs)printf("\n");
		p=(player *)calloc(n+1,sizeof(player));
		g=n*k*(n-1)/2;
		for(i=0;i<g;i++)
		{
			scanf("%d%s%d%s",&p1,s1,&p2,s2);
			if(s1[0]=='r' && s2[0]=='s')
			{
				p[p1].w++;
				p[p2].l++;
			}
			else if(s1[0]=='s' && s2[0]=='p')
			{
				p[p1].w++;
				p[p2].l++;
			}
			else if(s1[0]=='p' && s2[0]=='r')
			{
				p[p1].w++;
				p[p2].l++;
			}
			else if(s2[0]=='r' && s1[0]=='s')
			{
				p[p2].w++;
				p[p1].l++;
			}
			else if(s2[0]=='s' && s1[0]=='p')
			{
				p[p2].w++;
				p[p1].l++;
			}
			else if(s2[0]=='p' && s1[0]=='r')
			{
				p[p2].w++;
				p[p1].l++;
			}
		}
		for(i=1;i<=n;i++)
		{
			if((p[i].w+p[i].l)==0)printf("-\n");
			else printf("%.3lf\n",p[i].w/(double)(p[i].w+p[i].l));
		}
		free(p);
		cs++;
	}
	return 0;
}













