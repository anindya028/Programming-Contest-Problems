//Classic DP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define size 1005

int mat[size][size],track[size][size];
char s[size];

int make(int st,int end)
{
	int a,b;
	if(st>end)
		return 0;
	if(mat[st][end]>=0)
		return mat[st][end];
	if(s[st]==s[end])
	{
		mat[st][end]=make(st+1,end-1);
		track[st][end]=0;
	}
	else
	{
		a=make(st,end-1)+1;
		b=make(st+1,end)+1;
		if(a>b)
		{
			mat[st][end]=b;
			track[st][end]=1;
		}
		else
		{
			mat[st][end]=a;
			track[st][end]=2;
		}
	}
	return mat[st][end];
}

void print(int st,int end)
{
	if(st>end)
		return;
	if(track[st][end]==0)
	{
		printf("%c",s[st]);
		print(st+1,end-1);
		if(st!=end)
			printf("%c",s[end]);
	}
	else if(track[st][end]==1)
	{
		printf("%c",s[st]);
		print(st+1,end);
		printf("%c",s[st]);
	}
	else
	{
		printf("%c",s[end]);
		print(st,end-1);
		printf("%c",s[end]);
	}
	return;
}

int main()
{
	register int i,j;
	int len;
	while(scanf("%s",s)==1)
	{
		len=strlen(s);
		for(i=0;i<len;i++)
			for(j=i+1;j<len;j++)
				mat[i][j]=track[i][j]=-1;
		printf("%d ",make(0,len-1));
		print(0,len-1);
		printf("\n");
	}
	return 0;
}
