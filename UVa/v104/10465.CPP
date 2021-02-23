//DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define min(a,b) ((a<b)?(a):(b))
#define max(a,b) ((a>b)?(a):(b))
int n,m,T;
struct timed
{
	int bur;
	int beer;
}tim[10005];
timed recur(int t)
{
	timed mbur,nbur;
	if(tim[t].bur>=0)
		return tim[t];
	if(t==min(m,n))
	{
		tim[t].bur=1;
		tim[t].beer=0;
		return tim[t];
	}
	if((t-m)<0)
	{
		nbur=recur(t-n);
		tim[t].bur=nbur.bur+1;
		tim[t].beer=nbur.beer;
		return tim[t];
	}
	if((t-n)<0)
	{
		mbur=recur(t-m);
		tim[t].bur=mbur.bur+1;
		tim[t].beer=mbur.beer;
		return tim[t];
	}
	mbur=recur(t-m);
	nbur=recur(t-n);
	if(nbur.beer==mbur.beer)
	{
		tim[t].bur=max(nbur.bur,mbur.bur)+1;
		tim[t].beer=nbur.beer;
	}
	else
	{
		if(nbur.beer<mbur.beer)
		{
			tim[t].bur=nbur.bur+1;
			tim[t].beer=nbur.beer;
		}
		else
		{
			tim[t].bur=mbur.bur+1;
			tim[t].beer=mbur.beer;
		}
	}
	return tim[t];
}
int main()
{
	int i;
	timed ans;
	while(scanf("%d%d%d",&m,&n,&T)==3)
	{
		for(i=0;i<min(m,n);i++)
		{
			tim[i].bur=0;
			tim[i].beer=i;
		}
		for(;i<=T;i++)
			tim[i].bur=-1;
		ans=recur(T);
		if(ans.beer==0)printf("%d\n",ans.bur);
		else printf("%d %d\n",ans.bur,ans.beer);
	}
	return 0;
}













