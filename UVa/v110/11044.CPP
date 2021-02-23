#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int cs,n,m,i;
	scanf("%d",&cs);
	for(i=0;i<cs;i++)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",((int)(n/3))*((int)(m/3)));
	}
	return 0;
}













