#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<queue>
#include<list>
#include<vector>
#include<string>
using namespace std;	

//#define Long __int64
//#define Long long long
struct problem
{
	char name[30][100];
	int k;
	bool taken;
}p[30];

struct answer
{
	char s[100];
}ans[30];

bool operator<(answer a,answer b)
{
	return strcmp(a.s,b.s)<0;
}

int main()
{
	int t,cs,i,j,n,freq[26],num,got,l;
	scanf("%d",&t);
	for(cs=0;cs<t;cs++)
	{
		printf("Case #%d:\n",cs+1);
		scanf("%d",&n);
		for(i=0;i<26;i++)
			freq[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&p[i].k);
			p[i].taken=false;
			for(j=0;j<p[i].k;j++)
			{
				scanf("%s",p[i].name[j]);
				p[i].name[j][0]=toupper(p[i].name[j][0]);
				freq[p[i].name[j][0]-'A']++;
				for(l=1;p[i].name[j][l];l++)
					p[i].name[j][l]=tolower(p[i].name[j][l]);
			}
		}
		num=0;
		while(num<n)
		{
			for(i=0;i<n;i++)
				if(freq[i]==1)
				{
					got=0;
					for(j=0;j<n && !got;j++)
						if(!p[j].taken)
						{
							for(l=0;l<p[j].k;l++)
								if((p[j].name[l][0]-'A')==i)
								{
									got=1;
									strcpy(ans[num].s,p[j].name[l]);
									p[j].taken=true;
									num++;
									break;
								}
							for(l=0;l<p[j].k && got;l++)
								freq[p[j].name[l][0]-'A']--;
						}
				}
		}
		sort(ans,ans+num);
		for(i=0;i<num;i++)
			printf("%s\n",ans[i].s);
	}
	return 0;
}
