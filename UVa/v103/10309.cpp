//============================================================================
// Name        : 10309.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

char s[15][15];
int mat[15][15],temp[15][15];

int main() {
	int i,j,k;
	char cs[105];
	while(scanf("%s",cs)==1)
	{
		if(!strcmp(cs,"end"))
			break;
		for(i=0;i<10;i++)
		{
			scanf("%s",s[i]);
			for(j=0;j<10;j++)
				if(s[i][j]=='O')
					mat[i][j]=1;
				else
					mat[i][j]=0;
		}
		
		int ans=1<<28;
		for(i=0;i<(1<<10);i++)
		{
			int cnt=0;
			for(j=0;j<10;j++)
				for(k=0;k<10;k++)
					temp[j][k]=mat[j][k];
			
			for(j=0;j<10;j++)
				if(i & 1<<j)
				{
					cnt++;
					temp[0][j]^=1;
					if(j)
						temp[0][j-1]^=1;
					if(j<9)
						temp[0][j+1]^=1;
					temp[1][j]^=1;
				}
			
			for(j=1;j<10;j++)
			{
				for(k=0;k<10;k++)
					if(temp[j-1][k])
					{
						cnt++;
						temp[j-1][k]^=1;
						temp[j][k]^=1;
						temp[j+1][k]^=1;
						if(k)
							temp[j][k-1]^=1;
						if(k<9)
							temp[j][k+1]^=1;
					}	
			}
			
			int ok=1;
			
			for(j=0;j<10;j++)
				if(temp[9][j])
					ok=0;
			
			if(ok)
				if(cnt<ans)
					ans=cnt;
		}
		if(ans==1<<28 || ans>100)
			printf("%s -1\n",cs);
		else
			printf("%s %d\n",cs,ans);
	}
	return 0;
}
