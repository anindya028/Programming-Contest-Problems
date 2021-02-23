#include<stdio.h>
#include<math.h>
long double n,p,ans; 
long d;
void main()
{
	while(scanf("%Lf%Lf",&n,&p)==2)
	{
		if(p>=0)ans=pow(10,(log10(p)/n));
		d=ans;
                if((ans-d)>=.5)d+=1;
		printf("%ld\n",d);
	}
}













