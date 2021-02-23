#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define inf 1<<29
#define Min(a,b) (((a)<(b))?(a):(b))
#define mem(a,b) memset(a,b,sizeof(a))

int dp[105][7000],s,m,n,three[10];

struct tea
{
	int cost;
	vector<int> sub;
}t[105];

int make(int pos,vector<int> now)
{
	int state,i,j;
	for(i=state=0;i<s;i++)
		state=state*3+now[i];
	
	if(pos==n)
	{
		if(state==(three[s]-1))
			return 0;
		return inf;
	}
	if(dp[pos][state]!=-1)
		return dp[pos][state];
	
	dp[pos][state]=make(pos+1,now);
	
	for(i=0;i<t[pos].sub.size();i++)
		if(now[t[pos].sub[i]-1]<2)
			now[t[pos].sub[i]-1]++;
	
	j=make(pos+1,now)+t[pos].cost;
	dp[pos][state]=Min(dp[pos][state],j);

	return dp[pos][state];
}

int main()
{
	int i,bs,dbs,k,ans;
	three[0]=1;
	for(i=1;i<10;i++)
		three[i]=three[i-1]*3;
	char buf[1000];
	vector<int> ss;
	while(gets(buf))
	{
		sscanf(buf,"%d%d%d",&s,&m,&n);
		if(!s)
			break;
		ss.clear();
		for(i=0;i<s;i++)
			ss.push_back(0);
		for(i=ans=0;i<m;i++)
		{
			set<int> is;
			gets(buf);
			bs=dbs=0;
			sscanf(buf+bs,"%d%n",&t[i].cost,&dbs),bs+=dbs;
			t[i].sub.clear();
			while(sscanf(buf+bs,"%d%n",&k,&dbs)==1)
				t[i].sub.push_back(k),bs+=dbs;
			ans+=t[i].cost;
			for(k=0;k<t[i].sub.size();k++)
			{
				if(is.find(t[i].sub[k])==is.end())
					is.insert(t[i].sub[k]),ss[t[i].sub[k]-1]++;
			}
		}
		for(i=0;i<n;i++)
		{
			set<int> is;
			gets(buf);
			bs=dbs=0;
			sscanf(buf+bs,"%d%n",&t[i].cost,&dbs),bs+=dbs;
			t[i].sub.clear();
			while(sscanf(buf+bs,"%d%n",&k,&dbs)==1)
			{
				if(is.find(k)==is.end())
					is.insert(k),t[i].sub.push_back(k);
				bs+=dbs;
			}
		}
		mem(dp,-1);
		for(i=0;i<s;i++)
			if(ss[i]>=3)
				ss[i]=2;
		ans+=make(0,ss);
		printf("%d\n",ans);
	}
	return 0;
}