#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,m,k,*a,i,j,countm,countk,killed,*ansk,*ansm,x,y,posk,posm;
	while(scanf("%d%d%d",&n,&k,&m)==3)
	{
		if(!n)break;
		a=(int *)calloc(n,sizeof(int));
		ansk=(int *)calloc(n,sizeof(int));
		ansm=(int *)calloc(n,sizeof(int));
		for(killed=x=y=j=0,i=n-1;;)
		{
			for(countk=0;;j=(j+1)%n)
			{
				if(!a[j])countk++;
				if(countk==k)
				{
					posk=j;
					ansk[x++]=j+1;
					countk=0;
					break;		
				}
			}
			for(countm=0;;i=(i-1+n)%n)
			{
				if(!a[i])countm++;
				if(countm==m)
				{
					posm=i;
					ansm[y++]=i+1;
					countm=0;
					break;
				}
			}
			a[posk]=a[posm]=1;
			if(posk==posm)killed++;
			else killed+=2;
			if(killed==n)break;
		}
		for(i=0;i<(x<y?x:y);i++)
		{
			if(i)printf(",");
			if(ansk[i]!=ansm[i])printf("%3d%3d",ansk[i],ansm[i]);
			else printf("%3d",ansk[i]);
		}
		if(x<y)
		{
			for(;i<y;i++)
				printf(",%3d",ansm[i]);
		}
		else
		{
			for(;i<x;i++)
				printf(",%3d",ansk[i]);
		}
		printf("\n");
		free(a);
		free(ansk);
		free(ansm);
	}
	return 0;
}













