#include<stdio.h>
#include<string.h>

#define mem(a,b) memset(a,b,sizeof(a))

char s1[35],s2[35];
struct memo
{
	int len;
	long long way;
}dp[35][35];
int len1,len2;

memo make(int i,int j)
{
	memo ret;
	if(!s1[i] || !s2[j])
	{
		ret.len=(!s1[i])?len2-j:len1-i;
		ret.way=1;
		return ret;
	}
	if(dp[i][j].len!=-1)
		return dp[i][j];

	if(s1[i]==s2[j])
		dp[i][j]=make(i+1,j+1),dp[i][j].len++;
	else
	{
		dp[i][j]=make(i+1,j),dp[i][j].len++;
		ret=make(i,j+1),ret.len++;
		if(ret.len<dp[i][j].len)
			dp[i][j]=ret;
		else if(ret.len==dp[i][j].len)
			dp[i][j].way+=ret.way;
	}

	return dp[i][j];
}


int main()
{
	int t,cs;
	char s[30];
	gets(s);
	sscanf(s,"%d",&t);
	for(cs=0;cs<t;cs++)
	{
		gets(s1);
		gets(s2);
		len1=strlen(s1),len2=strlen(s2);
		mem(dp,-1);
		memo k=make(0,0);
		printf("Case #%d: %d %lld\n",cs+1,k.len,k.way);
	}
	return 0;
}

