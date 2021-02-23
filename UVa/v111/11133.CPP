//DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int eigen[44][45],i,j,k;
	for(i=0;i<44;i++)
	{
		eigen[i][i]=eigen[i][i+1]=1; 
		for(j=i+2;j<45;j++)
		{
			eigen[i][j]=eigen[i][j-1];
			for(k=2;k<=(j-i);k++)
				if(j%k==0)
					eigen[i][j]+=eigen[i][j-k];
		}
	}
	while(scanf("%d%d",&i,&j)==2)
	{
		if(i>=j)break;
		printf("%d %d %d\n",i,j,eigen[i][j]);
	}
	return 0;
}













