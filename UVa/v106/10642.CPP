#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	int sx,sy,n,dx,dy,rs,rd,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&sx,&sy,&dx,&dy);
		rs=((sx+sy)*(sx+sy+1))/2+sx+1;
		rd=((dx+dy)*(dx+dy+1))/2+dx+1;
		printf("Case %d: %d\n",i+1,rd-rs);
	}
	return 0;
}













