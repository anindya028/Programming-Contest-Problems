#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define inf 1<<30
int *a,*left,*right;
unsigned long long count;
void merge(int p,int q,int r)
{
	int n1,n2,i,j,k;
	n1=q-p+1;
        n2=r-q;
	left=(int *)calloc((n1+2),sizeof(int));
	right=(int *)calloc((n2+2),sizeof(int));
	for(i=1;i<=n1;i++)left[i]=a[p+i-1];
	for(j=1;j<=n2;j++)right[j]=a[q+j];
        left[i]=right[j]=inf;
	for(i=1,j=1,k=p;k<=r;k++)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
                	count+=(n1-i+1);
			a[k]=right[j];
			j++;
		}
	}
	free(left);
        free(right);
	return;
}
void mergesort(int p,int r)
{
	int q;
	if(p<r)
	{
        	q=(p+r)/2;
		mergesort(p,q);
		mergesort(q+1,r);
		merge(p,q,r);
	}
        return;
}
int main()
{
	int n,i;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		a=(int *)calloc((n+5),sizeof(int));
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		count=0;
		mergesort(1,n);
		printf("%llu\n",count);
		free(a);
	}
	return 0;
}













