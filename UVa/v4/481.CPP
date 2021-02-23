#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
using namespace std;
//#define Long __int64
//#define Long long long
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
	int a[100000];
        unsigned i=0;
		while(scanf("%d",&a[i])==1)i++;
	vector<int> seq(a,a+sizeof(a)/sizeof(a[0]));
	vector<int> lis=find_lis(seq);
	printf("%d\n-\n",lis.size());
	for(i=0;i<lis.size();i++)
		printf("%d\n",seq[lis[i]]);	
	return 0;
}













