#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 1000000
bool prime[size+1];
long pr[80000];
long segmented_sieve(long int low,long int high)
{
	long int i,j,d,temp,t;

	d=high-low+1;
	for(i=0;i<d;i++)
		prime[i]=1;

	if(low%2)
		i=1;
	else
		i=0;
	for(;i<d;i+=2)
		prime[i]=0;

	temp=sqrt(high)+1;
	for(i=3;i<temp;i+=2)
	{
		if(i>=low)
			if(!prime[i-low])
				continue;

		t=(i/low)*i;
		if(i<low)
			t+=i;
		if(t==i)
			t+=i;
		t-=low;
		if(t<0)
			for(j=t+i*(low/i-2);j<0;j+=i);
		else j=t;
		if(j%2==0 && low%2==0)j+=i;
		if(j%2 && low%2) j+=i;
		for(;j<d;j+=2*i)
			prime[j]=0;
	}

	if(low<=1)
		prime[1-low]=0;
	if(low<=2)
		prime[2-low]=1;
	for(i=j=0;i<d;i++)
	{
		if(prime[i])
		{
			pr[j]=i+low;
			j++;
		}
	}
	return j;
}
int main()
{
	long l,u,c1,c2,d1,d2,i,min,max,num,dif;
	while(scanf("%ld%ld",&l,&u)==2)
	{
		num=segmented_sieve(l,u);
		if(num<=1)
		{
			printf("There are no adjacent primes.\n");
			continue;
                }
		c1=d1=pr[0];
                c2=d2=pr[1];
		min=c2-c1;
                max=d2-d1;
		for(i=2;i<num;i++)
		{
			dif=pr[i]-pr[i-1];
			if(dif<min)
			{
				c1=pr[i-1];
				c2=pr[i];
				min=dif;
			}
			if(dif>max)
			{
				d1=pr[i-1];
				d2=pr[i];
				max=dif;
			}
        }
		printf("%ld,%ld are closest, %ld,%ld are most distant.\n",c1,c2,d1,d2);
	}
	return 0;
}













