#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
//#define Long __int64
//#define Long long long
struct elephant
{
	int ind,w,s;
}ele[1005];
bool operator<(elephant A,elephant B)
{
	if(A.s==B.s)return A.w<B.w;
	return A.s>B.s;
}
int main()
{
	int i=0,n,*parent,*seq,*l,j,len,max;
	while(scanf("%d%d",&ele[i].w,&ele[i].s)==2)
		ele[i++].ind=i+1;
	sort(ele,ele+i);
	n=i;
	parent=(int *)calloc(1005,sizeof(int));
	seq=(int *)calloc(1005,sizeof(int));
	l=(int *)calloc(1005,sizeof(int));
	len=0;
	for(i=l[0]=1;i<n;i++)
	{
		max=0;
		for(j=0;j<i;j++)
		{
			if(ele[j].w<ele[i].w && ele[j].s>ele[i].s)
			{
				if(l[j]>max)
				{
					max=l[j];
					parent[i]=j;
				}
			}
		}
		l[i]=max+1;
		if(l[i]>len)
		{
			len=l[i];
			seq[0]=i;
		}
	}
	for(j=1;j<len;j++)
		seq[j]=parent[seq[j-1]];
	printf("%d\n",len);
	for(i=len-1;i>=0;i--)printf("%d\n",ele[seq[i]].ind);
	free(parent);
	free(seq);
	free(l);
	return 0;
}












