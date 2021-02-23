#include<stdio.h>
#include<string.h>

#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))

LL dp[20][17],n;
char s[20];
int giv[20];

LL make(int now,int pos)
{
	if(pos==n)
		return 1;
	
	if(dp[now][pos]!=-1)
		return dp[now][pos];

	int i;
	if(s[pos]!='?')
	{
		if(pos+1<n)
			if(s[pos+1]!='?')
				if((giv[pos+1]-giv[pos])>=-1 && (giv[pos+1]-giv[pos])<=1)
					return 0;
		
		dp[now][pos]=make(giv[pos],pos+1);
		return dp[now][pos];
	}
	dp[now][pos]=0;
	for(i=0;i<n;i++)	
		if(now-i<-1 || now-i>1)
		{
			if(pos+1<n && s[pos+1]!='?')
				if(giv[pos+1]-i>=-1 && giv[pos+1]-i<=1)
					continue;
		
			dp[now][pos]+=make(i,pos+1);
		}

	return dp[now][pos];		
}

int main()
{
	int i,j;
	
	while(scanf("%s",s)==1)
	{
		n=strlen(s);
		for(i=0;s[i];i++)
			if(s[i]!='?')
			{
				if(s[i]>='1' && s[i]<='9')
					giv[i]=s[i]-'1';
				else
					giv[i]=s[i]-'A'+9;
			}
		mem(dp,-1);
		printf("%lld\n",make(18,0));
	}
	return 0;
}