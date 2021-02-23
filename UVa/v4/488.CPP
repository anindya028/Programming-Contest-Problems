#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char num[][11]={"1","22","333","4444","55555","666666","7777777","88888888","999999999"};
	int a,f,n,i,j,k;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			if(i)printf("\n");
			scanf("%d%d",&a,&f);
			for(j=0;j<f;j++)
			{
                        	if(j)printf("\n");
				for(k=0;k<a;k++)
				{
					printf("%s\n",num[k]);
				}
				for(k-=2;k>=0;k--)
				{
					printf("%s\n",num[k]);
				}
			}
		}
	}
	return 0;
}













