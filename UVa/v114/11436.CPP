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
#define Min(a,b) (((a)<(b))?(a):(b))  
#define size 15000
int pr[10000];
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

int x,y;

void check(Long m,Long k)
{
	int t;
	double det=sqrt(9*k*k-12*(k*k-m));
	Long d=(Long)floor(det+1e-8);
	if( (d*d)==(9*k*k-12*(k*k-m)) )
	{
		t=(-3*k+sqrt(9*k*k-12*(k*k-m)))/6.;
		if(t<y && t>0)
			y=t,x=y+k;
	}
}

int main()
{
	int m=gene(size*2);
	int j,add;
	register int i;
	Long n,temp;
	while(scanf("%lld",&n)==1 && n)
	{
		x=y=1000000000;
		check(n,1);
		for(i=0;i<m;i++)
			if(n%pr[i]==0)
			{
				temp=n/pr[i];
				check(temp,pr[i]);
				if(!i)
					add=2;
				else 
					add=2*pr[i];
				for(j=pr[i]*pr[i];j<30000 && j<n;j+=add)
					if(n%j==0)
					{
						temp=n/j;
						check(temp,j);
					}
			}
		if(x<1000000000)
			printf("%d %d\n",x,y);
		else
			printf("No solution\n");
	}
	return 0;
}
