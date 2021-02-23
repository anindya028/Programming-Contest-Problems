//Adhoc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
int main()
{
	char s[1000005];
	int length[1000005],i,n,p,q,temp,cs=0;
	while(gets(s))
	{
        if(s[0]==EOF||s[0]=='\0')break;
		printf("Case %d:\n",++cs);
		length[0]=1;
		for(i=1;s[i];i++)
		{
			if(s[i]==s[i-1])length[i]=length[i-1]+1;
			else length[i]=1;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&p,&q);
			if(p==q)
			{
				printf("Yes\n");
				continue;
			}
			if(p>q)
			{
				temp=p;
				p=q;
				q=temp;
			}
			if((q-p+1)==(length[q]-length[p]+1))printf("Yes\n");
			else printf("No\n");
		}
		gets(s);
        }
	return 0;
}













