#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define size 31000
int main()
{
	int n,r,*freq,num,*sor,i,j,k,l,sum;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&r);
                        sum=0;
			freq=(int *)calloc(size,sizeof(int));
                        sor=(int *)calloc(r,sizeof(int));
			for(j=0;j<r;j++)
			{
				scanf("%d",&num);
				freq[num]++;
			}
			for(j=k=0;k<r;j++)
			{
				for(l=0;l<freq[j];l++)
				{
					sor[k]=j;
					k++;
				}
			}
			if(r%2)
			{
				for(j=0;j<r;j++)sum+=abs(sor[j]-sor[(r-1)/2]);
				printf("%d\n",sum);
			}
			else
			{
				for(j=0;j<r;j++)sum+=abs(sor[j]-sor[r/2-1]);
				printf("%d\n",sum);
			}
			free(freq);
			free(sor);
		}
	}
	return 0;
}













