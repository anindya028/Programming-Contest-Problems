#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 32000
struct prime
{
	unsigned m:1;
};
long pr[3436];
prime p[16000];
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
	int m=gene(size);
	int a[162],b[162],c[162],d[162],flag[162],low,high,i,j,temp,printed;
	for(i=1,j=0;i<(m-4);)
	{
		if(((pr[i+3]-pr[i+2])==(pr[i+2]-pr[i+1]))&&((pr[i+2]-pr[i+1])==(pr[i+1]-pr[i])))
		{
			a[j]=pr[i];
			b[j]=pr[i+1];
			c[j]=pr[i+2];
			d[j]=pr[i+3];
			flag[j]=4;
                        j++;
			i+=3;
		}
		else if((pr[i+2]-pr[i+1])==(pr[i+1]-pr[i]))
		{
			a[j]=pr[i];
			b[j]=pr[i+1];
			c[j]=pr[i+2];
                        d[j]=pr[i+2];
			flag[j]=3;
			j++;
			i+=2;
		}
		else i++;
	}
	while(scanf("%d%d",&low,&high)==2)
	{
        	if((!low)&&(!high))break;
			if(low>high)
			{
				temp=low;
				low=high;
				high=temp;
			}
		for(i=printed=0;a[i]<low;i++);
		for(;i<j;i++)
		{
			if(d[i]>high)break;
			if(flag[i]==4)printf("%d %d %d %d\n",a[i],b[i],c[i],d[i]);
			else printf("%d %d %d\n",a[i],b[i],c[i]);
		}
	}

}













