#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100005
//#define myint unsigned __int64
#define myint unsigned long long
bool prime[size+1];
unsigned long pr[10000];
myint bigmod(myint b,myint p,myint m)
{
   myint a; 
   if (p == 0) 
      return 1; 
   if (p%2 == 0)
   { 
      a = bigmod(b,p/2,m); 
      return ((a%m)*(a%m)) % m; 
   }
   else
   { 
      return ((b % m) * bigmod(b,p-1,m)) % m; 
   } 
}
bool suspect(myint b,myint n)
{
	long long t=0,x[70],u=n-1;
	register myint i;
	while(u%2==0)
	{
		t++;
		u/=2;
	}
	//x=(long long *)calloc(t+1,sizeof(long long));
	x[0]=bigmod(b,u,n);
	for(i=1;i<=t;i++)
	{
		x[i]=((x[i-1]%n)*(x[i-1]%n))%n;
		if(x[i]==1 && x[i-1]!=1 && x[i-1]!=(n-1))
			return false;
	}
	if(x[t]==1)
		return true;
	else
		return false;
}
myint segmented_sieve(unsigned long low,unsigned long high)
{
	long long d,t;
	register long long i,j;
	d=high-low+1;
	for(i=0;i<d;i++)
		prime[i]=1;

	if(low%2)
		i=1;
	else
		i=0;
	for(;i<d;i+=2)
		prime[i]=0;

	for(i=3;i*i<=high;i+=2)
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
	unsigned long base,low,high,count,m,failure[10000],cs=0;
	register myint i,j;
	while(scanf("%lu%lu%lu",&base,&low,&high)==3)
	{
		if(!base)break;
		if(cs)printf("\n");
		cs++;
		if((low-high)>10000000)
		{
			m=segmented_sieve(low,high);
			if(low%2==0)
			{
				if(high%2==0)count=(high-low)/2-m;
				else count=(high-low-1)/2+1-m;
			}
			else
			{
				if(high%2==0)count=(high-1-low)/2+1-m;
				else count=(high-low)/2+1-m;
			}
			printf("There are %lu odd non-prime numbers between %lu and %lu.\n",count,low,high);
			for(j=0,i=(low%2)?low:low+1;i<=high;i+=2)
			{
				if(suspect(base,i) && !prime[i-low])failure[j++]=i;
			}
			if(!j)printf("There are no failures in base %lu.\n",base);
			else
			{
				printf("%llu suspects fail in base %lu:\n",j,base);
				for(i=0;i<j;i++)
				{
					printf("%lu\n",failure[i]);
				}
			}
		}
		else
		{
			for(j=count=0,i=(low%2)?low:low+1;i<=high;i+=2)
			{
				m=0;
				if(suspect(2,i))
				{
					if(suspect(7,i))
					{
						if(suspect(61,i))
						{
							m=1;
							count++;
						}
					}
				}
				if(!m && suspect(base,i))failure[j++]=i;
			}
			if(low%2==0)
			{
				if(high%2==0)count=(high-low)/2-count;
				else count=(high-low-1)/2+1-count;
			}
			else
			{
				if(high%2==0)count=(high-1-low)/2+1-count;
				else count=(high-low)/2+1-count;
			}
			printf("There are %lu odd non-prime numbers between %lu and %lu.\n",count,low,high);
			if(!j)printf("There are no failures in base %lu.\n",base);
			else
			{
				printf("%llu suspects fail in base %lu:\n",j,base);
				for(i=0;i<j;i++)
				{
					printf("%lu\n",failure[i]);
				}
			}
		}
	}
	return 0;
}













