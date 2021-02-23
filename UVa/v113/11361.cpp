#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;

int dp[85][11][85],k;

int make(int num,int rem,int dig)
{
	int i;
	if(!rem)
	{
		if(dig%k==0 && num%k==0)
			return 1;
		return 0;
	}
	if(dp[num][rem][dig]!=-1)
		return dp[num][rem][dig];
	dp[num][rem][dig]=0;
	for(i=0;i<10;i++)
		dp[num][rem][dig]+=make((num*10+i)%k,rem-1,dig+i);
	return dp[num][rem][dig];
}

int main()
{
	int t,i,a,b,ans,j,prev,now,preva,prevb,nowa,nowb;
	string sa,sb;
	char s[20];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&k);
		if(k>82)
		{
			printf("0\n");
			continue;
		}
		memset(dp,-1,sizeof(dp));
		sprintf(s,"%d",a),sa=s;
		sprintf(s,"%d",b),sb=s;
		if(a==b)
		{
			j=0;
			for(i=0;i<sa.size();i++)
				j+=(sa[i]-'0');
			if(j%k==0 && a%k==0)
				printf("1\n");
			else
				printf("0\n");
			continue;
		}
		if(sa.size()<sb.size())
		{
			reverse(sa.begin(),sa.end());
			while(sa.size()<sb.size())
				sa+="0";
			reverse(sa.begin(),sa.end());
		}
		ans=0;
		j=prev=now=0;
		while(sa[j]==sb[j])
			now=(now*10+(sa[j]-'0'))%k,prev+=(sa[j]-'0'),j++;
		for(i=sa[j]-'0'+1;i<sb[j]-'0';i++)
			ans+=make((now*10+i)%k,sa.size()-j-1,prev+i);
		j++;
		preva=prev+sa[j-1]-'0',nowa=(now*10+sa[j-1]-'0')%k;
		prevb=prev+sb[j-1]-'0',nowb=(now*10+sb[j-1]-'0')%k;
		while(j<sa.size())
		{
			for(i=sa[j]-'0'+1;i<10;i++)
				ans+=make((nowa*10+i)%k,sa.size()-j-1,preva+i);
			for(i=0;i<sb[j]-'0';i++)
				ans+=make((nowb*10+i)%k,sb.size()-j-1,prevb+i);
			j++;
			preva=preva+sa[j-1]-'0',nowa=(nowa*10+sa[j-1]-'0')%k;
			prevb=prevb+sb[j-1]-'0',nowb=(nowb*10+sb[j-1]-'0')%k;
		}
		if(prevb%k==0 && nowb%k==0)
			ans++;
		if(preva%k==0 && nowa%k==0)
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}
