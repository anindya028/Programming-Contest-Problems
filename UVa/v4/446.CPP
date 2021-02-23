#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//#define Long __int64
//#define Long long long
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
	int n,i,n1,n2,j,ans;
	char s[20],bin1[50],bin2[50],s1[5],s2[5],oper;
	scanf("%d",&n);
	gets(s);
	for(i=0;i<n;i++)
	{
		gets(s);
                n1=n2=0;
		sscanf(s,"%s %c%s",s1,&oper,s2);
		rev(s1);
		rev(s2);
		for(j=0;s1[j];j++)
		{
			if(isalpha(s1[j]))n1+=((s1[j]-'A'+10)*(int)pow(16,j));
			else n1+=((s1[j]-'0')*(int)pow(16,j));
		}
		for(j=0;s2[j];j++)
		{
			if(isalpha(s2[j]))n2+=((s2[j]-'A'+10)*(int)pow(16,j));
			else n2+=((s2[j]-'0')*(int)pow(16,j));
		}
		if(oper=='+')ans=n1+n2;
                else ans=n1-n2;
		for(j=0;n1;j++)
		{
			bin1[j]=(char)((n1%2)+'0');
			n1/=2;
		}
		for(;j<13;j++)bin1[j]='0';
		bin1[j]='\0';
		rev(bin1);
		for(j=0;n2;j++)
		{
			bin2[j]=(char)((n2%2)+'0');
			n2/=2;
		}
		for(;j<13;j++)bin2[j]='0';
		bin2[j]='\0';
		rev(bin2);
		printf("%s %c %s = %d\n",bin1,oper,bin2,ans);
	}
	return 0;
}













