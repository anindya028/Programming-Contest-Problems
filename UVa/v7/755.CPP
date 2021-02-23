#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
struct tele
{
	long num;
    char sp[8];
}ph[100005];
bool operator<(tele a,tele b)
{
	return a.num<b.num;
}
int main()
{
	long n,i,j,k,l,cs,t,printed;
	char s[100],temp[100];
	int code[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
	scanf("%ld",&cs);
	while(cs--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0,l=0;s[j];j++)
				if(isalnum(s[j]))
					if(isalpha(s[j]))
						temp[l++]='0'+code[s[j]-'A'];
					else
						temp[l++]=s[j];
            temp[l]='\0';
			sscanf(temp,"%ld",&ph[i].num);
			strcpy(ph[i].sp,temp);
		}
		sort(ph,ph+n);
		printed=0;
		for(i=0;i<n;)
		{
			k=1;
			t=ph[i].num;
			i++;
			while(t==ph[i].num)
			{
				i++;
				k++;
			}
			if(k>1)
			{
				for(j=0;ph[i-1].sp[j];j++)
				{
					if(j==3)printf("-%c",ph[i-1].sp[j]);
					else printf("%c",ph[i-1].sp[j]);
				}
				printf(" %ld\n",k);
				printed++;
			}
		}
		if(!printed)printf("No duplicates.\n");
		if(cs)printf("\n");
	}
	return 0;
}













