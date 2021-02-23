//Awesome Number theory
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;
//#define Long  __int64
#define Long long long
#define size 5005
int pr[2000];
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
	int m=gene(size*2);
	Long n,b,i,j,s,*freq,temp,ans,f;
	while(scanf("%lld%lld",&n,&b)==2 && n && b)
	{
		temp=b;
		freq=(Long *)calloc(m,sizeof(Long));
		for(i=0;pr[i]<=temp && i<m;i++)
		{
			while(temp%pr[i]==0)
			{
				temp/=pr[i];
				freq[i]++;
			}
		}
		f=0;
		for(j=0;pr[j]<=b;j++)
		{
			if(!freq[j])
				continue;
			ans=0;
			for(i=pr[j];i<=n;i*=pr[j])
			{
				s=n/i;
				ans+=((n*(n+1)/2)+n+1)*s;
				ans+=(i*i*(s*(s+1)*(2*s+1)/6) - (2*n+3)*i*(s*(s+1)/2))/2;
			}
			ans/=freq[j];
			if(!f)
				f=ans;
			else if(ans<f)
				f=ans;
		}
		printf("%lld\n",f);
		free(freq);
	}
	return 0;
}
//166662438307705929
