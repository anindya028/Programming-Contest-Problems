#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	int m,n,temp;
	while(scanf("%d%d",&m,&n)==2)
	{
		if(!m||!n)break;
		if(m==1&&n==1)
		{
			printf("1 knights may be placed on a 1 row 1 column board.\n");
			continue;
		}
		if(m==1||n==1)
		{
			printf("%d knights may be placed on a %d row %d column board.\n",n+m-1,m,n);
			continue;
		}
		if(m==2||n==2)
		{
			temp=(m!=2?m:n);
			if((temp%4)>=2)
				printf("%d knights may be placed on a %d row %d column board.\n",(temp/4)*4+4,m,n);
			else if(temp%4==1)
				printf("%d knights may be placed on a %d row %d column board.\n",(temp/4)*4+2,m,n);
			else printf("%d knights may be placed on a %d row %d column board.\n",(temp/4)*4,m,n);
			continue;
		}
		if((m*n)%2)printf("%d knights may be placed on a %d row %d column board.\n",(m*n+1)/2,m,n);
		else printf("%d knights may be placed on a %d row %d column board.\n",m*n/2,m,n);
	}
	return 0;
}













