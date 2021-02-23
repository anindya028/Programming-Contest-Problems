#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define Min(a,b) ((a)<(b)?(a):(b))
#define inf 1<<29
int nseg;
vector<int> seg[1005];
int dp[35][1005];

int make(int last,int pos)
{
	int now,mn=inf,i,is=0;
	if(pos==nseg)
		return 0;
	if(dp[last][pos]!=-1)
		return dp[last][pos];
	if(seg[pos].size()==1)
	{
		if(seg[pos][0]==last)
			dp[last][pos]=make(last,pos+1);
		else
			dp[last][pos]=1+make(seg[pos][0],pos+1);
		return dp[last][pos];
	}
	for(i=0;i<seg[pos].size();i++)
		is= is | (seg[pos][i]==last);
	for(i=0;i<seg[pos].size();i++)
	{
		now= (!is | (seg[pos][i]==last)) + seg[pos].size()-1 + make(seg[pos][i],pos+1);
		mn=Min(mn,now);
	}
	dp[last][pos]=mn;
	return dp[last][pos];
}

int main()
{
	int i,j,k,t,is[30],ans;
	char s[1005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&k,s);
		nseg=strlen(s)/k;
		memset(dp,-1,sizeof(dp));
		for(i=0;i<nseg;i++)
		{
			for(j=0;j<30;j++)
				is[j]=0;
			seg[i].clear();
			for(j=i*k;j<(i+1)*k;j++)
				if(!is[s[j]-'a'])
				{
					is[s[j]-'a']=1;
					seg[i].push_back(s[j]-'a');
				}
		}
		ans=inf;
		for(i=0;i<seg[0].size();i++)
			ans=Min(ans,seg[0].size()+make(seg[0][i],1));
		printf("%d\n",ans);
	}
	return 0;
}