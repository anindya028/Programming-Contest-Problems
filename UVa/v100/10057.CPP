#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 65600
//#define Long long long

int main()
{
	long n,num,*freq,*sing,i,j,k;
	while(scanf("%ld",&n)==1)
	{
		freq=(long *)calloc(size,sizeof(long));
		sing=(long *)calloc(n,sizeof(long));	
	        for(i=0;i<n;i++)
	        {
			scanf("%ld",&num);
			freq[num]++;
	       	}
	       	for(i=j=0;j<n;i++)
	       	{
			for(k=0;k<freq[i];k++)
                        {
				sing[j]=i;
				j++;
			}
	       	}
	       	if(n%2)
	       	{
			printf("%ld %ld 1\n",sing[(n-1)/2],freq[sing[(n-1)/2]]);
	       	}
	       	else
	       	{
			if(sing[n/2]==sing[n/2-1])printf("%ld %ld 1\n",sing[n/2-1],freq[sing[n/2-1]]);
			else printf("%ld %ld %ld\n",sing[n/2-1],freq[sing[n/2]]+freq[sing[n/2-1]],sing[n/2]-sing[n/2-1]+1);
	       	}
		free(freq);
		free(sing);
        }
	return 0;
}