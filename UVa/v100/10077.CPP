#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct Fract
{
	int num,den;
}f,low,high,mid;

void binsearch(void)
{
	low.num=0,low.den=1,high.num=1,high.den=0;
	while(1)
	{
		mid.num=low.num+high.num;
		mid.den=low.den+high.den;
		if(f.num*mid.den < f.den*mid.num)
		{
			printf("L");
			high=mid;
		}
		else if(f.num*mid.den > f.den*mid.num)
		{
			printf("R");
			low=mid;
		}
		else
			return;
	}
	return;
}
int main()
{
	while(scanf("%d%d",&f.num,&f.den)==2)
	{
		if(f.num==1 && f.den==1)
			break;
		binsearch();
		printf("\n");
	}
	return 0;
}













