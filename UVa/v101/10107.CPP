#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define size 10000
/*int sort_function( const void *a, const void *b)
{
	return strcmp((char *)a,(char *)b);
}*/
long s[size];
long bisearch(long key,long n)
{
	long low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high+1)/2;
		if(s[mid]<key)low=mid;
		else high=mid-1;
	}
	if(s[low]<key)return low;
	else return  0;
}
void main ()
{
	long temp,i=0,j,lim;
	while(scanf("%ld",&temp)==1)
	{
		//qsort((void *)s,i+1, sizeof(s[0]),sort_function);
		if(!i)
		{
                	s[i]=temp;
			printf("%ld\n",s[i]);
        	}
		else
		{
			lim=bisearch(temp,i);
			for(j=i-1;j>lim;j--)
			{
				s[j+1]=s[j];
			}
			s[j+1]=temp;
                	if(!(i%2))
                        {
                        	printf("%ld\n",s[i/2]);
                        }
			else
                        {
				temp=s[(i-1)/2]+s[(i+1)/2];
				if(!(temp%2))
				{
					printf("%ld\n",temp/2);
				}
				else
				{
					printf("%ld\n",(temp-1)/2);
				}
                        }
		}
                i++;
	}


}


