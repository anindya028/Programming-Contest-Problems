#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>

using namespace std;

#define inf (1<<29)
#define mem(a,b) memset(a,(b),sizeof(a))
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b)  ((a) < (b) ? (a) : (b))

typedef pair<int,int> pii;

char s[55][55];
string dp[55][55];

string make(int u,int v)
{
	if(u==v)
		return "";
	if(dp[u][v]!="z")
		return dp[u][v];
	dp[u][v][0]=s[u][v];
	int i,j;
	string now,aa="z";
	for(i=u+1;i<v;i++)
		for(j=i;j<v;j++)
			if(s[u][i]==s[j][v])
			{
				now=make(i,j);
				aa[0]=s[u][i];
				now = aa + now + aa;
				if(now.length()>dp[u][v].length())
					dp[u][v]=now;
				else if(now.length()==dp[u][v].length() && now<dp[u][v])
					dp[u][v]=now;
			}
	return dp[u][v];
}

int main()
{
	int t,cs,n,i,j;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				dp[i][j]="z";
		printf("%s\n",make(0,n-1).c_str());
	}
	return 0;
}
