#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)==3)
	{
		if(!n && !m && !k)
			break;
		if(m%2)printf("Keka\n");
		else printf("Gared\n");
	}	
	return 0;
}













