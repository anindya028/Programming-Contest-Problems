#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int r,c,col,ans;
	while(scanf("%d%d%d",&r,&c,&col)==3)
	{
		if(!r && !c && !col)break;
		if(col)
		{
			ans=((c-6)/2)*((r-6)/2)+((c-7)/2)*((r-7)/2);
			printf("%d\n",ans);
		}
		else
		{
			ans=((c-7)/2)*((r-6)/2)+((c-6)/2)*((r-7)/2);
			printf("%d\n",ans);
		}
	}
	return 0;
}













