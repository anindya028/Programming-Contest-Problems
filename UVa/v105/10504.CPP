#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;


char s[105][105];

int main()
{
	register int i,j,k,l;
	int n,m,cs=0,cnt,dx,dy;
	char d[15];
	while(scanf("%d",&n)==1)
	{
		if(!n)
			break;
		if(cs)
			printf("\n");
		scanf("%d",&m);
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		while(m--)
		{
			scanf("%s",d);
			for(i=cnt=0;i<n;i++)
				for(j=0;j<n;j++)
					if(d[0]==s[i][j])
						for(k=i;k<n;k++)
							for(l=j+1;l<n;l++)
								if(d[0]==s[k][l])
								{
									dx=k-i;
									dy=l-j;
									if((k+dy)<n && (l-dx)>=0 && (i+dy)<n && (j-dx)>=0)
										if(s[k+dy][l-dx]==d[0] && s[i+dy][j-dx]==d[0])
											cnt++;
								}

			printf("%s %d\n",d,cnt);
		}
		cs++;
	}

	return 0;
}

