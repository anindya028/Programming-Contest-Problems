//Number Theory
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
long gcd(long m,long n)
{
	if(!m)return n;
	return gcd((n%m),m);
}
long a[1001],i,max,garb,dif[1000];
void main ()
{
	while(scanf("%ld",&garb)==1)
	{
		if(!garb)break;
		a[0]=garb;
		for(i=1;;i++)
		{
			scanf("%ld",&a[i]);
			if(i==1)
			{
				if(abs(a[1])==abs(a[0]))max=abs(a[0]);
				else max=abs(a[1]-a[0]);

                        }
			if(!a[i])
			{
				break;
			}
			dif[i-1]=abs(a[i]-a[i-1]);
			if(i==2)
			{
				if(max==abs(a[i])&&max==abs(a[i-1]))max=gcd(max,dif[i-1]);
				else max=gcd(dif[i-1],dif[i-2]);
                        }
                        else if(i>2)max=gcd(max,dif[i-1]);
		}
		dif[i-1]=abs(a[i-1]-a[0]);
		max=gcd(max,dif[i-1]);
		printf("%ld\n",max);
	}       

}


