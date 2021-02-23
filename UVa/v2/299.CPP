#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int num[55];
void swap(int i,int j)
{
	int temp;
	temp=num[i];
	num[i]=num[j];
	num[j]=temp;
}
int main()
{
	int n,i,j,k,l,count;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&l);
                count=0;
		for(j=0;j<l;j++)scanf("%d",&num[j]);
		for(j=0;j<(l-1);j++)
		{
			for(k=j+1;k<l;k++)
			{
				if(num[k]<num[j])
				{
					swap(j,k);
					count++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",count);
        }
	return 0;
}













