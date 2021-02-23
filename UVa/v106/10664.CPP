#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int *tak,i,j,k,n,m,sum,dif,bs,db,num[30];
	char buf[10000];
	scanf("%d\n",&n);
	for(k=0;k<n;k++)
	{
		gets(buf);
		bs=db=i=sum=0;
		while(sscanf(buf+bs,"%d%n",&num[i],&db)==1)
		{
			sum+=num[i];
			i++;
			bs+=db;
		}
		m=i;
		if(sum%2)
		{
			printf("NO\n");
			continue;
		}
		tak=(int *)calloc(sum/2+1,sizeof(int));
		tak[0]=1;
		dif=sum;
		for(i=0;i<m && dif;i++)
		{
			for(j=sum/2;j>=0 && dif;j--)
			{
				if(tak[j])
				{
					if((j+num[i])<=sum/2)
					{
						tak[j+num[i]]=1;
						if((sum-2*(j+num[i]))==0)
							dif=0;
					}
				}
			}
		}
		if(!dif)printf("YES\n");
		else printf("NO\n");
		free(tak);
	}
	return 0;
}













