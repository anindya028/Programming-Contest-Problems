#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[30][30];
int m,n,i,j,count,cs;
void fill(int r,int c)
{
	if((r-1)>=0)
	{
        	if((c-1)>=0)
		{
			if(s[r-1][c-1]=='1')
			{
				s[r-1][c-1]='0';
				fill(r-1,c-1);
			}
		}
		if(s[r-1][c]=='1')
		{
			s[r-1][c]='0';
			fill(r-1,c);
		}
		if(s[r-1][c+1]=='1')
		{
			s[r-1][c+1]='0';
			fill(r-1,c+1);
		}
	}
	if((c-1)>=0)
        {
		if(s[r][c-1]=='1')
		{
			s[r][c-1]='0';
			fill(r,c-1);
		}
	}
	if(s[r][c+1]=='1')
	{
		s[r][c+1]='0';
		fill(r,c+1);
	}
	if((r+1)<m)
	{
		if((c-1)>=0)
		{
			if(s[r+1][c-1]=='1')
			{
				s[r+1][c-1]='0';
				fill(r+1,c-1);
			}
                }
		if(s[r+1][c]=='1')
		{
			s[r+1][c]='0';
			fill(r+1,c);
		}
		if(s[r+1][c+1]=='1')
		{
			s[r+1][c+1]='0';
			fill(r+1,c+1);
		}
        }
        return;
}
int main()
{
	while(scanf("%d",&m)==1)
	{
		n=m;
		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		for(i=count=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(s[i][j]=='1')
				{
					count++;
					s[i][j]='0';
					fill(i,j);
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n",++cs,count);
	}
	return 0;
}













