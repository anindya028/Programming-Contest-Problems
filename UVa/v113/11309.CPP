//Adhoc
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

bool palin(char s[])
{
	if(s[0]=='0')
	{
		if(s[1]=='0')
		{
			if(s[3]=='0')
				return true;
			else return s[3]==s[4];
		}
		else return s[1]==s[4];
	}
	else return (s[0]==s[4] && s[1]==s[3]);
}				

int main()
{
	int i,t,tim,h,m;
	char s[10],ans[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		tim=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
		if(tim>=1412)
		{
			printf("00:00\n");
			continue;
		}
		for(i=tim+1;;i++)
		{
			h=i/60;
			m=i%60;
			ans[0]=h/10+'0';
			ans[1]=h%10+'0';
			ans[2]=':';
			ans[3]=m/10+'0';
			ans[4]=m%10+'0';
			ans[5]='\0';
			if(palin(ans))
				break;
		}
		printf("%s\n",ans);
	}
	return 0;
}













