//Easy DP 
#include<stdio.h>
typedef unsigned long long datatype;

datatype co[65][65];

datatype trib(int n, int back)
{
    datatype count=0;
    int i;
    count++;

    if(n<=1) return 1;
	if(co[n][back])
		return co[n][back];
    for(i=1;i<=back;i++)
         count+=trib(n-i,back);
	co[n][back]=count;
    return co[n][back];

}

int main()

{
	int n,m,cs=0;
	while(scanf("%d%d",&n,&m)==2)
	{ 
		if(n>60)
			break;
		printf("Case %d: %llu\n",++cs,trib(n,m));
	}
	return 0;
}

 