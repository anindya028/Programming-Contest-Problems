#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[105][105];
int m,n,i,j,count;
void fill(int r,int c)
{
	if((r-1)>=0)
	{
        	if((c-1)>=0)
		{
			if(s[r-1][c-1]=='@')
			{
				s[r-1][c-1]='*';
				fill(r-1,c-1);
			}
		}
		if(s[r-1][c]=='@')
		{
			s[r-1][c]='*';
			fill(r-1,c);
		}
		if(s[r-1][c+1]=='@')
		{
			s[r-1][c+1]='*';
			fill(r-1,c+1);
		}
	}
	if((c-1)>=0)
        {
		if(s[r][c-1]=='@')
		{
			s[r][c-1]='*';
			fill(r,c-1);
		}
	}
	if(s[r][c+1]=='@')
	{
		s[r][c+1]='*';
		fill(r,c+1);
	}
	if((r+1)<m)
	{
		if((c-1)>=0)
		{
			if(s[r+1][c-1]=='@')
			{
				s[r+1][c-1]='*';
				fill(r+1,c-1);
			}
                }
		if(s[r+1][c]=='@')
		{
			s[r+1][c]='*';
			fill(r+1,c);
		}
		if(s[r+1][c+1]=='@')
		{
			s[r+1][c+1]='*';
			fill(r+1,c+1);
		}
        }
        return;
}
int main()
{
	while(scanf("%d%d",&m,&n)==2)
	{
		if(!m)break;
		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		for(i=count=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(s[i][j]=='@')
				{
					count++;
					s[i][j]='*';
					fill(i,j);
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}













