#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int comp(const void *a, const void *b) {
    long *x=(long *)a; 
    long *y=(long *)b; 
    if(*x>*y) return 1; 
    if(*x<*y) return -1; 
    else return 0; 
}
int *num,n;
int binsearch(int key)
{
	int low=1,high=n,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(num[mid]>=key)high=mid;
		else low=mid+1;
	}
	if(num[low]>=key)return low;
	else return 0;
}
int main()
{
	int q,i,m,ans,cs=0;
	while(scanf("%ld%ld",&n,&q)==2 && n)
	{
		printf("CASE# %d:\n",++cs);
		num=(int *)calloc(n+1,sizeof(int));
		num[0]=0;
		for(i=1;i<=n;i++)scanf("%d",&num[i]);
		qsort(num,n+1,sizeof(num[0]),comp);
		for(i=0;i<q;i++)
		{
			scanf("%d",&m);
			ans=binsearch(m);
			if(!ans)printf("%d not found\n",m);
			else
			{
				if(num[ans]==m)printf("%d found at %d\n",m,ans);
				else printf("%d not found\n",m);
			}
		}
        }
	return 0;
}













