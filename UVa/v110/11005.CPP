//Base Convertion
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int cost[36];
int base[40];
void convert(int num,int b)
{
	if(!num)
	{
		base[b]=cost[0];
		return;
	}
	while(num)
	{
		base[b]+=cost[num%b];
		num/=b;
	}
	return;
}
int main()
{
	int cs,i,j,k,q,num,min;
	scanf("%d",&cs);
	for(i=0;i<cs;i++)
	{
		if(i)printf("\n");
		for(j=0;j<36;j++)
		{
			scanf("%d",&cost[j]);
		}
		printf("Case %d:\n",i+1);
		scanf("%d",&q);
		for(j=0;j<q;j++)
		{
			scanf("%d",&num);
			min=21000000;
			for(k=2;k<40;k++)base[k]=0;
			for(k=2;k<=36;k++)
			{
				convert(num,k);
				if(base[k]<min)min=base[k];
			}
			printf("Cheapest base(s) for number %d:",num);
			for(k=2;k<=36;k++)
			{
				if(base[k]==min)printf(" %d",k);
			}
			printf("\n");
		}
	}
	return 0;
}













