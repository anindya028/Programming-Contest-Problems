#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
using namespace std;
#define myabs(a) (((a)>0)?(a):-(a))
#define Max(a,b) (((a)>(b))?(a):(b))
int main()
{
	int num[100],n,i,j,sum,cs,t,c[100],temp1,temp2,temp3,temp4,k,st,end,m;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		if(n==2)
		{
			printf("Case %d: %d\n",cs+1,myabs(num[0]-num[1]));
			continue;
		}
		j=50;
		c[j]=num[n-1];
		c[j+1]=num[0];
		sum=num[n-1]-num[0];
		i=1;
		k=n-i-1;
		st=j;
		end=j+1;
		while(i<=k)
		{
			temp1=myabs(c[st]-num[i]);
			temp2=myabs(c[end]-num[i]);
			temp3=myabs(c[st]-num[k]);
			temp4=myabs(c[end]-num[k]);
			m=Max(temp1,Max(temp2,Max(temp3,temp4)));
			if(m==temp1)
			{
				st--;
				c[st]=num[i];
				i++;
			}
			else if(m==temp2)
			{
				end++;
				c[end]=num[i];
				i++;
			}
			else if(m==temp3)
			{
				st--;
				c[st]=num[k];
				k--;
			}
			else
			{
				end++;
				c[end]=num[k];
				k--;
			}
			sum+=m;
		}
		printf("Case %d: %d\n",cs+1,sum);
	}
	return 0;
}













