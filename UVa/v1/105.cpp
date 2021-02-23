#include<stdio.h>
	
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,a)
#define Max(a,b) (((a)>(b))?(a):(b))

int main()
{
	int st,nd,d,i,now=0,h[10005]={0};
	while(scanf("%d%d%d",&st,&d,&nd)==3)
		For(i,st,nd)
			h[i]=Max(h[i],d);
	now=0;
	nd=0;
	Foro(i,10000)
		if(h[i]!=now)
			if(!nd)
				printf("%d %d",i,h[i]),now=h[i],nd=1;
			else
				printf(" %d %d",i,h[i]),now=h[i];
	printf("\n");
	return 0;
}
