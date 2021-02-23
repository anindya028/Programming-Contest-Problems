#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int t,cs;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		int t1,t2,fin,at,ct[3];
		scanf("%d%d%d%d%d%d%d",&t1,&t2,&fin,&at,&ct[0],&ct[1],&ct[2]);
		sort(ct,ct+3);
		int tot=(t1+t2+fin+at)*2+ct[2]+ct[1];
		printf("Case %d: ",cs+1);
		if(tot>=180)
			puts("A");
		else if(tot>=160)
			puts("B");
		else if(tot>=140)
			puts("C");
		else if(tot>=120)
			puts("D");
		else
			puts("F");
	}
	return 0;
}