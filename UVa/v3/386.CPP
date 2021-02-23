#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
//#define Long __int64
//#define Long long long
struct cube
{
	int a,b,c,d;
}cub[1000];
bool operator<(cube A,cube B)
{
	if(A.a==B.a)
		return A.b<B.b;
	return A.a<B.a;
}
int main()
{
	int i,j,k,s,q,count=0;
	for(i=2;i<=200;i++)
		for(j=i;j<=200;j++)
			for(k=j;k<=200;k++)
			{
				s=i*i*i+j*j*j+k*k*k;
				q=(int)(pow(s,1./3.)+1e-8);
				if(q*q*q==s && q<=200)
				{
					cub[count].a=q;
					cub[count].b=i;
					cub[count].c=j;
					cub[count].d=k;
					count++;
				}
			}
	sort(cub,cub+count);
	for(i=0;i<count;i++)
		printf("Cube = %d, Triple = (%d,%d,%d)\n",cub[i].a,cub[i].b,cub[i].c,cub[i].d);
	return 0;
}













