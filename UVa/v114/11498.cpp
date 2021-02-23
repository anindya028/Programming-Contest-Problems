#include<stdio.h>

int main()
{
	int a,b,x,y,k,i;
	while(scanf("%d",&k)==1 && k)
	{
		scanf("%d%d",&a,&b);
		for(i=0;i<k;++i)
		{
			scanf("%d%d",&x,&y);
			x-=a,y-=b;
			if(!x || !y)
				printf("divisa\n");
			else if(x<0 && y<0)
				printf("SO\n");
			else if(x>0 && y<0)
				printf("SE\n");
			else if(x>0 && y>0)
				printf("NE\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}