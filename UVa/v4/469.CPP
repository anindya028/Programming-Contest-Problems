#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s[105][105],temp[105][105];
int m,n,i,j,count,cs;
void fill(int r,int c)
{
	if((r-1)>=0)
	{
        	if((c-1)>=0)
		{
			if(temp[r-1][c-1]=='W')
			{
				temp[r-1][c-1]='L';
				count++;
				fill(r-1,c-1);
			}
		}
		if(temp[r-1][c]=='W')
		{
			temp[r-1][c]='L';
			count++;
			fill(r-1,c);
		}
		if(temp[r-1][c+1]=='W')
		{
			temp[r-1][c+1]='L';
			count++;
			fill(r-1,c+1);
		}
	}
	if((c-1)>=0)
        {
		if(temp[r][c-1]=='W')
		{
			temp[r][c-1]='L';
			count++;
			fill(r,c-1);
		}
	}
	if(temp[r][c+1]=='W')
	{
		temp[r][c+1]='L';
		count++;
		fill(r,c+1);
	}
	if((r+1)<m)
	{
		if((c-1)>=0)
		{
			if(temp[r+1][c-1]=='W')
			{
				temp[r+1][c-1]='L';
				count++;
				fill(r+1,c-1);
			}
        }
		if(temp[r+1][c]=='W')
		{
			temp[r+1][c]='L';
			count++;
			fill(r+1,c);
		}
		if(temp[r+1][c+1]=='W')
		{
			temp[r+1][c+1]='L';
			count++;
			fill(r+1,c+1);
		}
    }
    return;
}
int main()
{
	char t[105];
	int k,N,a;
	scanf("%d\n\n",&N);
	for(a=0;a<N;a++)
	{
		if(a)printf("\n");
		i=0;
		while(gets(t))
		{
			if(t[0]!='L' && t[0]!='W')break;
			strcpy(s[i++],t);
			if(i==1)n=strlen(t);
			else if(strlen(t)>n)n=strlen(t);
		}
		m=i;
		//n=strlen(s[i-1]);
		sscanf(t,"%d%d",&i,&j);
		if(i>=m ||j>=n)count=0;
		else if(s[i-1][j-1]=='L')count=0;
		else
		{
			for(k=0;k<m;k++)strcpy(temp[k],s[k]);
			temp[i-1][j-1]='L';
			count=1;
			fill(i-1,j-1);
		}
		printf("%d\n",count);
		while(gets(t))
		{
			if(!strlen(t))break;
			sscanf(t,"%d%d",&i,&j);
			if(i>m || j>n)count=0;
			else if(s[i-1][j-1]=='L')count=0;
			else
			{
				for(k=0;k<m;k++)strcpy(temp[k],s[k]);
				temp[i-1][j-1]='L';
				count=1;
				fill(i-1,j-1);
			}
			printf("%d\n",count);
		}
		/*for(i=0;i<m;i++)
		{
			s[i][0]='\0';
			temp[i][0]='\0';
		}*/
	}
	return 0;
}













