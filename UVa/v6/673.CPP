#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n,i,j,k,l,flag,found,count;
	char s[150],t;
	scanf("%d",&n);
	t=getchar();
	for(i=0;i<n;i++)
	{
		gets(s);
		flag=1;
		for(j=0;s[j] && flag;j++)
		{
			if(s[j]==')')
			{
				for(k=j-1,found=0;k>=0 && !found;k--)
				{
					if(s[k]=='(')
					{
						found=1;
						for(l=k,count=0;l<=j;l++)
						{
							if(s[l]=='[')count++;
							else if(s[l]==']')count--;
							if(count<0)flag=0;
							s[l]='*';
						}
						if(count)flag=0;
					}
				}
				if(!found)flag=0;
			}
		}
		for(j=0;s[j] && flag;j++)
		{
			if(s[j]==']')
			{
				for(k=j-1,found=0;k>=0 && !found;k--)
				{
					if(s[k]=='[')
					{
						found=1;
						for(l=k;l<=j;l++)
							s[l]='*';
					}
				}
				if(!found)flag=0;
			}
		}
		for(j=0;s[j] && flag;j++)
			if(s[j]=='('||s[j]==')'||s[j]=='['||s[j]==']')
				flag=0;
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}













