#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int x,i,j,k,l,m,n,cs=0;
	int *num;
	while(scanf("%d",&x)==1 && x)
	{
		if(cs)printf("\n");
        	num=(int *)calloc(n,sizeof(int));
		for(i=0;i<x;i++)scanf("%d",&num[i]);
		for(i=0;i<x-5;i++)
		{
			for(j=i+1;j<x-4;j++)
			{
				for(k=j+1;k<x-3;k++)
				{
					for(l=k+1;l<x-2;l++)
					{
						for(m=l+1;m<x-1;m++)
						{
							for(n=m+1;n<x;n++)
							{
								printf("%d %d %d %d %d %d\n",num[i],num[j],num[k],num[l],num[m],num[n]);
							}
						}
					}
				}
			}
		}
                free(num);
		cs++;
        }
	return 0;
}













