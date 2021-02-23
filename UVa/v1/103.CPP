#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
int n;
struct box
{
	int dim[20];
	int num;
}b[40],temp;

bool comp(box p,box q)
{
	int i;
	bool flag=true;
	for(i=0;i<n;i++)
		if(p.dim[i]>=q.dim[i])
			flag=false;

	return flag;
}
/*bool operator<(box p,box q)
{
	return comp(p,q);
}*/
int main()
{
	int i,j,k,l[40],parent[40],seq[40],len,max;
	while(scanf("%d%d",&k,&n)==2)
	{
		for(i=0;i<k;i++)
		{
			for(j=0;j<n;j++)
				scanf("%d",&b[i].dim[j]);
			sort(b[i].dim,b[i].dim+n);
			b[i].num=i+1;
		}
		//sort(b,b+k);
		for(i=0;i<k;i++)
			for(j=i+1;j<k;j++)
				if(comp(b[j],b[i]))
				{
					temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
		l[0]=1;
		len=1;
		for(i=0;i<k;i++)
			parent[i]=i;
		seq[0]=0;
		for(i=1;i<k;i++)
		{
			max=0;
			for(j=0;j<i;j++)
			{
				if(comp(b[j],b[i]))
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
				seq[0]=i;
				len=l[i];
			}
		}
		i=j=0;
		while(parent[seq[j]]!=seq[j])
		{
			i++;
			seq[i]=parent[seq[j]];
			j++;
		}
		printf("%d\n",len);
		printf("%d",b[seq[len-1]].num);
		for(i=len-2;i>=0;i--)
			printf(" %d",b[seq[i]].num);
		printf("\n");
	}
	return 0;
}













