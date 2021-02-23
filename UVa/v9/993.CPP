#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j,count,cs;
	int num[100];
	scanf("%d",&cs);
	for(i=0;i<cs;i++)
	{
		scanf("%d",&n);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		count=0;
		j=9;
		while(j>1)
		{
			if(n==1)break;
			while(n%j==0)
			{
				n/=j;
				num[count]=j;
				count++;
			}
			j--;
		}
		if(!count || n!=1)
		{
			printf("-1\n");
			continue;
		}
		for(j=count-1;j>=0;j--)
			printf("%d",num[j]);
		printf("\n");
	}
	return 0;
}













