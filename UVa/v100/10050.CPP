#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int *day,t,i,j,num,p,hart,count,k;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&num);
		day=(int *)calloc(num+1,sizeof(int));
		scanf("%d",&p);
		for(j=0;j<p;j++)
		{
			scanf("%d",&hart);
			for(k=hart;k<=num;k+=hart)day[k]=1;
		}
		for(j=count=0;j<=num;j++)
		{
			if(j%7==0 || j%7==6)continue;
			if(day[j])count++;
		}
		printf("%d\n",count);
		free(day);
        }
	return 0;
}













