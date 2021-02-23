#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

#define SIZE 100000

using namespace std;

int memo[45][SIZE],amount,N,coins[45];
int total,votes[45];

int knapsack(int left)
{
	int i,j;	
	
	for(i=0;i<N;i++)
		for(j=0;j<=amount;j++)
			memo[i][j]=0;

	for(i=0;i<N;i++)
		memo[i][0]=1;

	memo[0][coins[0]]=1;

	for(i=1;i<N;i++)
	{
		for(j=0;j<=amount;j++)memo[i][j]=memo[i-1][j];

		for(j=0;(coins[i]+j)<=amount;j++)
		{
			memo[i][coins[i]+j] =  memo[i-1][coins[i]+j] + memo[i-1][j];
		}
	}

	int sum=0;
	for(i=amount-1;i>=(amount-votes[left]);i--)
	{
		sum+=memo[N-1][i];
	}
	return sum;
}

int main(void)
{
	int i,j,bs,dbs;
	char s[100];
	while(gets(s))
	{
		bs=dbs=0;
		sscanf(s+bs,"%d%n",&amount,&dbs);
		bs+=dbs;
		i=0;
		while(sscanf(s+bs,"%d%n",&votes[i],&dbs)==1)
		{
			bs+=dbs;
			i++;
			/*scanf("%d%c",&votes[i],&c);
			i++;
			if(c!=' ')
				break;*/
		}
		N=i-1;
		total=i;
		int index;
		for(i=0;i<total;)
		{
			index=0;
			for(j=0;j<total;j++)if(j!=i)
			{
				coins[index++]=votes[j];				
			}
			printf("%d",knapsack(i));
			i++;
			if(i<total)
				printf(" ");
		}
		printf("\n");


	}
	return 0;
}