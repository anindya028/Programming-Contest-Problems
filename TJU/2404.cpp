#include<stdio.h>
#include<algorithm>

using namespace std;

int data[100005],ok[100005];

int main()
{
	int n,i,j,cnt,len;
	while(scanf("%d",&n)==1)
	{
		scanf("%d",&len);
		for(i=0;i<n;i++)
			scanf("%d",&data[i]),ok[i]=0;
		
		sort(data,data+n);

	//	for(i=0;i<n;i++)
	//		printf("%d ",data[i]);

		for(i=cnt=0,j=n-1;i<n;i++)
		{
			if(ok[i])
				continue;
			while(j>i && data[j]+data[i]>len)
				j--;
			if(j>i && data[j]+data[i]<=len)
			{
				ok[j]=1;
				j--;
			}
			ok[i]=1;
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}