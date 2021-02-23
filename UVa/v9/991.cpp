#include<stdio.h>

int main()
{
	int n,cat[14],i;
	cat[0]=1;
	cat[1]=1;
	cat[2]=2;
	for(i=2;i<11;i++)
		cat[i]=(2*(2*i-1)*cat[i-1])/(i+1);
	i=0;
	while(scanf("%d",&n)==1)
	{
		if(i)
			printf("\n");
		i++;
		printf("%d\n",cat[n]);
	}
	return 0;
}