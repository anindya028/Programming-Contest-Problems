#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
struct prime
{
	unsigned m:1;
};
long pr[25];
prime p[50];
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
void main()
{
	long lim=gene(size);
	int m,n,num,*mfact,j,k,min,temp,count,i;
        scanf("%d",&num);
	for(j=0;j<num;j++)
	{
		scanf("%d%d",&m,&n);
		mfact=(int *)calloc(25,sizeof(int));
		min=0;
		for(k=0;(m!=1)&&(k<25);k++)
		{
			while(m%pr[k]==0)
			{
				mfact[k]++;
				m/=pr[k];
			}
		}
		for(i=0;i<k;i++)
		{
			if(!mfact[i])continue;
			temp=n;
			count=0;
			while(temp)
			{
				count+=temp/=pr[i];
			}
                        count/=mfact[i];
			if(!min)min=count;
			else if(count<min)min=count;
		}
		if(m>1)
		{
			count=0;
			while(n)
			{
				count+=n/=m;
			}
			if(count<min||!min)min=count;
                }
		if(!min)printf("Case %d:\nImpossible to divide\n",j+1);
		else printf("Case %d:\n%d\n",j+1,min);
                free(mfact);
        }
}













