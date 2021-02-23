#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

int mat[15][15],n;

void row(int a,int b)
{
	int temp,i;
	for(i=0;i<n;i++)
	{
		temp=mat[a-1][i];
		mat[a-1][i]=mat[b-1][i];
		mat[b-1][i]=temp;
	}
	return;
}

void col(int a,int b)
{
	int temp,i;
	for(i=0;i<n;i++)
	{
		temp=mat[i][a-1];
		mat[i][a-1]=mat[i][b-1];
		mat[i][b-1]=temp;
	}
	return;
}

void inc(void)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			mat[i][j]=(mat[i][j]+1)%10;
	return;
}

void dec(void)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			mat[i][j]=(mat[i][j]+9)%10;
	return;
}

void transpose(void)
{
	int i,j,temp[15][15];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			temp[i][j]=mat[j][i];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			mat[i][j]=temp[i][j];
	return;
}

int main()
{
	char s[15][15],com[20];
	int a,b,i,j,cs,t,m;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				mat[i][j]=s[i][j]-'0';
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s",com);
			if(!strcmp(com,"inc"))
				inc();
			else if(!strcmp(com,"dec"))
				dec();
			else if(!strcmp(com,"transpose"))
				transpose();
			else
			{
				scanf("%d%d",&a,&b);
				if(!strcmp(com,"row"))
					row(a,b);
				else 
					col(a,b);
			}
		}
		printf("Case #%d\n",cs+1);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d",mat[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

