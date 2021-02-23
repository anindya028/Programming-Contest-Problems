#include<stdio.h>

int main()
{
	int t,cs,n,num[30],mil,jui,i;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		mil=jui=0;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]),mil+=(num[i]/30+1)*10,jui+=(num[i]/60+1)*15;
		if(mil<jui)
			printf("Case %d: Mile %d\n",cs+1,mil);
		else if(mil>jui)
			printf("Case %d: Juice %d\n",cs+1,jui);
		else 
			printf("Case %d: Mile Juice %d\n",cs+1,mil);
	}
	return 0;
}