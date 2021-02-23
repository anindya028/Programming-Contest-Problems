//Coin Change DP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	
//#define Long __int64
#define Long long long

Long ways[305][1005];

int main()
{
	int n,low,high,bs,dbs;
	register int i,j;
	char s[1000];
	for(i=0;i<=300;i++)
		ways[i][0]=0;
	for(i=0;i<=1000;i++)	
		ways[0][i]=1;
	ways[0][0]=1;
	for(i=1;i<=300;i++)
		for(j=1;j<=1000;j++)
		{
			if((i-j)>=0)
				ways[i][j]=ways[i-j][j]+ways[i][j-1];
			else
				ways[i][j]=ways[i][j-1];
		}
	while(gets(s))
	{
		bs=0;
		sscanf(s+bs,"%d%n",&n,&dbs);
		bs+=dbs;
		if(sscanf(s+bs,"%d%n",&low,&dbs)==1)
		{
			bs+=dbs;
			if(sscanf(s+bs,"%d%n",&high,&dbs)==1)
			{
				if(!low)
					printf("%lld\n",ways[n][high]);
				else
					printf("%lld\n",ways[n][high]-ways[n][low-1]);
			}
			else
				printf("%lld\n",ways[n][low]);
		}
		else
			printf("%lld\n",ways[n][1000]);
	}
	return 0;
}
