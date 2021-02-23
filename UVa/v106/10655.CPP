#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
//#define Long __int64
#define Long long long
struct matrix
{
	Long mat[5][5],r,c;
}fib;
matrix mat_mult(matrix A,matrix B)
{
	int i,j,k;//A.c must be equal to B.r
	matrix C;
	for(i=0;i<A.r;i++)
		for(j=0;j<B.c;j++)
		{
			C.mat[i][j]=0;
			for(k=0;k<A.c;k++)
				C.mat[i][j]+=A.mat[i][k]*B.mat[k][j];
		}
	C.r=A.r;
	C.c=B.c;
	return C;
}
matrix bigmod(matrix B,int p)
{
	matrix A;
	if(p==1)
		return B;
	if(p%2==0)
	{
		A=bigmod(B,p/2);
		return mat_mult(A,A);
	}
	else
		return mat_mult(B,bigmod(B,p-1));
}
int main()
{
    fib.r=fib.c=2;
    fib.mat[1][0]=1;
    fib.mat[1][1]=0;
    matrix ans;
    int p,q,n;
    while(scanf("%d%d%d",&p,&q,&n)==3)
    {	
          if(!n)
          {
                printf("2\n");
                continue;
          }
          if(!p && !q)
          {
                printf("0\n");
                continue;
          }
          if(p==1 && !q)
          {
                 printf("1\n");
                 continue;
          } 
          if(p==2 && q==1)
          {
                  printf("2\n");
                  continue;
          } 
		  if(n==1)
		  {
			  printf("%d\n",p);
			  continue;
		  }
          fib.mat[0][0]=p;
          fib.mat[0][1]=-q;
          ans=bigmod(fib,n-1);
          printf("%lld\n",ans.mat[0][0]*p+2*ans.mat[0][1]);
    }                                
	return 0;
}













