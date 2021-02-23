#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<string>
using namespace std;	
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define inf 1e9
#define eps 1e-7
#define myabs(a) (((a)>0)?(a):-(a))
#define LL long long 

int dp[1<<14][14],mat[55][55],pr[55];
int p,store[14],v;

int make(int now,int pos)
{
	int i,tot=0;
	Foro(i,p)
		if(now & 1<<i)
			tot++;
	if(tot==v)
		return -mat[store[pos]][store[0]];
	if(dp[now][pos]>-inf)
		return dp[now][pos];
	int t;
	Foro(i,p)
		if(!(now & 1<<i))
			t=pr[store[i]]-mat[store[pos]][store[i]] + make(now | 1<<i,i),
			dp[now][pos]=Max(dp[now][pos],t);
	return dp[now][pos];
}

int main()
{
	int t,n,m,i,j,k,sum,ans;
	double c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		Fore(i,0,n)
		{
			Fore(j,0,n)
				mat[i][j]=inf;
			pr[i]=0.;
		}
		Foro(i,m)
			scanf("%d%d%lf",&j,&k,&c),mat[j][k]=mat[k][j]=Min(mat[j][k],(int)(c*100+eps));
		Fore(k,0,n)
			Fore(i,0,n)
				Fore(j,0,n)
					mat[i][j]=Min(mat[i][j],mat[i][k]+mat[k][j]);
		scanf("%d",&p);
		Foro(i,p)
			scanf("%d%lf",&k,&c),pr[k]+=(int)(c*100+eps);
		p=1;
		Fore(i,0,n)
			if(pr[i]>0)
				store[p]=i,p++;
		store[0]=0;
		k=p;
		ans=-inf;
		while(k>1)
		{
			Foro(i,p)
				Foro(j,1<<p)
					dp[j][i]=-inf;
			v=k;
			sum=make(1,0);
			ans=Max(ans,sum);
			k--;
		}
		if(ans>0)
			printf("Daniel can save $%.2lf\n",(double)(ans/100.0));
		else
			printf("Don't leave the house\n");
	}
	return 0;
}