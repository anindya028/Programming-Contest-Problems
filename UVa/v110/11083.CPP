//Number Theory
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define size 500
long pr[170];
bool p[size];
//#define Long __int64
#define Long long long
long gene(long n)
{
	int root=ceil(sqrt(n));
    long i,j;
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
	int m=gene(size*2);
	Long n,b,ans,c,p,i;
	while(scanf("%lld%lld",&n,&b)==2)
	{
		if(!n && !b)break;
		for(i=0;i<m && pr[i]*pr[i]<=b;i++)
			if(b%pr[i]==0)
			{
				b/=pr[i];
				p=pr[i];
			}
		if(b>1)
			p=b;
		ans=0;
		for(i=p;i<=n;i*=p)
		{
			c=n/i;
			ans+=((c-1)*c*i/2);
			ans+=((n/i)*(n-c*i+1));
		}
		printf("%lld\n",ans);
	}
	return 0;
}













