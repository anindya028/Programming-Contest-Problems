#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
struct dict
{
	char w[25];
	int value;
}d[1005];
int main()
{
	int m,n,i,sum,j,k;
        char temp[30];
	while(scanf("%d%d",&m,&n)==2)
	{
		for(i=0;i<m;i++)scanf("%s%d",d[i].w,&d[i].value);
		for(i=0;i<n;i++)
		{
			for(j=sum=0;;j++)
			{
				scanf("%s",temp);
				if(temp[0]=='.')break;
				for(k=0;k<m;k++)
				{
					if(!strcmp(d[k].w,temp))
					{
						sum+=d[k].value;
						break;
					}
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}













