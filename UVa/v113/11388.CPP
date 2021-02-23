//Faltu
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>
using namespace std;

//#define Long __int64
//#define Long long long	

int main()
{
	int a,b,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(b%a)
			printf("-1\n");
		else
			printf("%d %d\n",a,b);
	}
	return 0;
}
