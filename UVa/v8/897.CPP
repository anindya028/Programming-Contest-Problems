#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	



int main()
{
	int p[]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,331,337,373,733,919,991,0};
	int n,i;
	while(scanf("%d",&n)==1 && n)
	{
		i=0;
		if((n>=7 && n<10) || (n>=97 && n<100) || (n>=991))
		{
			printf("0\n");
			continue;
		}
		while(p[i]<=n)
		{
			i++;
			if(p[i]==0)
				break;
		}
		printf("%d\n",p[i]);
	}
	return 0;
}
