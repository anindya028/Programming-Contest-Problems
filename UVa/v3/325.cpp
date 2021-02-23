#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char line[10005],s[10005];
	int j,flag,len,digit=0,point;
	while(gets(line))
	{
		if(line[0]=='*')break;
		sscanf(line,"%s",s);
		flag=1;
		point=j=digit=0;
		len=strlen(line);
		while(line[j]==' ')
			j++;
		if(line[j]=='+' || line[j]=='-' && j<len)
		{
			if(!isdigit(line[j+1]))
				flag=0;
			j++;
		}
		if(j==len)
		{
			if(flag && digit && point)printf("%s is legal.\n",s);
			else printf("%s is illegal.\n",s);
			continue;
		}
		while(isdigit(line[j]))
		{
			j++;
			digit++;
		}
		/*while(line[j]==' ')
			j++;*/
		if(j==len)
		{
			if(flag && digit && point)printf("%s is legal.\n",s);
			else printf("%s is illegal.\n",s);
			continue;
		}
		if(line[j]!='.' && line[j]!=' ' && line[j]!='e' && line[j]!='E')
			flag=0;
		if(line[j]=='.' || line[j]=='e' || line[j]=='E')
			point=1;
		if(point && !digit)
		{
			printf("%s is illegal.\n",s);
			continue;
		}
		if((line[j]=='e' || line[j]=='E')&& (line[j+1]=='+' || line[j+1]=='-'))
			j+=2;
		else if(line[j]=='.'|| line[j]=='e' ||line[j]=='E')j++;
		digit=0;
		if(j==len)
		{
			if(flag && digit && point)printf("%s is legal.\n",s);
			else printf("%s is illegal.\n",s);
			continue;
		}
		while(isdigit(line[j]))
		{
			j++;
			digit++;
		}
		if(j==len || (point && !digit))
		{
			if(flag && digit && point)printf("%s is legal.\n",s);
			else printf("%s is illegal.\n",s);
			continue;
		}
		while(line[j]==' ')
			j++;
		if(j==len && point)
		{
			if(flag && digit)printf("%s is legal.\n",s);
			else printf("%s is illegal.\n",s);
			continue;
		}
		if(j!=len && line[j-1]==' ')
		{
			printf("%s is illegal.\n",s);
			continue;
		}
		if(line[j]!='e' && line[j]!='E' && j<len)
			flag=0;
		if(j==len)
		{
			if(flag && point)printf("%s is legal.\n",s);
			else printf("%s is illegal.\n",s);
			continue;
		}
		j++;
		if(line[j]=='+' || line[j]=='-')
			j++;
		digit=0;
		while(isdigit(line[j]))
		{
			j++;
			digit++;
		}
		while(line[j]==' ')
			j++;
		if(line[j]!='\0')
			flag=0;
		if(flag && digit && point)
			printf("%s is legal.\n",s);
		else printf("%s is illegal.\n",s);
	}
	return 0;
}