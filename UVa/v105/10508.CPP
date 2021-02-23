#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<list>
using namespace std;

struct word
{
	char s[1005];
	int dif;
}*w;

bool operator<(word a,word b)
{
	return a.dif<b.dif;
}

int main()
{
	int n,m,i,j,cnt;
	while(scanf("%d%d",&n,&m)==2)
	{
		w=(word *)calloc(n,sizeof(word));
		for(i=0;i<n;i++)
		{
			scanf("%s",w[i].s);
			if(i==0)
				w[i].dif=0;
			else
			{
				for(j=cnt=0;w[i].s[j];j++)
					if(w[0].s[j]!=w[i].s[j])
						cnt++;
				w[i].dif=cnt;
			}
		}
		sort(w,w+n);
		for(i=0;i<n;i++)
			printf("%s\n",w[i].s);
		free(w);
	}
	return 0;
}

