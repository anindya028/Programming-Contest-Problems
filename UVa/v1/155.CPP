#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int n,px,py;
void recurse(int x, int y, int k)
{
	if (x-k<=px && x+k>=px && y-k<=py && y+k>=py) 
		n++;
	if (k>1)
	{
		recurse(x-k,y-k,k/2);
		recurse(x-k,y+k,k/2);
		recurse(x+k,y-k,k/2);
		recurse(x+k,y+k,k/2);
	}
}
int main()
{
	int k;
	while (scanf("%d%d%d",&k,&px,&py)!=EOF && (k || px || py))
	{
		n = 0;
		recurse(1024,1024,k);
		printf("%3d\n",n);
	}
	return 0;
}













