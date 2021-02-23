#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int cs,n,k,i,j,two[32],ans;
	two[0]=1;
	for(i=1;i<31;i++)
		two[i]=two[i-1]*2;
	scanf("%d",&cs);
	for(i=0;i<cs;i++)
	{
		scanf("%d%d",&n,&k);
		for(j=ans=0;j<n;j++)
		{
			if(k>=two[n-j-1])
			{
				ans+=two[n-j-1];
				k=two[n-j-1]-(k-two[n-j-1]+1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}













