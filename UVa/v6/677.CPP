#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define N 20 
int n,d,time,a[N][N],b[N],path; 
char color[N]; 
void dfs(int s) 
{ 
   int i; 
   if(time==(d+1)) 
   { 
      path++; 
      printf("("); 
      for(i=0;i<=d;i++) 
      { 
         if(i) printf(","); 
         printf("%d",b[i]+1); 
      } 
      printf(")\n"); 
      return ; 
   } 
   for(i=0;i<n;i++) 
      if(color[i]=='w' && a[s][i]) 
      { 
         color[i]='g'; 
         b[time++]=i; 
         dfs(i); 
         b[--time]=0; 
         color[i]='w'; 
      } 
} 
int main()
{
	int cs=0,i,j;
	do
	{
		if(cs)printf("\n");
		cs++;
		scanf("%d%d",&n,&d);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<n;i++)
			color[i]='w';
		path=0;
		time=1;
		color[0]='g';
		dfs(0);
		if(!path)printf("no walk of length %d\n",d);
	}while(scanf("%d",&n)==1 && n==-9999);
	return 0;
}













