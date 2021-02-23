#include<stdio.h>                            
#include<math.h>
long i;
long long temp,m;
void main()
{
	for(;;i++)
	{
		scanf("%lld",&m);
                if(m<0)break;
		temp=m*(m+1)/2+1;
		printf("%lld\n",temp);
	}

      	
}













