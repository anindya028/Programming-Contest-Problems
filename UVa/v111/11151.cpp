//DP
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define max(a,b) (a>b?a:b)
int mat[1005][1005];
char s[1005];
int get(int i,int j)
{
	if(i>j)
		return 0;
	if(mat[i][j])
		return mat[i][j];
	if(i==j)
	{
		mat[i][j]=1;
		return 1;
	}
	else if(s[i]==s[j])
	{
		mat[i][j]=get(i+1,j-1)+2;
		return mat[i][j];
	}
	else
	{
		mat[i][j]=max(get(i,j-1),get(i+1,j));
		return mat[i][j];
	}
}
int main()
{
	int i,j,k,n,len;
	scanf("%d",&n);
	gets(s);
	for(k=0;k<n;k++)
	{
		gets(s);
		len=strlen(s);
		if(!len)
		{
			printf("0\n");
			continue;
		}
		for(i=0;i<len;i++)
			for(j=0;j<len;j++)
				mat[i][j]=0;
		printf("%d\n",get(0,len-1));
	}
	return 0;
}