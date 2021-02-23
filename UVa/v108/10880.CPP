#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j,k,r,c,q,*fir,*sec;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&c,&r);
		if(c==r)
		{
			printf("Case #%d: 0\n",i+1);
			continue;
		}
		fir=(int *)calloc(100000,sizeof(int));
		sec=(int *)calloc(100000,sizeof(int));
		q=c-r;
		if(q<r)
		{
			printf("Case #%d:\n",i+1);
			free(fir);
			free(sec);
			continue;
		}
		for(j=1,k=0;j*j<=q;j++)
		{
			if(q%j==0)
			{
				fir[k]=j;
				sec[k]=q/j;
				k++;
			}
		}
		printf("Case #%d:",i+1);
		for(j=0;j<k;j++)
		{
			if(fir[j]>r)printf(" %d",fir[j]);
		}
		for(j=k-1;j>=0;j--)
		{
			if(sec[j]>r && sec[j]!=fir[j])printf(" %d",sec[j]);
		}
		printf("\n");
		free(fir);
		free(sec);
	}
	return 0;
}













