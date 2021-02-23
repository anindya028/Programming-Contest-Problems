#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define LL long long
#define Max(a,b) ((a)>(b)?(a):(b))

char pattern[12][15];
char s[12][15];
int patlen[12];
//	           pat len char
pair<int,int> next[12][12][30];
//   pos mask pattern leng
LL dp[26][1<<10][12][12];
int n,m;

LL make(int pos,int now,int pat,int len)
{
	if(pos==n)
		return (now == ((1<<m)-1));
	if(dp[pos][now][pat][len]!=-1)
		return dp[pos][now][pat][len];

	dp[pos][now][pat][len] = 0;
	int i,mask;
	for(i=0;i<26;i++)
	{
		if(next[pat][len][i].first<m && next[pat][len][i].second == (patlen[next[pat][len][i].first]-1) )
			mask = now | (1<<( next[pat][len][i].first ));
		else
			mask = now;
		dp[pos][now][pat][len] += make(pos+1,mask,next[pat][len][i].first,next[pat][len][i].second);
	}
	return dp[pos][now][pat][len];
}

pair<int,int> match(int pat,int len)
{
	int i,j,k;
	int mx=-1,id=m;
	for(i=0;i<m;i++)
	{
		for(j=0;j<=len;j++)
		{
			int cnt=0;
			for(k=0;k<patlen[i] && j+k<=len;k++)
				if(pattern[pat][j+k] == s[i][k])
					cnt++;
				else
					break;
			if(cnt==len-j+1)
			{
				if(cnt-1>mx)
					mx = cnt-1, id = i;
			}
		}
	}
	if(mx==-1)
		mx = 0;
	return make_pair(id,mx);
}

vector<string> pass;
char got[30];
void gene(int pos,int now,int pat,int len)
{
	if(pos==n)
	{
		got[pos]=0;
		if((now == ((1<<m)-1)))
			pass.push_back(got);
		return;
	}
	if(dp[pos][now][pat][len]<=0)
		return;
	int i,mask;
	for(i=0;i<26;i++)
	{
		if(next[pat][len][i].first<m && next[pat][len][i].second == (patlen[next[pat][len][i].first]-1) )
			mask = now | (1<<( next[pat][len][i].first ));
		else
			mask = now;
		got[pos] = 'a'+i;
		gene(pos+1,mask,next[pat][len][i].first,next[pat][len][i].second);
	}
}

int main()
{
	int i,j,k,cs=0;
	while(scanf("%d%d",&n,&m)==2 && n)
	{
		for(i=0;i<m;i++)
			scanf("%s",pattern[i]),
			strcpy(s[i],pattern[i]),
			patlen[i] = strlen(pattern[i]);
		
		int cnt=0,f[12]={0};
		for(i=0;i<m;i++)
			for(j=i+1;j<m;j++)
				if(!strcmp(s[i],s[j]))
					f[j] = 1;
		
		for(i=0;i<m;i++)if(!f[i])
			for(j=0;j<m;j++)
				if(!f[j] && i!=j)
				{
					int u;
					for(u=0;u<patlen[i];u++)
					{
						int v=0;
						for(k=0;k<patlen[j];k++)
							if(s[i][u+k]==s[j][k])
								v++;
							else
								break;
						if(v==patlen[j])
							f[j] = 1;
					}
				}

		for(i=0;i<m;i++)
			if(!f[i])
				strcpy(pattern[cnt],s[i]),
				cnt++;
		m = cnt;
		
		for(i=0;i<m;i++)
			strcpy(s[i],pattern[i]),
			patlen[i] = strlen(pattern[i]);

		patlen[m] = 0;

		memset(dp,-1,sizeof(dp));
		for(i=0;i<m;i++)
			for(j=0;j<patlen[i];j++)
			{
				char temp = pattern[i][j+1];
				for(k=0;k<26;k++)
				{
					pattern[i][j+1] = 'a'+k;
					next[i][j][k] = match(i,j+1);
				}
				pattern[i][j+1] = temp;
			}

		for(k=0;k<26;k++)
		{
			pattern[m][0] = 'a'+k;
			next[m][0][k] = match(m,0);
		}
		LL ans = make(0,0,m,0);
		printf("Case %d: %lld suspects\n",++cs,ans);
		if(ans<=42)
		{
			pass.clear();
			gene(0,0,m,0);
			if(ans)
				sort(pass.begin(),pass.end());
			assert(ans==(int)pass.size());
			for(i=0;i<pass.size();i++)
				printf("%s\n",pass[i].c_str());
		}
	}
	return 0;
}