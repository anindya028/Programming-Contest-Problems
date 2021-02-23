#include<stdio.h>
#include<string.h>

#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))

LL mod,two[50];

struct mybig
{
	LL fir,sec;
}dp[3][37][37][37],dp1[3][37][37][37];

mybig add(mybig a,mybig b)
{
	mybig c;
	c.fir=(a.fir+b.fir)%mod;
	c.sec=a.sec+b.sec+(a.fir+b.fir)/mod;
	return c;
}

mybig make(int pos,int a,int b,int c)
{
	mybig ret;
	ret.sec=0;
	if(!a && !b && !c)
	{
		ret.fir=!pos;
		return ret;
	}
	if(a<0 || b<0 || c<0)
	{
		ret.fir=0;
		return ret;
	}

	if(dp[pos][a][b][c].sec!=-1)
		return dp[pos][a][b][c];

	if(!pos)
		dp[pos][a][b][c]= add(make(1,a,b-1,c),make(2,a,b,c-1));
	else if(pos==1)
		dp[pos][a][b][c]= add(make(0,a-1,b,c),make(2,a,b,c-1));
	else
		dp[pos][a][b][c]= add(make(1,a,b-1,c),make(0,a-1,b,c));

	return dp[pos][a][b][c];
}

mybig make1(int last,int a,int b,int c)
{
	mybig ret;
	ret.sec=0;
	if(!b && !c && a==1 && last)
	{
		ret.fir=1;
		return ret;
	}
	if(b<0 || c<0 || a<0)
	{
		ret.fir=0;
		return ret;
	}
	if(dp1[last][a][b][c].fir!=-1)
		return dp1[last][a][b][c];

	if(!last)
		dp1[last][a][b][c]=add(make1(1,a,b-2,c),make1(2,a,b,c-2));
	else if(last==1)
		dp1[last][a][b][c]=add(make1(0,a-2,b,c),make1(2,a,b,c-2));
	else
		dp1[last][a][b][c]=add(make1(1,a,b-2,c),make1(0,a-2,b,c));

	return dp1[last][a][b][c];
}

int main()
{
	mod=1000000000;
	mod*=mod;
	mem(dp,-1);
	mem(dp1,-1);
	int i,n,t,cs,m;
	two[0]=1;
	for(i=1;i<50;i++)
		two[i]=two[i-1]*2;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("Case %d: 1\n",cs+1);
			continue;
		}
		mybig now=make(0,n/3,n/3,n/3);
		m=n/3;
		if(m%2==0)
		{
			mybig k=make1(0,n/3-1,n/3,n/3);
			now = add(now,k);
		}
		now.fir=((now.sec%2)*mod+now.fir)/2;
		now.sec/=2;
		if(!now.sec)
			printf("Case %d: %lld\n",cs+1,now.fir);
		else
			printf("Case %d: %lld%.18lld\n",cs+1,now.sec,now.fir);
	}
	return 0;
}