#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
using namespace std;	

#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

int given[100005];
struct element
{
	int freq,st,nd;
}ele[100005];
int dp[100005][20];

int process(int i,int j)
{
	int k=(int)floor(log((double)(j-i+1))/log(2.0));
	if(ele[dp[i][k]].freq>ele[dp[j-(1<<k)+1][k]].freq)
		return dp[i][k];
	else
		return dp[j-(1<<k)+1][k];
}

int binsearch(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(ele[mid].nd>=key)
			high=mid;
		else
			low=mid+1;
	}
	return low;
}

int main()
{
	int n,q,i,m,j,k,u,v;
	while(scanf("%d",&n)==1 && n)
	{
		scanf("%d",&q);
		Foro(i,n)
			scanf("%d",&given[i]);
		m=0;
		for(i=0;i<n;)
		{
			for(j=i+1;j<n && given[j]==given[i];j++);
			ele[m].st=i;
			ele[m].nd=j-1;
			ele[m].freq=j-i;
			i=j;
			m++;
		}
		k=(int)floor(log((double)(m))/log(2.0));
		for(i=0;i<m;i++)
			dp[i][0]=i;
		for(j=1;j<=k;j++)
			for(i=0;i+(1<<j)-1<m;i++)
				if(ele[dp[i][j-1]].freq>ele[dp[i+(1<<(j-1))][j-1]].freq)
					dp[i][j]=dp[i][j-1];
				else
					dp[i][j]=dp[i+(1<<(j-1))][j-1];
		Foro(i,q)
		{
			scanf("%d%d",&u,&v);
			u--,v--;
			j=binsearch(u,m);
			k=binsearch(v,m);
			if(j==k)
				printf("%d\n",v-u+1);
			else if(j+1==k)
				printf("%d\n", Max(ele[j].nd-u+1,v-ele[k].st+1) ); 
			else
				printf("%d\n",Max( Max(ele[j].nd-u+1,v-ele[k].st+1),ele[process(j+1,k-1)].freq));
		}
	}
	return 0;
}