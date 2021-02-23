#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

//#define Long __int64
#define Long long long
#define size 100000
int pr[320000];
bool p[size];
int gene(int n)
{
	int root=ceil(sqrt(n));
    int i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2])
		{
			for(j=i*i;j<n+1;j+=(2*i))
				p[j/2]=1;
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

int phi[size*2+5];
Long ans[size*2+5];

int main()
{
	int m=gene(size*2);
	int k,n,f,t1,t2;
	ans[1]=0;
	ans[2]=1;
	phi[2]=1;
	register int i,j;
	for(i=3;i<=2*size;++i)
	{
		if(!p[(i-1)/2] && (i%2))
		{
			phi[i]=i-1;
			ans[i]=ans[i-1]+phi[i];
			continue;
		}
		f=0;
		ans[i]=ans[i-1];
		for(j=2;j*j<=i;++j)
			if(!(i%j))
			{
				k=i/j;
				if(k==j)
					ans[i]+=j*phi[k];
				else
					ans[i]+=(j*phi[k]+k*phi[j]);
				if(!f)
				{
					f=1;
					t1=k;
					t2=j;
					while(t1%j==0)
					{
						t2*=j;
						t1/=j;
					}
					if(t1!=1)
						phi[i]=phi[t1]*phi[t2];
					else
						phi[i]=(j-1)*(i/j);
					ans[i]+=phi[i];
					if(((!p[(j-1)/2] && (j%2)) || j==2) && (!p[(k-1)/2] && (k%2)))
						break;
				}
			}
	}
	while(scanf("%d",&n)==1 && n)
		printf("%lld\n",ans[n]);
	return 0;
}
