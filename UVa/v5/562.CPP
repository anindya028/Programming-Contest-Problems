#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int k,n,num[101],sum,i,j,*tak,dif,m;
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		scanf("%d",&m);
		for(i=sum=0;i<m;i++)
		{
			scanf("%d",&num[i]);
			sum+=num[i];
		}
		tak=(int *)calloc((sum/2+1),sizeof(int));
		tak[0]=1;
		dif=sum;
		for(i=0;i<m;i++)
		{
			for(j=sum/2;j>=0;j--)
			{
				if(tak[j])
				{
					if((j+num[i])<=(sum/2))
					{
						tak[j+num[i]]=1;
						if((sum-2*(j+num[i]))<dif)
							dif=sum-2*(j+num[i]);
					}
				}
			}
		}
		printf("%d\n",dif);
		free(tak);
	}
	return 0;
}













