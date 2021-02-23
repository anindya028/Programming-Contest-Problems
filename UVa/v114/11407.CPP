//Typical DP
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;	

#define size 105
int sack[size*size];

int main()
{
	int t,n,coin[size];
	register int i,j; 
	for(i=1;i<size;i++)
		coin[i]=i*i;
	for(i=1;i<size*size;i++)
		sack[i]=-1;
	sack[0]=0;
	for(i=1;i<size;i++)
		for(j=0;j<size*size;j++)
			if(sack[j]>=0)
				if(j+coin[i]<size*size)
					if(sack[j]+1<sack[j+coin[i]] || sack[j+coin[i]]==-1)
						sack[j+coin[i]]=sack[j]+1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",sack[n]);
	}
	return 0;
}
