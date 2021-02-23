#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,k,*a,i,count,killed,found,j,p,pos,l;
	while(scanf("%d%d",&n,&k)==2)
	{
		if(!n && !k)break;
		if(n==1 && k==1)
		{
			printf("1\n");
			continue;
		}
		found=0;
		//if(k>n)k%=n;
		for(i=1;!found;i++)
		{
			a=(int *)calloc(n+1,sizeof(int));
			for(p=0;p<=n;p++)a[p]=p;
			p=1;
			for(j=i,count=killed=0;p && killed<n;j=(j+1)%(n+1))
			{
				if(a[j])count++;
				if(count==k)
				{
					if(a[j]==1)p=0;
					a[j]=0;
					pos=j;
					count=0;
					for(l=(j+1)%(n+1);p && killed<n;l=(l+1)%(n+1))
					{
						if(a[l])count++;
						if(count==k)
						{
							a[pos]=a[l];
							a[l]=count=0;
							break;
						}
					}
					killed++;
				}
				if(killed==(n-1) && p)
				{
					printf("%d\n",i);
					found=1;
					break;
				}
			}
			free(a);
		}
	}
	return 0;
}













