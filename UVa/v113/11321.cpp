
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

#define SIZE 10009

class point
{
public:
	int val;
	int prev;	
};

bool comp(const point& B, const point& A)
{
	if(A.val!=B.val)//different modulas
		return B.val<A.val;

	if(B.prev&1 && A.prev&1 )//both odd
		return B.prev>A.prev;

	if(!(B.prev&1) && !(A.prev&1) )//both even
		return B.prev<A.prev;

	return B.prev&1;//odd one preceed
}

point P[SIZE];

int main(void)
{
	int N,M;
	int i;
	while(true)
	{
		scanf("%d%d",&N,&M);
		if(N==0 && M==0)
			break;
		for(i=0;i<N;i++)
		{
			scanf("%d",&P[i].prev);
			P[i].val=P[i].prev%M;			
		}
		sort(P,P+N,comp);
		printf("%d %d\n",N,M);

		for(i=0;i<N;i++)
			printf("%d\n",P[i].prev);
	}
	printf("%d %d\n",N,M);
	return 0;
}