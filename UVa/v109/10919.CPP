#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
/*struct course
{
	int req;

	int num[100];
}cor[100];*/
int main()
{
	int m,k,c,i,j,l,taken[100],num[100],flag,count,r;
	while(scanf("%d",&k)==1 && k)
	{
        	flag=1;
        	scanf("%d",&m);
		for(i=0;i<k;i++)scanf("%d",&taken[i]);
		for(i=0;i<m;i++)
		{
                	scanf("%d%d",&c,&r);
			for(j=0;j<c;j++)scanf("%d",&num[j]);
			for(j=count=0;j<c && flag;j++)
                        	for(l=0;l<k;l++)
					if(num[j]==taken[l])count++;
			if(count<r)flag=0;
		}
		if(flag)printf("yes\n");
		else printf("no\n");
	}
	return 0;               	

}













