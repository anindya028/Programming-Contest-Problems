#include<stdio.h>
#include<string.h>

bool isvow(char a)
{
	return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u');
}

int main()
{
	int t,i;
	char s1[30],s2[30];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s1,s2);
		if(strlen(s1)==strlen(s2))
		{
			int ok=1;
			for(i=0;s1[i];i++)
			{
				if(isvow(s1[i]) && isvow(s2[i]))
					continue;
				if(s1[i]!=s2[i])
					ok=0;
			}
			if(ok)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
	return 0;
}