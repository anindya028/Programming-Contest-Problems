#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int ans[151],i,j,count,killed,*a,c,found;
	for(i=3;i<=150;i++)
	{
		found=0;
		for(c=2;!found;c++)
		{
			a=(int *)calloc(i,sizeof(int));
			a[0]=1;
			for(j=1,count=0,killed=1;!a[1];j=(j+1)%i)
			{
				if(!a[j])count++;
				if(count==c)
				{
					a[j]=1;
					count=0;
					killed++;
				}
				if(killed==(i-1) && !a[1])
				{
					ans[i]=c;
					found=1;
					break;
				}
			}
			free(a);
		}
	}
	while(scanf("%d",&i)==1)
	{
		if(!i)break;
		printf("%d\n",ans[i]);
	}
	return 0;
}













