#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
char s[105][105];
int m,n;
int counter(int i,int j)
{
	int count=0;
	if((i-1)>=0)
	{
		if((j-1)>=0)
		{
			if(s[i-1][j-1]=='*')count++;
		}
		if(s[i-1][j]=='*')count++;
		if((j+1)<n)
		{
			if(s[i-1][j+1]=='*')count++;
		}
	}
	if((j-1)>=0)
	{
		if(s[i][j-1]=='*')count++;
	}
	if((j+1)<n)
	{
		if(s[i][j+1]=='*')count++;
	}
	if((i+1)<m)
	{
		if((j-1)>=0)
		{
			if(s[i+1][j-1]=='*')count++;
		}
		if(s[i+1][j]=='*')count++;
		if((j+1)<n)
		{
			if(s[i+1][j+1]=='*')count++;
		}
	}
	return count;
}
int main()
{
	int cs=0,i,j;
	char ans[105][105];
	while(scanf("%d%d",&m,&n)==2)
	{
			if(!m || !n)break;
        	if(cs)printf("\n");
		for(i=0;i<m;i++)scanf("%s",s[i]);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(s[i][j]=='*')ans[i][j]='*';
				else ans[i][j]=counter(i,j)+'0';
			}
			ans[i][j]='\0';
		}
		printf("Field #%d:\n",++cs);
		for(i=0;i<m;i++)printf("%s\n",ans[i]);
        }
	return 0;
}













