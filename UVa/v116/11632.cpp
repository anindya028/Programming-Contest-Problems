#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define inf 1<<30 
#define Min(a,b) (((a)<(b))?(a):(b))

struct he
{
	int bit,num,pre;
}temp;

int dp[150][150],n,val[150],same[150][150];
int cum[150];
vector<he> vv;

int make(int st,int nd)
{
	if(st>nd)
		return 0;
	if(dp[st][nd]!=-1)
		return dp[st][nd];
	dp[st][nd]=inf;
	int i,j,k;
	for(i=st;i<=nd;i++)
	{
		if(i<nd)
			k=(cum[nd]-cum[i])*(vv[i+1].pre-vv[st+1].pre);
		else
			k=0;
		j=same[st][i]+make(i+1,nd)-k;
		dp[st][nd]=Min(dp[st][nd],j);
	}
	return dp[st][nd];
}

int main()
{
	int i,j;
	while(scanf("%d",&n)==1 && n)
	{
		j=1;
		vv.clear();	
		for(i=1;i<=n;i++)
		{
			scanf("%d",&val[i]);
			if(val[i])
			{
				temp.bit=i,temp.num=val[i],temp.pre=j;
				j++;
				vv.push_back(temp);
			}
		}

		cum[0]=vv[0].num;
		for(i=1;i<vv.size();i++)
			cum[i]=cum[i-1]+vv[i].num;
		memset(dp,-1,sizeof(dp));
		for(i=0;i<vv.size();i++)
			for(j=i;j<vv.size();j++)
			{
				if(!i)
					same[i][j]=cum[j]*(vv[i].pre+vv[j].bit);
				else
					same[i][j]=(cum[j]-cum[i-1])*(vv[i].pre+vv[j].bit);
			}
		printf("%d\n",make(0,vv.size()-1));
	}
	return 0;
}