//Simulation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

int r,c,flag;
char s[10][10];
char k[9];

void print(int i,int j,int d)
{
	if(s[i][j]=='@')
	{
		flag=1;
		return;
	}
	if((j+1)<c)
	{
		if(s[i][j+1]==k[d])
		{
			print(i,j+1,d+1);
			if(flag)
			{
				if(s[i][j+1]=='@')
					printf("left");
				else
					printf(" left");
				return;
			}
		}
	}
	if((j-1)>=0)
	{
		if(s[i][j-1]==k[d])
			print(i,j-1,d+1);
		if(flag)
		{
			if(s[i][j-1]=='@')
				printf("right");
			else 
				printf(" right");
			return;
		}
	}
	if((i+1)<r)
	{
		if(s[i+1][j]==k[d])
			print(i+1,j,d+1);
		if(flag)
		{
			if(s[i+1][j]=='@')
				printf("forth");
			else 
				printf(" forth");
			return;
		}
	}
}

int main()
{
	int t,i;
	strcpy(k,"AVOHEI@");
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
			scanf("%s",s[i]);
		for(i=flag=0;i<c;i++)
			if(s[0][i]=='#')
				print(0,i,0);
		printf("\n");
	}
	return 0;
}
