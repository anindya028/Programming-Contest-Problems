#include<stdio.h>

int main()
{
	int n,m,i,cnt1,cnt2;
	while(scanf("%d%d",&n,&m)==2)
	{
		cnt1=cnt2=0;
		for(i=2;i<1000;i++)
			while(n%i==0)
				n/=i,cnt1++;
		for(i=2;i<1000;i++)
			while(m%i==0)
				m/=i,cnt2++;
		if(cnt1>cnt2)
			printf("Win\n");
		else
			printf("Lose\n");
	}
	return 0;
}