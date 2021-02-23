#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int  main()
{
	int t,i,a,b;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>b)printf(">\n");
		else if(a<b)printf("<\n");
		else printf("=\n");
	}
	return 0;
}













