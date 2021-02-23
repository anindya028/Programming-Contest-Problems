#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct point
{
	int x,y;
}p[200000];
int main()
{
	int n,i,counts,counto,mx,my;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
		}
		mx=p[n/2].x;
		my=p[n/2].y;
		for(i=counts=counto=0;i<n;i++)
		{
			if((p[i].x>mx && p[i].y>my) || (p[i].x<mx && p[i].y<my))
				counts++;
			if((p[i].x>mx && p[i].y<my) || (p[i].x<mx && p[i].y>my))
				counto++;
		}
		printf("%d %d\n",counts++,counto++);
	}
	return 0;
}













