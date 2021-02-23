#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;

#define Long long long 	

#define sq(a) ((a)*(a))
#define pb(a) push_back(a)
#define Min(a,b) (((a)<(b))?(a):(b))
#define Max(a,b) (((a)>(b))?(a):(b))
#define eps 1e-9
#define inf 1<<29
#define pye 2.*acos(0.)
#define SZ(v) ((int)(v).size())
#define For(i,a,b) for(i=(a);i<(b);++i)
#define Fore(i,a,b) for(i=(a);i<=(b);++i)
#define Forc(i,v) For(i,0,SZ(v))
#define Foro(i,a) For(i,0,a)

#define size 5000005
int pr[665000];
bool p[size];
int gene(int n)
{
	int root=ceil(sqrt(n));
    int i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2]=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i])
        {
			pr[j]=i*2+1;
			j++;
        }
	}
    return j;
}

int main()
{
	int m=gene(2*size);
	Long n,fact[100];
	register int i,j;
	while(scanf("%lld",&n)==1 && n)
	{
		if(n<6 && n>-6)
		{
			printf("-1\n");
			continue;
		}
		if(n<0)
			n=-n;
		for(i=j=0;sq(pr[i])<=n && i<m;i++)
		{
			if(n%pr[i]==0)
			{
				fact[j]=pr[i];
				j++;
				while(n%pr[i]==0)
					n/=pr[i];
			}
		}
		if(n>1)
		{
			fact[j]=n;
			j++;
		}
		if(j<2)
			printf("-1\n");
		else
			printf("%lld\n",fact[j-1]);
	}
	return 0;
}
