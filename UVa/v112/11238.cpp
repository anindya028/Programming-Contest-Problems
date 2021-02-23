#include<stdio.h>
#include<string.h>

#define LL long long

LL dp[11][4][302][2][11];

LL make(int fr,int t,int rem,int att,int sta)
{
	if(rem<0)
		return 0;
	if(!fr)
	{
		if(!t)
			return rem==0;
		else if(t==3)
		{
			int j,k=0;
			for(j=0;j<10;j++)
				if((rem-2*j)>=0 && (rem-2*j)<=(10-j))
					k++;
			if(rem-2*10>=0 && rem-2*10<=10)
				k++;
			return k;
		}
		else if(t==2)
		{
			int j,k=0;
			for(j=0;j<10;j++)
				if(rem-j>=0 && rem-j<=(10-j))
					k++;
			if(rem-10>=0 && rem-j<=10)
				k++;
			return k;
		}
		else
			return rem<=10;
	}
	if(dp[fr][t][rem][att][sta]!=-1)
		return dp[fr][t][rem][att][sta];
	dp[fr][t][rem][att][sta]=0;
	int i,nfr,natt,nt,nrem,nsta;
	for(i=0;i<=sta;i++)
	{
		if(i==sta)
		{
			nfr=fr-1,natt=0,nsta=10;
			nt=t/2;
			if(!att)
				nt+=2;
			else
				nt+=1;
		}
		else
		{
			if(!att)
				nfr=fr,natt=1,nsta=sta-i;
			else
				nfr=fr-1,natt=0,nsta=10;
			nt=t/2;
		}
		if(t==3)
			nrem=rem-i*3;
		else if(t)
			nrem=rem-i*2;
		else
			nrem=rem-i;

		dp[fr][t][rem][att][sta]+=make(nfr,nt,nrem,natt,nsta);
	}
	return dp[fr][t][rem][att][sta];
}

int main()
{
	int n;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d",&n)==1 && n>=0)
		printf("%lld\n",make(10,0,n,0,10));
	return 0;
}