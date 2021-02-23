
/*typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[5000];
prime p[size];
long gene(long n)
{
	int root=ceil(sqrt(n));
        long i,j;
	for(i=3;i<=root;i+=2)
	{
		if(!p[i/2].m)
		{
			for(j=i*i;j<n+1;j+=(2*i))p[j/2].m=1;
		}
	}
	j=1;
	pr[0]=2;
	for(i=1;i<n/2;i++)
	{
		if(!p[i].m)
                {
			pr[j]=i*2+1;
			j++;
                }
	}
        return j;
}
long n,c,fact[5000],temp,k,count,i,m,l,*nfact,*mfact;
long max(long a,long b)
{
	return a>b?a:b;
}
int lcm(void)
{
	long a,b=fact[i],d=fact[l],e,f;
	nfact=(long *)calloc(m,sizeof(long));
	mfact=(long *)calloc(m,sizeof(long));
	for(a=0;a<m&&b>1;a++)
	{
		//if(pr[a]*pr[a]>b)break;
		while(b%pr[a]==0)
		{
			nfact[a]++;
			b/=pr[a];
		}
	}
        f=a;
	for(a=0;a<m&&d>1;a++)
	{
		//if(pr[a]*pr[a]>d)break;
		while(d%pr[a]==0)
		{
			nfact[a]++;
			d/=pr[a];
		}
	}
        if(a>f)f=a;
	e=1;
	for(a=0;a<f;a++)e*=(long)pow(pr[a],max(nfact[a],mfact[a]));
	free(nfact);
	free(mfact);
	if(e==n)return 1;
	else return 0;
}
void main()
{
	m=gene(45000);
	while(scanf("%ld",&n)==1)
        {
		if(!n)break;
		if(n==1)
		{
			printf("1 1\n");
			continue;
		}
		if(n==2)
		{
			printf("2 2\n");
			continue;
		}
		for(i=2,count=0;i*i<=n;i++)
		{
			if(n%i==0)
			{
				if(i!=(n/i))
                                {
					fact[count]=i;
					fact[count+1]=n/i;
					count+=2;
				}
				else
				{
					fact[count]=i;
					count++;
				}
			}
		}
		if(!count)
		{
			printf("%ld 2\n",n);
                        continue;
		}
		c=count+2;
		for(i=0;i<(count-1);i++)
			for(l=i+1;l<count;l++)
				if(lcm())c++; 
		printf("%ld %ld\n",n,c);
        }
}*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
long N;
long gcd(long m,long n)
{
	if(!m)return n;
	return gcd((n%m),m);
}
bool lcm(long a,long b)
{
	if((a*(b/gcd(a,b)))==N)return true;
	else return false;
}
int main()
{
	long *fact,c,i,j,count;
	while(scanf("%ld",&N)==1)
	{
		if(!N)break;
		if(N==1)
		{
			printf("1 1\n");
			continue;
		}
		if(N==2)
		{
			printf("2 2\n");
			continue;
		}
                fact=(long *)calloc(10000,sizeof(long));
		for(i=2,count=0;i*i<=N;i++)
		{
			if(N%i==0)
			{
				if(i!=(N/i))
                                {
					fact[count]=i;
					fact[count+1]=N/i;
					count+=2;
				}
				else
				{
					fact[count]=i;
					count++;
				}
			}
		}
		if(!count)
		{
			printf("%ld 2\n",N);
                        continue;
		}
		c=count+2;
		for(i=0;i<count-1;i++)
			for(j=i+1;j<count;j++)
				if(lcm(fact[i],fact[j]))c++;
		printf("%ld %ld\n",N,c);
	}
	return 0;
}













