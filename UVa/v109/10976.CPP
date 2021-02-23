#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct pair
{
	int x,y;
}p[1000];
int main()
{
	int k,i,j;
	while(scanf("%d",&k)==1)
	{
		j=0;
		for(i=k+1;i<=2*k;i++)
		{
			if((k*i)%(i-k)==0)
			{
				p[j].x=(k*i)/(i-k);
				p[j].y=i;
				j++;
			}
		}
		printf("%d\n",j);
		for(i=0;i<j;i++)
			printf("1/%d = 1/%d + 1/%d\n",k,p[i].x,p[i].y);
	}
	return 0;
}













