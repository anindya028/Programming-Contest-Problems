#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long
void rev(char *t)
{
	int i=0,j=strlen(t)-1;
	char temp;
	while(i<j)
	{
	        temp=t[i];
		t[i]=t[j];
		t[j]=temp;
		i++;
		j--;
	}
	return;
}
int main()
{
	char s[20],ans[20];
        int num,i=0;
	while(scanf("%s",s)==1)
	{
		num=(((s[0]-'0')*10+s[1]-'0')*3600+((s[2]-'0')*10+s[3]-'0')*60+(s[4]-'0')*10+s[5]-'0'))*100+(s[6]-'0')*10+s[7]-'0';
		num=(num*125)/108;
		sprintf(ans,"%d",&num);
		if(strlen(ans)<7)
		{
			rev(ans);
			for(i=0;ans[i];i++);
			for(;i<7;i++)ans[i]='0';
			ans[i]='\0';
			rev(ans);
		}
		printf("%s\n",ans);
	}
	return 0;
}













