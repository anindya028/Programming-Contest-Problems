#include<stdio.h>
#define myabs(a) (((a)>0)?(a):-(a))

int main()
{
	int a,b,c,i,j,got,t,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		got=0;
		for(i=-b;3*i<=a && !got;i++)
		{
			if(!i || b%myabs(i))
				continue;
			for(j=i+1;i+2*j<=a && !got;j++)
			{
				int k=a-i-j;
				if((i*j*k)==b && (i*i+j*j+k*k)==c && k!=i && j!=i)
				{
					got=1;
					x=i,y=j,z=k;
				}
			}
		}
		if(!got)
			printf("No solution.\n");
		else
			printf("%d %d %d\n",x,y,z);
	}
	return 0;
}