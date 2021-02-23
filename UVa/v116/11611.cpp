#include<stdio.h>
#include<string.h>

#define mod 50431
#define mem(a,b) memset(a,b,sizeof(a))

int dp[20][1<<8][1<<8],n,m,know,knext;
char s[9][22];

bool possible(int k,int pos,int j,int now,int next)
{
	if(pos+1==m)
		if(k<4 || k==5)
			return false;
	if(j+1==n)
		if(k<5 && k!=1)
			return false;
	know=now,knext=next;
	if(!k)
	{
		know|=(1<<j),know|=(1<<(j+1)),knext|=(1<<(j+1));
		if( (s[j][pos]=='.' || s[j][pos]=='R') && (s[j+1][pos]=='.' || s[j+1][pos]=='R')
			&& (s[j+1][pos+1]=='.' || s[j+1][pos+1]=='R') && !(now & 1<<(j+1)) && !(next & 1<<(j+1)))
				return true;
		return false;
	}
	else if(k==1)
	{
		if(!j)
			return false;	
		know|=(1<<j),knext|=(1<<j),knext|=(1<<(j-1));
		if( (s[j][pos]=='.' || s[j][pos]=='G') && (s[j][pos+1]=='.' || s[j][pos+1]=='G')
			&& (s[j-1][pos+1]=='.' || s[j-1][pos+1]=='G') && !(next & 1<<j) && !(next & 1<<(j-1)))
				return true;
		return false;
	}
	else if(k==2)
	{
		know|=(1<<j),knext|=(1<<j),know|=(1<<(j+1));
		if( (s[j][pos]=='.' || s[j][pos]=='B') && (s[j][pos+1]=='.' || s[j][pos+1]=='B')
			&& (s[j+1][pos]=='.' || s[j+1][pos]=='B') && !(now & 1<<(j+1)) && !(next & 1<<j))
				return true;
		return false;
	}
	else if(k==3)
	{
		know|=(1<<j),knext|=(1<<j),knext|=(1<<(j+1));
		if( (s[j][pos]=='.' || s[j][pos]=='N') && (s[j][pos+1]=='.' || s[j][pos+1]=='N')
			&& (s[j+1][pos+1]=='.' || s[j+1][pos+1]=='N') && !(next & 1<<(j+1)) && !(next & 1<<j))
				return true;
		return false;
	}
	else if(k==4)
	{
		know|=(1<<j),know|=(1<<(j+1));
		if( (s[j][pos]=='.' || s[j][pos]=='W') && (s[j+1][pos]=='.' || s[j+1][pos]=='W')
			&& !(now & 1<<(j+1)))
				return true;
		return false;
	}
	else if(k==5)
	{
		know|=(1<<j),knext|=(1<<j);
		if( (s[j][pos]=='.' || s[j][pos]=='P') && (s[j][pos+1]=='.' || s[j][pos+1]=='P')
			&& !(next & 1<<j))
				return true;
		return false;
	}
	else
	{
		know|=(1<<j);
		if( (s[j][pos]=='.' || s[j][pos]=='L'))
			return true;
		return false;
	}
}

int make(int pos,int now,int next)
{
	if(pos==m)
		return 1;
	if(dp[pos][now][next]!=-1)
		return dp[pos][now][next];
	int av=0,i,j;
	for(i=0;i<n;i++)
		if(!(now & 1<<i) && s[i][pos]!='#')
		{
			av++;
			j=i;
			break;
		}
	if(!av)
	{
		dp[pos][now][next]=make(pos+1,next,0);
		return dp[pos][now][next];
	}
	dp[pos][now][next]=0;
	for(i=0;i<7;i++)
		if(possible(i,pos,j,now,next))
			(dp[pos][now][next]+=make(pos,know,knext))%=mod;
	return dp[pos][now][next];
}

int main()
{
	int t,i,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		mem(dp,-1);
		printf("Case %d: %d\n",cs+1,make(0,0,0));
	}
	return 0;
}