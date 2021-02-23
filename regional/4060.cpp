#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

#define LL long long

bool p[1000005];
LL pr[80000];

int gene(void)
{
	int i,j,n=1000000;
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

vector<int> fact,fr,factor;

void bktk(int now,int pos)
{
	if(now>1000000)
		return;
	if(pos==fact.size())
	{
		factor.push_back(now);
		return;
	}
	int i;
	bktk(now,pos+1);
	for(i=1;i<=fr[pos] && now<=1000000;i++)
		now*=fact[pos],
		bktk(now,pos+1);
}

LL gcd(LL a,LL b)
{
	if(!b)return a;
	return gcd(b,(a%b));
}

LL lcm(LL a,LL b)
{
	return (a/gcd(a,b))*b;
}

bool ok(int a,int b,int c,LL n)
{
	return lcm(lcm(a,b),c)==n;
}

int main()
{
	LL n,temp;
	int m=gene();
	int i,j,k,cs=0;
	while(scanf("%lld",&n)==1 && n)
	{
		temp=n;
		fact.clear();
		factor.clear();
		fr.clear();
		j=0;
		for(i=0;i<m && pr[i]*pr[i]<=temp;i++)
			if(temp%pr[i]==0)
			{
				fact.push_back(pr[i]);
				fr.push_back(0);
				while(temp%pr[i]==0)
					fr[j]++,temp/=pr[i];
				j++;
			}
		if(temp<1000000 && temp>1)
			fact.push_back(temp),
			fr.push_back(1);
		bktk(1,0);
		sort(factor.begin(),factor.end());
		printf("Scenario %d:\n",++cs);
		int got=0;
		for(i=0;i<factor.size();i++)
			for(j=i+1;j<factor.size() && factor[j]-factor[i]<=25;j++)
				for(k=j+1;k<factor.size() && factor[k]-factor[i]<=25;k++)
					if(ok(factor[i],factor[j],factor[k],n))
						printf("%d %d %d\n",factor[i],factor[j],factor[k]),got=1;
		if(!got)
			printf("Such bells don't exist\n");
		printf("\n");
	}
	return 0;
}