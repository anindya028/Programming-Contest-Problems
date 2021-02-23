//Tricky simulation
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct train
{
	int no,tm;
}*trum;
bool operator<(train A,train B)
{
	return A.tm<B.tm;
}
int main()
{
	int t,i,bs,dbs,k,j,m,n,cs=0;
	char s[1000];
	while(scanf("%d",&t)==1)
	{
		if(!t)break;
		gets(s);
		trum=(train *)calloc(t*50,sizeof(train));
		k=0;
		for(i=0;i<t;i++)
		{
			gets(s);
			bs=0;
			sscanf(s+bs,"%d:%n",&j,&dbs);
			bs+=dbs;
			while(sscanf(s+bs,"%d%n",&trum[k].tm,&dbs)==1)
			{
				if(trum[k].tm<0)break;
				bs+=dbs;
				trum[k].no=j;
				k++;
			}
		}
		gets(s);
		sscanf(s,"%d%d",&m,&n);
		sort(trum,trum+k);
		for(i=0;trum[i].tm<m;i++);
		if(n<k)printf("Case %d: Peter arrives at stop %d by tram %d.\n",++cs,n,trum[n-1].no);
		else if((n-k+i)%k==0)printf("Case %d: Peter arrives at stop %d by tram %d.\n",++cs,n,trum[k-1].no);
		else printf("Case %d: Peter arrives at stop %d by tram %d.\n",++cs,n,trum[(n-k+i)%k-1].no);
		free(trum);
	}
	return 0;
}













