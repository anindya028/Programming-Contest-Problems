#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
using namespace std;	
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define mem(a) memset(a,-1,sizeof(a))
#define LL long long 

LL dp[1<<17][5];
int n;
char s[20];
string ss;
map<char,int> mp;

LL make(int mask,int now)
{
	if(mask==((1<<(n))-1))
		return !now;
	if(dp[mask][now]!=-1)
		return dp[mask][now];
	dp[mask][now]=(!now && mask);
	int i,flag=0;
	Foro(i,n)
	{
		if(!(mask & 1<<i) && !flag)
		{
			dp[mask][now]+=make((mask | 1<<i),(now*16+mp[s[i]])%5);
			if(s[i]==s[i+1])
				flag=1;
		}
		else if(s[i]!=s[i+1])
			flag=0;
	}
	return dp[mask][now];
}

int main()
{
	int i;
	LL ans;
	int freq[200];
	For(i,1,10)
		mp[(char)(i+'0')]=i;
	For(i,10,16)
		mp[(char)(i-10+'A')]=i;
	while(gets(s))
	{
		if(s[0]=='#')
			break;
		mem(dp);
		ss=s;
		sort(ss.begin(),ss.end());
		n=ss.size();
		sprintf(s,"%s",ss.c_str());
		ans=make(0,0);
		printf("%lld\n",ans);
	}
	return 0;
}