#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int low,high,dif,t,i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
        {
		scanf("%d%d",&low,&high);
		dif=high-low;
		if(!dif)
		{
			printf("0\n");
			continue;
		}
		else if(dif==1)
		{
			printf("1\n");
			continue;
		}
		for(j=1;;j++)
		{
			dif-=2*j;
			if(dif<=0)
			{
				printf("%d\n",2*j);
                                break;
			}
			else if(dif<=j)
			{
				printf("%d\n",2*j+1);
				break;
                        }
			else if(dif==(j+1))
			{
				printf("%d\n",2*j+1);
				break;
			}
			else if(dif<=(2*j))
			{
				printf("%d\n",2*j+2);
				break;
			}
		}
	}
	return 0;
}













