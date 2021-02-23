#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char s[105][105];
int r,c;
int give(int i,int j)
{
	if(i)
	{
		if(j)
		{
			if(s[i-1][j-1]=='*')
				return 0;
		}
		if(s[i-1][j]=='*')
			return 0;
		if(j<(c-1))
		{
			if(s[i-1][j+1]=='*')
				return 0;
		}
	}
	if(j)
	{
		if(s[i][j-1]=='*')
			return 0;
	}
	if(j<(c-1))
	{
		if(s[i][j+1]=='*')
			return 0;
	}
	if(i<(r-1))
	{
		if(j)
		{
			if(s[i+1][j-1]=='*')
				return 0;
		}
		if(s[i+1][j]=='*')
			return 0;
		if(j<(c-1))
		{
			if(s[i+1][j+1]=='*')
				return 0;
		}
	}
	return 1;
}
int main()
{
	int i,j,count;
	while(scanf("%d%d",&r,&c)==2)
	{
		if(!r && !c)
			break;
		for(i=0;i<r;i++)
			scanf("%s",s[i]);
		count=0;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(s[i][j]=='*')
					count+=give(i,j);
		printf("%d\n",count);
	}
	return 0;
}













