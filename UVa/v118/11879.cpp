#include<stdio.h>
#include<string.h>

int main()
{
	char s[1005];
	int i,res;
	while(scanf("%s",s)==1)
	{
		if(!strcmp(s,"0"))
			break;
		res=0;
		for(i=0;s[i];i++)
			res=(res*10+(s[i]-'0'))%17;
		printf("%d\n",!res);
	}
	return 0;
}