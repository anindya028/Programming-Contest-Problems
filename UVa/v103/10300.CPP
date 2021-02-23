//Adhoc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define size 100
typedef unsigned long int myint;
void main()
{
	int n,i=0,f;
	scanf("%d",&n);
        myint premium[size],p,s,garb,j;
	for(;i<n;i++)
	{
		scanf("%d",&f);
                premium[i]=0;
		for(j=0;j<f;j++)
		{
			scanf("%lu%lu%lu",&p,&garb,&s);
			premium[i]+=(p*s);
		}
        }
	for(i=0;i<n;i++)printf("%lu\n",premium[i]);


}













