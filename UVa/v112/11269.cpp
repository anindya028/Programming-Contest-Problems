#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

#define SIZE 150
#define Max(A,B) (((A)>(B))?(A):(B))

typedef struct{
	int a,b;
}prob;

prob arr[SIZE];
int last[SIZE];


/*int comp(const void *ai,const void *bi){
	prob *x=(prob *)ai,*y=(prob *)bi;

	return ((x->a+Max(x->b,y->a)+y->b) - (y->a+Max(y->b,x->a)+x->b));
}*/

bool operator<(prob p,prob q)
{
	int tpq,tqp;
	tpq=p.a+Max(p.b,q.a)+q.b;
	tqp=q.a+Max(q.b,p.a)+p.b;
	return tpq<tqp;
}

int main()
{
	int i,n,tot;	

	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
			scanf("%d",&arr[i].a);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i].b);

		//qsort(arr,n,sizeof(prob),comp);
		sort(arr,arr+n);
		last[0]=arr[0].a;
		for(i=1;i<n;i++)
			last[i]=last[i-1]+arr[i].a;
		tot=arr[0].a;
		for(i=0;i<n;i++)
		{
			if(last[i]<=tot)
				tot+=arr[i].b;
			else
			{
				tot=last[i];
				tot+=arr[i].b;
			}
		}

		printf("%d\n",tot);
	}

	return 0;
}