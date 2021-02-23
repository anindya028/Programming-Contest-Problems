#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define mem(a) memset(a,-1,sizeof(a))

int dp[30][30][30],n;
int g[30];

int make(int pos,int rem,int last)
{
	if(!rem)
		return 1;
	if(pos==n)
		return 0;
	if(dp[pos][rem][last]!=-1)
		return dp[pos][rem][last];
	dp[pos][rem][last]=make(pos+1,rem,last);
	if(5*last<=4*g[pos])
		dp[pos][rem][last]+=make(pos+1,rem-1,g[pos]);
	return dp[pos][rem][last];
}

int main()
{
	int t,i,j;
	char s[1000];
	int is[30];
	gets(s);
	sscanf(s,"%d",&t);
	while(t--)
	{
		gets(s);
		n=0;
		for(i=0;i<30;i++)
			is[i]=0;
		for(i=0;s[i];i++)
			if(s[i]>=65 && s[i]<=90)
				is[s[i]-'A']=1;
		for(i=0;i<30;i++)
			if(is[i])
				g[n]=i+1,n++;
		mem(dp);
		i=n;
		if(!n)
		{
			printf("0 1\n");
			continue;
		}
		while(1)
		{
			j=make(0,i,0);
			if(j)
				break;
			i--;
		}
		printf("%d %d\n",i,j);
	}
	return 0;
}
