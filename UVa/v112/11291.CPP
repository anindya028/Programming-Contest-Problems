#include<stdio.h>
#include<string.h>

char s[100005];

bool digit(char ch)
{
	return (ch>='0' && ch<='9');
}

double process(int st,int nd)
{
	int i=st;
	while(!digit(s[i]) && s[i]!='.' && s[i]!='-')
		i++;
	char ss[1005];
	int j=0;
	while(i<=nd && s[i]!=' ')
		ss[j++]=s[i++];
	ss[j]=0;
	while(i<=nd && s[i]==' ')
		i++;
	double p;
	sscanf(ss,"%lf",&p);
	if(i>nd)
		return p;

	int cnt=0;
	while(s[i]!='(' && !digit(s[i]) && s[i]!='-')
		i++;
	int st1=i;
	i++;
	if(s[i-1]=='(')
		while(s[i]!=')' || cnt)
		{
			if(s[i]=='(')
				cnt++;
			else if(s[i]==')')
				cnt--;
			i++;
		}	
	else
		while(s[i]=='-' || digit(s[i]))
			i++;
	int nd1=i;

	cnt=0;
	while(s[i]!='(' && !digit(s[i]) && s[i]!='-')
		i++;
	int st2=i;
	i++;
	if(s[i-1]=='(')
		while(s[i]!=')' || cnt)
		{
			if(s[i]=='(')
				cnt++;
			else if(s[i]==')')
				cnt--;
			i++;
		}	
	else
		while(s[i]=='-' || digit(s[i]))
			i++;
	int nd2=i;
	
	double x=process(st1,nd1);
	double y=process(st2,nd2);
	return (p*(x+y)+(1-p)*(x-y));
}

int main()
{
	while(gets(s))
	{
		if(strcmp(s,"()")==0)		
			break;
		printf("%.2lf\n",process(0,strlen(s)-1));
	}
	return 0;
}