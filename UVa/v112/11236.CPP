#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define eps 1e-10
struct Triplet
{
	int a,b,c,d;
	int sum;
}tri[100000];
int gener(void)
{
	int count=0;
	register int i,j,k,l;
	for(i=1;4*i<=2000;i++)
		for(j=i;(i+3*j)<=2000;j++)
			for(l=j;(2*l+i+j)<=2000;l++)
			{
				if(i*j*l<=1000000)continue;
				k=((i+j+l)*1000000)/(i*j*l-1000000);
				if(((i+j+l)*1000000)%(i*j*l-1000000)==0 && k>=l && (i+j+k+l)<=2000)
				{
					tri[count].a=i;
					tri[count].b=j;
					tri[count].c=l;
					tri[count].d=k;
					count++;
				}
			}
	return count;
}
int main()
{
	int i,j,count;
	count=gener();
	for(i=0;i<count;i++)
		printf("%.2lf %.2lf %.2lf %.2lf\n",tri[i].a/100.,tri[i].b/100.,tri[i].c/100.,tri[i].d/100.);
	return 0;
}













