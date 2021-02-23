#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int num,den,temp;
	while(scanf("%d%d",&num,&den)==2)
	{
		printf("[%d;",num/den);
		temp=num%den;
		num=den;
		den=temp;
		printf("%d",num/den);
		while(den>1)
		{
			temp=num%den;
			num=den;
			den=temp;
			printf(",%d",num/den);
		}
		printf("]\n");
	}
	return 0;
}













