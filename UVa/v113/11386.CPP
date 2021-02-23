//Good search problem,O(n^2*log(n))
//O(n^2) solution exists
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

struct number
{
	int no;
	long long freq;
}num[5005];

bool operator<(number a,number b)
{
	return a.no<b.no;
}

int binsearch(int low,int high,int key)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(num[mid].no==key)
			return mid;
		else if(num[mid].no>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return 50000;
}
		


int main()
{
	int n,k,temp;
	long long cnt;
	register int i,j;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i].no);
		sort(num,num+n);
		for(i=j=0;i<n;i++)
		{
			cnt=1;
			temp=i;
			while(i<(n-1) && num[i+1].no==num[i].no)
			{
				i++;
				cnt++;
			}
			num[j].no=num[temp].no;
			num[j].freq=cnt;
			j++;
		}
		n=j;
		cnt=0;
		for(i=0;i<n;i++)
		{
			if(num[i].freq>1)
			{
				k=binsearch(i+1,n-1,num[i].no*2);
				if(k<n)
					cnt+=(((num[i].freq*(num[i].freq-1))/2)*num[k].freq);
			}
			for(j=i+1;j<n;j++)
			{
				k=binsearch(j+1,n-1,num[i].no+num[j].no);
				if(k<n)
					cnt+=(num[i].freq * num[j].freq * num[k].freq);
				if( (num[i].no+num[j].no) >= num[n-1].no)
					break;
			}
		}
		printf("%lld\n",cnt);
	}				
	return 0;
}
