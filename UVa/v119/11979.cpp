#include<stdio.h>
#include<algorithm>

using namespace std;

#define mabs(a) ((a)>0?(a):-(a))

int arr[15][2039];

int main()
{
	int cs,T,i,j,ret,n,m;
	scanf("%d",&T);
	for(cs = 1; cs <= T; cs++)
	{
		scanf("%d%d",&n,&m);

		for( i = 0; i < n; i++)
			for( j = 0; j < m; j++)
				scanf("%d",&arr[j][i]);

		ret = 0;

		for(j = 0; j < m; j++)
		{
			sort(arr[j],arr[j]+n);

			for( i = 0; i < n; i++)
				ret += mabs(i - arr[j][i]);
		}

		printf("Case %d: %d\n",cs,ret);
	}
	return 0;
}