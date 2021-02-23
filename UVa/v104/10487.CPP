//searching
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int *sum;
int bisearch1(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(sum[mid]>=key)high=mid;
		else low=mid+1;
	}
	if(sum[low]>=key)return low;
	else return 0;
}
int bisearch2(int key,int n)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(sum[mid]<=key)low=mid;
		else high=mid-1;
	}
	if(sum[low]<=key)return low;
	else return 0;
}
int comp(const void *a, const void *b) { 
    long *x=(long *)a; 
    long *y=(long *)b; 
    if(*x>*y) return 1; 
    if(*x<*y) return -1; 
    else return 0; 
}
int main()
{
	int n,m,q,*num,i,j,k,cs=0;
	while(scanf("%d",&n)==1)
	{
        	if(!n)break;
		num=(int *)calloc(n,sizeof(int));
		sum=(int *)calloc(n*(n-1)/2,sizeof(int));
		for(i=0,k=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			for(j=0;j<i;j++)
			{
				if(num[j]==num[i])continue;
				sum[k]=num[i]+num[j];
				k++;
			}
		}
		qsort(sum,k,sizeof(sum[0]),comp);
		scanf("%d",&m);
		printf("Case %d:\n",cs+1);
		for(i=0;i<m;i++)
		{
			scanf("%d",&q);
			j=sum[bisearch1(q,k)];
			n=sum[bisearch2(q,k)];
			if(j==q)printf("Closest sum to %d is %d.\n",q,j);
			else if(n==q)printf("Closest sum to %d is %d.\n",q,n);
			else
                        {
				if(abs((j-q))<abs((q-n)))printf("Closest sum to %d is %d.\n",q,j);
				else printf("Closest sum to %d is %d.\n",q,n);
                        }
		}
		cs++;
	}
	return 0;            
}













