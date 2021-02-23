/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int sum,num[1001],n,i;
int comp(const void *a, const void *b) {
    long *x=(long *)a; 
    long *y=(long *)b; 
    if(*x>*y) return 1; 
    if(*x<*y) return -1; 
    else return 0; 
}
int bisearch(int key)
{
	int low=1,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(num[mid]==key)return mid;
		else if(num[mid]>key)high=mid-1;
		else low=mid+1;
	}
	return 0;
}
int gene(void)
{
	int temp,k,j,flag=0;
	for(i=0;i<(n-2);i++)
	{
		for(j=i+1;j<(n-1);j++)
		{
                	if(num[i]==num[j])continue;
			for(k=j+1;k<n;k++)
			{
				if(num[i]==num[k]||num[j]==num[k])continue;
				temp=num[i]+num[j]+num[k];
                                if(temp>num[n-1])return flag;
				if(bisearch(temp))
				{
					if(temp!=num[i]&&temp!=num[j]&&temp!=num[k])
                                        {
						sum=temp;
						flag=1;
					}
				}
			}
		}
	}
        return flag;
}
int main()
{
	int m;
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
                sum=0;
                for(i=0;i<n;i++)scanf("%d",&num[i]);
		qsort(num,n,sizeof(num[0]),comp);
                m=gene();
                if(m)printf("%d\n",sum);
		else printf("no solution\n");
        }
	return 0;
}*/
#include<stdio.h> 
#include<stdlib.h> 

typedef int LONG; 
#define INF 2000000000 

LONG arr[1005],data[1000009],sum1[1000009],sum2[1000009]; 
int index,ind1,ind2;

int sfunc1(void const *a,void const *b) 
{ 
   LONG p,q; 
   p=*(LONG *)a; 
   q=*(LONG *)b; 
   if(p>q) return 1; 
   else return -1; 
   return 0; 
} 

int binsearch(LONG x) 
{ 
   int low,high,mid; 
   low=0; 
   high=index; 

   while(low<(high-1)) 
   { 
      mid=(low+high)/2; 
      if(x<data[mid]) high=mid; 
      else low=mid; 
   }    
   if(x==data[low]) return low; 
   return -1; 
} 

void main() 
{ 
   int i,j,N,flag,r; 
   LONG a,max; 

   //freopen("10125.in","r",stdin); 

   while(scanf("%d",&N)==1 && N) 
   { 
      for(i=0;i<N;i++) scanf("%d",&arr[i]); 
      qsort(arr,N,sizeof(arr[0]),sfunc1); 
      ind1=ind2=index=0; 
      for(i=0;i<N;i++) 
      { 
         for(j=i+1;j<N;j++) 
         { 
			 if(arr[i]==arr[j])continue;
            data[index++]=arr[i]+arr[j];
			sum1[ind1++]=i;
			sum2[ind2++]=j;
         } 
      } 
      qsort(data,index,sizeof(data[0]),sfunc1); 
      max=-INF; 
      flag=1; 
      for(i=N-1;i>=0;i--) 
      { 
         for(j=i-1;j>=0;j--) 
         { 
            if(arr[i]==arr[j])continue;
			 a=(arr[i]-arr[j]); 
            r=binsearch(a); 
            if(r!=-1) 
            { 
               if(arr[i]>max)
			   {
				   if(sum1[r]!=i&&sum2[r]!=i&&sum2[r]!=j&&sum1[r]!=j)
				   {
					   max=arr[i]; 
						flag=0; 
				   }
			   }
            } 

            /*a=(data[j]-arr[i]); 
            r=binsearch(a); 
            if(r!=-1) 
            { 
               if(arr[j]>max)
			   {
				   if(sum1[r]!=arr[i]&&sum2[r]!=arr[i]&&sum1[r]!=data[j]&&sum2[r]!=data[j])
				   {
						max=arr[j]; 
						flag=0;
				   }
			   }
            }*/ 
         } 
          
      } 

      if(flag==1) printf("no solution\n"); 
      else printf("%d\n",max);    
   } 
}












