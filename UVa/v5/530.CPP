










#include<stdio.h>
long double n,k,sum,c; 
int main()
{
	while(1)
	{
		scanf("%Lf %Lf",&n,&k);
		if(n==0) break;
		if(k>n/2) k=n-k;
		if(k<2)
		{
			if(k==0) printf("1\n");
			else printf("%.0Lf\n",n);
		}
		else
		{
			if(n<2) printf("1\n");
			else
			{
				for(sum=1,c=k;c>0;c--,n--) sum*=n;
				for(;k>1;k--) sum/=k;
				printf("%.0Lf\n",sum);
			}
		}
	}
	return 0;
}


