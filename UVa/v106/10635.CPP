#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
template<typename T> vector<int> find_lis(vector<T> a)
{
	vector<int> b,p(a.size());
	int u,v,c,i;
	if(a.size()<1)return b;
	b.push_back(0);
	for(i=1;i< (int)a.size();i++)
	{
		if(a[b.back()]<a[i])
		{
			p[i]=b.back();
			b.push_back(i);
			continue;
		}
		for(u=0,v=b.size()-1;u<v;)
		{
			c=(u+v)/2;
			if(a[b[c]]<a[i])u=c+1;
			else v=c;
		}
		if(u<=v && a[i]<a[b[u]])
		{
			if(u>0)p[i]=b[u-1];
			b[u]=i;
		}
	}
	for(u=b.size(),v=b.back();u--;v=p[v])b[u]=v;
	return b;
}
int main()
{
	int *pos1,num[63000],i,j,t,n,p,q,r,k=0;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d",&n,&p,&q);
		pos1=(int *)calloc((n*n+1),sizeof(int));
		//num=(int *)calloc(n*n+1,sizeof(int));
		for(j=1;j<=p+1;j++)
		{
			scanf("%d",&r);
			pos1[r]=j;
		}
		for(j=k=0;j<=q;j++)
		{
			scanf("%d",&r);
			if(pos1[r])
			{
				num[k]=pos1[r];
				k++;
			}
		}
		/*for(j=0;j<=q;j++)
			printf("%d ",num[j]);*/
		vector<int> seq(num,num+k);
		vector<int> lis=find_lis(seq);
		printf("Case %d: %d\n",i+1,lis.size());
		//lis.clear();
		///seq.clear();
		free(pos1);
		//free(num);
	}
	return 0;
}













