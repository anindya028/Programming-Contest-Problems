#include<stdio.h>
#include<string.h>

#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))

LL dp[55][1<<11],two[55];
int n,m,giv[10000],len;

LL gcd(LL a,LL b)
{
	if(!b)return a;
	return gcd(b,a%b);
}

LL make(int pos,int now)
{
	if(giv[now] && pos>=len)
		return 0;
	if(pos==n)
		return 1;
	if(dp[pos][now]!=-1)
		return dp[pos][now];

	dp[pos][now]=make(pos+1,(now*2)%two[len]);
	dp[pos][now]+=make(pos+1,(now*2+1)%two[len]);

	return dp[pos][now];
}

int main()
{
	int i,cs=0,j,k;
	two[0]=1;
	for(i=1;i<55;i++)
		two[i]=two[i-1]*2;
	char s[20];
	LL lob,hor;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		mem(giv,0);
		for(i=0;i<m;i++)
		{
			scanf("%s",s);
			k=0;
			for(j=0;s[j];j++)
				k=2*k+(s[j]=='H');
			giv[k]=1;
		}
		len=strlen(s);

		if(!m)
		{
			printf("Case %d: 1/1\n",++cs);
			continue;
		}
		hor=two[n];
		mem(dp,-1);
		lob=make(0,0);
		if(!lob)
		{
			printf("Case %d: 0\n",++cs);
			continue;
		}
		LL g=gcd(lob,hor);
		printf("Case %d: %lld/%lld\n",++cs,lob/g,hor/g);
	}
	return 0;
}