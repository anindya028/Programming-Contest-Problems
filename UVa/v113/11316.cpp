#include<stdio.h>
#include<algorithm>

using namespace std;

#define SZ 1000000
#define LL long long
#define Max(a,b) ((a)>(b)?(a):(b))

char p[SZ+2];
int pr[80000];

int nece[SZ+2],tot;
char fr[SZ+2];
int num[SZ+2];

int gene(int n)
{
	int i,j;
	for(i=2;i*i<=n;i++)
		if(!p[i])
			for(j=i*i;j<=n;j+=i)
				p[j]=1;
	j=0;
	for(i=2;i<=n;i++)
		if(!p[i])
			pr[j++]=i;
	return j;
}

int now[SZ],cs;

LL calc(LL a,LL b)
{
	int i;
	if(a>b)
		swap(a,b);
	LL ret=a*b;
	for(i=0;i<tot && num[i]<=a;i++)
		if(now[num[i]]!=cs)
		{
			if(fr[i]%2)
				ret-=((a/(LL)num[i])*(b/(LL)num[i]));
			else
				ret+=((a/(LL)num[i])*(b/(LL)num[i]));
		}
	return ret;
}

int main()
{
	//freopen("11316.out","w",stdout);
	int m=gene(SZ);
	int i,j;
	for(i=2;i<=SZ;i++)
	{
		int temp=i;
		if(!p[i])
		{
			nece[i]=1;
			num[tot]=i;
			fr[tot]=1;
			tot++;
			continue;
		}
		for(j=0;pr[j]*pr[j]<=temp && j<temp;j++)
			if(temp%pr[j]==0)
			{
				temp/=pr[j];
				if(temp%pr[j]==0)
					break;
				if(nece[temp])
					nece[i]=nece[temp]+1,num[tot]=i,fr[tot]=nece[i],tot++;
				break;
			}
	}
	
	int gp[20],n,t,r1,c1,r2,c2;
	scanf("%d",&t);
	for(cs=1;cs<=t;cs++)
	{
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&gp[i]);
		sort(gp,gp+n);
		int v=Max(r1,c1);
		v=Max(v,Max(r2,c2));
		for(i=0;i<tot && num[i]<=v;i++)
		//	if(now[num[i]]!=cs)
			{
				for(j=0;j<n && num[i]*gp[j]<=v;j++)
					now[num[i]*gp[j]]=cs;
			}
		for(j=0;j<n;j++)
			now[gp[j]]=cs;

		LL res=calc(r2,c2)-calc(r2,c1-1)-calc(r1-1,c2)+calc(r1-1,c1-1);
		res = (LL)(r2-r1+1)*(LL)(c2-c1+1) - res;
		printf("%lld\n",res);
	}
	return 0;
}