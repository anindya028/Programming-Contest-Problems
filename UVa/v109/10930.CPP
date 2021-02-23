
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int num[35],*flag,n,i,j,max,a,cs=0;
	while(scanf("%d",&n)==1)
	{
		flag=(int *)calloc(30000,sizeof(int));
		a=1;
		max=0;
		printf("Case #%d:",++cs);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			printf(" %d",num[i]);
			if(!i)
			{
				max=num[i];
				flag[num[i]]++;
			}
			else
			{
				if(a)
				{
					for(j=0;j<i;j++)
					{
						if(num[j]>=num[i])
						{
							a=0;
							break;
						}
					}
					if(flag[num[i]])a=0;
					for(j=max;j>=0;j--)
					{
						if(j==max)max+=num[i];
						if(flag[j])flag[j+num[i]]++;
					}
					flag[num[i]]++;
				}
			}
		}
		printf("\n");
		if(a)printf("This is an A-sequence.\n");
		else printf("This is not an A-sequence.\n");
	}
	return 0;
}











