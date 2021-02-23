#include<stdio.h>
#include<string.h>

int num,den,n;
double p;
double dp[105][105];

double make(int now,int win)
{
	if(now)
	{
		if(win*den>num*now)
			return 1.0;
		if(now==n)
			return 0.0;
	}
	if(dp[now][win]>-1)
		return dp[now][win];
	dp[now][win]=(1-p)*make(now+1,win)+p*make(now+1,win+1);
	return dp[now][win];
}

int main()
{
	int t,cs,i,j;
	char s[20];
	gets(s);
	sscanf(s,"%d",&t);
	for(cs=0;cs<t;cs++)
	{
		gets(s);
		for(i=0;s[i];i++)
			if(s[i]=='/')
				s[i]=' ';
		sscanf(s,"%d%d%d",&num,&den,&n);
		p=num/(den+0.0);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				dp[i][j]=-1.0;
		double q=make(0,0);
	//	printf("->>%.6lf\n",q);
		int ans=(1/(1-q)+ 1e-6);
		printf("Case #%d: %d\n",cs+1,ans);
	}
	return 0;
}