
#include<stdio.h>
#include<math.h>

#define size 1000005

long int gcd(long int u,long int v);

long int count[size],counter[size];
bool flag[size],temp_flag[size];

struct triple
{
	long int x,y,z;
}triple[size];

int main()
{
	long int i,j,temp1,temp2,first,second,third,n,k=0,total_triple,wait,sum;
	for(i=2;i<708;i++)
	{
		for(j=1;j<i;j++)
		{
			if(i%2!=j%2)
			{
				if(gcd(i,j)==1)
				{
					temp1=i*i;
					temp2=j*j;
					first=2*i*j;
					second=temp1-temp2;
					third=temp1+temp2;
					flag[first]=flag[second]=flag[third]=1;
					triple[k].x=first;
					triple[k].y=second;
					triple[k++].z=third;
					count[third]++;
				}
			}
		}
	}
	for(i=708;i<1000;i++)
	{
		for(j=1;j<i;j++)
		{
			if(i%2!=j%2)
			{
				if(i*i+j*j<=1000000)
				{
					if(gcd(i,j)==1)
					{
						temp1=i*i;
						temp2=j*j;
						first=2*i*j;
						second=temp1-temp2;
						third=temp1+temp2;
						flag[first]=flag[second]=flag[third]=1;
						triple[k].x=first;
						triple[k].y=second;
						triple[k++].z=third;
						count[third]++;
					}	
				}
			}
		}
	}
	total_triple=k;
	temp1=count[5];
	counter[5]=1;
	for(i=6;i<1000001;i++)
	{
		if(count[i]>0)
			temp1+=count[i];
		counter[i]+=temp1;
	}
	while(scanf("%ld",&n)==1)
	{
		printf("%ld ",counter[n]);
		temp1=n/2;
		for(i=1;i<=n;i++)
			temp_flag[i]=0;
		for(i=0;i<total_triple;i++)
		{
			if(triple[i].z>n)continue;
			if(triple[i].z<=temp1)
			{
				temp2=n/triple[i].z;
				for(j=1;j<=temp2;j++)
					temp_flag[j*triple[i].x]=temp_flag[j*triple[i].y]=temp_flag[j*triple[i].z]=1;
			}
			else
			{
				temp_flag[triple[i].x]=temp_flag[triple[i].y]=temp_flag[triple[i].z]=1;
			}
		}
		sum=0;
		for(i=1;i<=n;i++)
			if(!temp_flag[i])
				sum++;
		printf("%ld\n",sum);
	}
	return 0;
}

long int gcd(long int u,long int v)
{
	long int t;
	while(v!=0)
	{
		t=v;
		v=u%v;
		u=t;
	}
	return u;
}
/* @end_of_source_code */
