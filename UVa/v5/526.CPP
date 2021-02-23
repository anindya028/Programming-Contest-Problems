#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

#define Min(a,b) (((a)<(b))?(a):(b))
enum{replace=1,insert,delet};

int mat[100][100],parent[100][100],index,pos[100];
char s1[100],s2[100];

void print(int i,int j)
{

	if(i<=0 && j<=0)
	{
		return;
	}
	if(parent[i][j]==delet)
	{

		printf("%d Delete %d\n",index++,pos[i-1]);
		print(i-1,j);
	}
	else if(parent[i][j]==insert)
	{

		printf("%d Insert %d,%c\n",index++,pos[i],s2[j-1]);
		print(i,j-1);
	}
	else if(parent[i][j]==0)
	{
		print(i-1,j-1);
	}
	else
	{

		printf("%d Replace %d,%c\n",index++,pos[i-1],s2[j-1]);
		print(i-1,j-1);
	}
	return;
}

int main()
{
	int val,i,j,len1,len2,cs=0;
	while(gets(s1))
	{
		gets(s2);
		if(cs)
			printf("\n");
		len1=strlen(s1);
		len2=strlen(s2);
		mat[0][0]=0;
		for(i=1;i<=len1;i++)
		{
			mat[i][0]=i;
			parent[i][0]=delet;
		}
		for(j=1;j<=len2;j++)
		{
			mat[0][j]=j;
			parent[0][j]=insert;
		}
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++)
				parent[i][j]=0;
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++)
			{
				val=(s1[i-1]==s2[j-1])?0:1;
				mat[i][j]=Min(mat[i-1][j-1]+val,Min(mat[i-1][j]+1,mat[i][j-1]+1));
				if(mat[i][j]==(mat[i-1][j]+1))
					parent[i][j]=delet;
				else if(mat[i][j]==(mat[i][j-1]+1))
					parent[i][j]=insert;
				else if(mat[i][j]==(mat[i-1][j-1]+val) && val)
					parent[i][j]=replace;
			}
		printf("%d\n",mat[len1][len2]);
		index=1;
		for(i=0;i<100;i++)
			pos[i]=i+1;
		print(len1,len2);
		cs++;
	}
	return 0;
}













