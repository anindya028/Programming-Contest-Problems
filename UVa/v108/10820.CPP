#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 230
struct prime
{
	unsigned m:1;
};
long pr[60],lim,sop[50001];
prime p[size/2];
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
void gener(void)
{
	long i,j,temp,power,root;
        double phi;
	sop[1]=1;
        sop[2]=3;
	for(i=3;i<50001;i++)
	{
		phi=temp=i;
		root=floor(sqrt(i))+1;
		for(j=0;(temp!=1)&&(j<lim);j++)
		{
                	if(pr[j]>root)break;
			power=0;
			while(temp%pr[j]==0)
			{
				power++;
				temp/=pr[j];
			}
			if(power)
			{
				phi*=(pr[j]-1);
				phi/=pr[j];
			}
		}
		if(temp>1)
		{
			phi*=(temp-1);
			phi/=temp;
		}
		sop[i]=sop[i-1]+2*(long)phi;
	}
}
int main()
{
	lim=gene(size);
	gener();
	long n;
	while(scanf("%ld",&n)==1)
	{
		if(!n)break;
		printf("%ld\n",sop[n]);
    }
	return 0;
}













