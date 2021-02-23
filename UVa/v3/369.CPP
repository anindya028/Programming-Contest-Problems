#include<stdio.h>
long double n,k,num,m,sum,c; 
void main()
{ 
	while(1)
	{ 
		scanf("%Lf %Lf",&n,&k);
		num=n;
		m=k; 
		if(n==0) break; 
		if(k>n/2) k=n-k;
		for(sum=1,c=k;c>0;c--,n--) sum*=n; 
		for(;k>1;k--) sum/=k; 
		printf("%.0Lf things taken %.0Lf at a time is %.0Lf exactly.\n",num,m,sum);
			 
		 
	}
}














