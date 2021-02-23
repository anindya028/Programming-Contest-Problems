#include<stdio.h>

#define Min(a,b) (((a)<(b))?(a):(b))

int coin[]={5,10,20,50,100,200};
int num[6],mn,tot;

int calc(int n)
{
	int i,ret=0;
	for(i=5;n;i--)
		ret+=(n/coin[i]),n%=coin[i];
	return ret;
}

void make(int pos,int now,int cnt)
{
	if(pos==6)
	{
		if(now>=tot)
			cnt+=calc(now-tot),
			mn=Min(mn,cnt);
		return;
	}
	int i;
	make(pos+1,now,cnt);
	for(i=1;i<=num[pos];i++)
	{
		now+=coin[pos];
		cnt++;
		make(pos+1,now,cnt);
	}
}

int main()
{
	int i,j;
	double g;
	while(1)
	{
		for(i=j=0;i<6;i++)
			scanf("%d",&num[i]),j+=num[i];
		if(!j)
			break;
		scanf("%lf",&g);
		j= (int)(g*1000 + 1.);
		tot=j/10;
		mn=100000000;
		make(0,0,0);
		printf("%3d\n",mn);
	}
	return 0;
}
