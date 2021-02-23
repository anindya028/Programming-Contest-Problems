#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

struct work
{
	int d,f;
	int no;
}w[1005];

bool operator<(work a,work b)
{
	return a.f*b.d>b.f*a.d;
}

int main()
{
	int t,i,n,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		if(cs)
			printf("\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&w[i].d,&w[i].f);
			w[i].no=i+1;
		}
		stable_sort(w,w+n);
		printf("%d",w[0].no);
		for(i=1;i<n;i++)
			printf(" %d",w[i].no);
		printf("\n");
	}
	return 0;
}
