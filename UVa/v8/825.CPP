#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

#define size 205
int sq[size][size],dp[size][size];

int main()
{
	int cs,t,i,j,k,p,r,c,bs,dbs;
	char s[100];
	gets(s);
	sscanf(s,"%d",&t);
	for(cs=0;cs<t;cs++)
	{
		gets(s);
		if(cs)
			printf("\n");
		gets(s);
		sscanf(s,"%d%d",&r,&c);
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				sq[i][j]=1;
		for(i=0;i<r;i++)
		{
			gets(s);
			bs=0;
			sscanf(s+bs,"%d%n",&k,&dbs);
			bs+=dbs;
			while(sscanf(s+bs,"%d%n",&p,&dbs)==1)
			{
				sq[k][p]=0;
				bs+=dbs;
			}
		}
		if(sq[1][1])
			dp[1][1]=1;
		else
			dp[1][1]=0;
		for(i=2;i<=c;i++)
			if(sq[1][i])
				dp[1][i]=dp[1][i-1];
			else
				dp[1][i]=0;
		for(i=2;i<=r;i++)
			if(sq[i][1])
				dp[i][1]=dp[i-1][1];
			else
				dp[i][1]=0;
		for(i=2;i<=r;i++)
			for(j=2;j<=c;j++)
				if(sq[i][j])
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
				else
					dp[i][j]=0;

		printf("%d\n",dp[r][c]);
	}
	return 0;
}

