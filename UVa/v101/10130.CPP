#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct taken
{
	int price;
	int weight;
}*tak;
int  main()
{
	int t,i,j,k,n,p[1005],w[1005],m,f[1000],sum,max;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d%d",&p[j],&w[j]);
		scanf("%d",&m);
		for(j=0;j<m;j++)
			scanf("%d",&f[j]);
		tak=(taken *)calloc(50,sizeof(taken));
		tak[0].weight=1;
		for(j=0;j<n;j++)
		{
			for(k=30;k>=0;k--)
			{
				if(tak[k].weight)
				{
					if((k+w[j])<=30)
					{
						if(tak[k+w[j]].price<(tak[k].price+p[j]))
						{
							tak[k+w[j]].weight=1;
							tak[k+w[j]].price=tak[k].price+p[j];
						}
					}
				}
			}
		}
		for(j=sum=0;j<m;j++)
		{
			for(k=30,max=0;k;k--)
			{
				if(k<=f[j] && tak[k].price>max)
					max=tak[k].price;
			}
			sum+=max;
		}
		printf("%d\n",sum);
		free(tak);
	}
	return 0;
}













