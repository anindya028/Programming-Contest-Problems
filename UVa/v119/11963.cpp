#include<stdio.h>
#include<string.h>

#define Max(a,b) ((a)>(b)?(a):(b))

struct activ
{
	int id,cv,cp;
}a[10];

struct country
{
	int nac,emi;
	int acid[10],per[10];
}c[55];

int mp[135],na,nc;
int dp[12][100];

int make(int pos,int now,int tot)
{
	if(now==((1<<na)-1) || pos==nc)
		return 0;
//	if(dp[pos][now]!=-1)
//		return dp[pos][now];
	dp[pos][now] = make(pos+1,now,tot);
	int i,j,k;
	for(i=0;i<na;i++)
		if(! (now & 1<<i))
		{
			for(k=0;k<c[pos].nac;k++)
				if(c[pos].acid[k]==i && tot - a[i].cp - a[i].cv*c[pos].emi>=0)
				{
					j = (c[pos].emi*c[pos].per[k] + 50)/100 + make(pos+1,now | 1<<i,tot - a[i].cp - a[i].cv*c[pos].emi);
					dp[pos][now] = Max(dp[pos][now],j);
				}
		}
	return dp[pos][now];
}

int main()
{
	int t,i,bud;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&na,&nc,&bud);
		bud *= 1000000;
		
		char s[5];

		for(i=0;i<na;i++)
		{
			scanf("%s%d%d",s,&a[i].cp,&a[i].cv);
			a[i].cp *= 1000;
			mp[s[0]] = i;
		}

		for(i=0;i<nc;i++)
		{
			scanf("%d%d",&c[i].nac,&c[i].emi);
			int j;
			for(j = 0;j < c[i].nac;j++)
			{
				scanf("%s",s);
				c[i].acid[j] = mp[s[0]];
				scanf("%s",s);
				
				c[i].per[j] = (s[0]-'0');
				if(s[1]!='%')
					c[i].per[j]*=10, c[i].per[j] += (s[1]-'0');
			}
		}

		memset(dp,-1,sizeof(dp));
		printf("%d\n",make(0,0,bud));
	}
	return 0;
}