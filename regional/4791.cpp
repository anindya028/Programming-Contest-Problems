#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

#define S(a) ((a)*(a))
#define inf 1e12

struct point
{
	int x,y;
}p[105];

double dist(int i,int j)
{
	return sqrt( (double) S(p[i].x-p[j].x) + S(p[i].y-p[j].y));
}

int n,b1,b2;

double dp[105][105][2][2];
int parent[105][105][2][2];
double make(int pos1,int pos2,int f1,int f2)
{
	if(pos2==n-1)
	{
		if(f1 && f2)
			return 0;
		else
			return inf;
	}
	if(parent[pos1][pos2][f1][f2]!=-1)
		return dp[pos1][pos2][f1][f2];
	int i,nf2;
	parent[pos1][pos2][f1][f2] = n+1;
	dp[pos1][pos2][f1][f2] = inf;
	for(i=pos2+1;i<n;i++)
	{
		if(i==pos1 && pos1!=n-1)
			continue;
		double v = dist(pos2,i);
		nf2 = f2 || (i==b1) || (i==b2);
		if(i<pos1)
			v += make(pos1,i,f1,nf2);
		else
			v += make(i,pos1,nf2,f1);
		if(v<dp[pos1][pos2][f1][f2])
			dp[pos1][pos2][f1][f2] = v,
			parent[pos1][pos2][f1][f2] = i;
		if(pos2+1<pos1)
			break;
	}
	//printf("%d %d %d %d %lf\n",pos1,pos2,f1,f2,dp[pos1][pos2][f1][f2]);
	return dp[pos1][pos2][f1][f2];
}

vector<int> ans1,ans2;
void gene(int pos1,int pos2,int f1,int f2)
{
	if(pos2==n-1)
		return;
	
	int i=parent[pos1][pos2][f1][f2],nf2;
	nf2 = f2 || (i==b1) || (i==b2);
	if(i<pos1)
		ans2.push_back(i),
		gene(pos1,i,f1,nf2);
	else
		ans2.push_back(i),
		swap(ans1,ans2),
		gene(i,pos1,nf2,f1);
}

int main()
{
	int i,cs=0;
	while(scanf("%d%d%d",&n,&b1,&b2)==3 && n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		memset(parent,-1,sizeof(parent));
		printf("Case %d: %.2lf\n",++cs,make(0,0,0,0));
		ans1.clear();
		ans2.clear();
		ans1.push_back(0);
		ans1.push_back(1);
		ans2.push_back(0);
		gene(1,0,(b1==1 || b2==1),0);
		printf("0");
		if(ans1[1]!=1)
			swap(ans1,ans2);
		for(i=1;i<ans1.size();i++)
			printf(" %d",ans1[i]);
		reverse(ans2.begin(),ans2.end());
		for(i=1;i<ans2.size();i++)
			printf(" %d",ans2[i]);
		printf("\n");
	}
	return 0;
}