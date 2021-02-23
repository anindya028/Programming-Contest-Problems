#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,*num,i,j,*temp,ans,zero;
	while(scanf("%d%d",&n,&k)==2)
	{
		if(!n && !k)break;
		num=(int *)calloc(n,sizeof(int));
		temp=(int *)calloc(n,sizeof(int));
		for(i=zero=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(!num[i])zero++;
		}
		sort(num,num+n);
		if((n-zero)<k)
		{
			for(i=n-k,j=ans=0;j<k;j++,i++)
				ans+=num[i];
			printf("%d\n",ans);
			free(num);
			free(temp);
			continue;
		}
		if(num[n-1]>0 || k%2)
		{
			for(i=n-k,j=0;j<k;j++,i++)
			{
				temp[j]=num[i];
			}
		}
		else 
		{
			for(i=0;i<k;i++)
			{
				temp[i]=num[i];
			}
		}
		if((num[n-1]>0 &&  n>1 && k>1) || k%2==0)
		{
			for(i=0;i<(k-1);i+=2)
			{
				if((num[i]*num[i+1])>(temp[i]*temp[i+1]))
				{
					temp[i]=num[i];
					temp[i+1]=num[i+1];
				}
				else break;
			}
		}
		for(i=ans=0;i<k;i++)ans+=temp[i];
		printf("%d\n",ans);
		free(num);
		free(temp);
	}
	return 0;
}













