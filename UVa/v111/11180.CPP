#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
	int n,i,a,b,j,temp;
	char ans[100000];
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			if(!a && !b)
			{
				printf("Case #%d: 0\n",i+1);
				continue;
			}
			for(j=0;;j++)
			{
				if(!a && !b)break;
				if((a+b)%2)ans[j]='1';
				else ans[j]='0';
				a-=(ans[j]-'0');
				temp=a;
				a=b-a;
				b=-temp-b;
				a/=2;
				b/=2;
			}
			ans[j]='\0';
			rev(ans);
			printf("Case #%d: %s\n",i+1,ans);
			ans[0]='\0';
		}
	}
	return 0;
}













