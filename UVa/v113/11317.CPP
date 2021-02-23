//Very good Number Theory,Thanks to S.M.!!
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;
//#define Long __int64
#define Long long long
#define eps 1e-8
#define size 500010
int pr[80000];
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
	Long *gcdf,*lcmf,i,j,n,temp;
	int m=gene(size*2),cs=0;
	double dg,dl;
	while(scanf("%lld",&n)==1 && n)
	{
		gcdf=(Long *)calloc(m,sizeof(Long));
		lcmf=(Long *)calloc(m,sizeof(Long));
		for(i=dg=0;i<m && pr[i]<=(n/2);i++)
		{
			for(j=pr[i];j<n;j*=pr[i])
				gcdf[i]+=((n/j)*((n/j)-1))/2;
			dg+=(log10((double)pr[i])*gcdf[i])/100.;
		}
		for(i=dl=0;i<m && pr[i]<=n;i++)
		{
			temp=n;
			while(temp)
				lcmf[i]+=temp/=pr[i];
			lcmf[i]*=(n-1);
			lcmf[i]-=gcdf[i];
			dl+=(log10((double)pr[i])*lcmf[i])/100.;
		}
		printf("Case %d: %.0lf %.0lf\n",++cs,floor(dg+eps)+1.,floor(dl+eps)+1.);
		free(gcdf);
		free(lcmf);
	}
	return 0;
}

