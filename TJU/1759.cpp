#include<stdio.h>

#define For(i,a,b) for(i=(a);i<(b);++i)
#define Foro(i,a) For(i,0,(a))
#define inf 1<<29
#define Min(a,b) (((a)<(b))?(a):(b))

int mat[102][102],num[102];
int make(int st,int nd)
{
	if(st>nd)
		return 0;
	if(mat[st][nd]!=inf)
		return mat[st][nd];
	int i;
	For(i,st,nd+1)
		mat[st][nd]=Min(mat[st][nd],make(st,i-1)+make(i+1,nd)+num[st-1]*num[i]*num[nd+1]);
	return mat[st][nd];
}

int main()
{
	int n,i,j;
	while(scanf("%d",&n)==1)
	{
		Foro(i,n+1)
			Foro(j,n+1)
				mat[i][j]=inf;
		Foro(i,n)
			scanf("%d",&num[i]);
		printf("%d\n",make(1,n-2));
	}
	return 0;
}