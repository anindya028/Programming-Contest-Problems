#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
	char s[105][105],ne;
	int t,i,m,n,q,r,c,j,len,k,flag;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d%d",&m,&n,&q);
		for(j=0;j<m;j++)
				scanf("%s",s[j]);
		printf("%d %d %d\n",m,n,q);
		for(j=0;j<q;j++)
		{
			scanf("%d%d",&r,&c);
			if(r>=m && c>=n)
			{
				printf("0\n");
				continue;
			}
			ne=s[r][c];
			len=1;
			while(1)
			{
				if((r-len)<0 || (c-len)<0 || (r+len)>=m || (c+len)>=n)
					break;
				flag=1;
				for(k=r-len;k<=(r+len) && flag;k++)
					if(s[k][c-len]!=ne)
						flag=0;
				for(k=r-len;k<=(r+len) && flag;k++)
					if(s[k][c+len]!=ne)
						flag=0;
				for(k=c-len;k<=(c+len) && flag;k++)
					if(s[r-len][k]!=ne)
						flag=0;
				for(k=c-len;k<=(c+len) && flag;k++)
					if(s[r+len][k]!=ne)
						flag=0;
				if(flag)
					len++;
				else break;
			}
			printf("%d\n",2*len-1);
		}
	}
	return 0;
}













