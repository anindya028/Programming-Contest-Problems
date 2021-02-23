#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int str2bin(char s[])
{
//	reverse(s,s+strlen(s));
	int i=0,ret=0;
	while(s[i])
	{
		if(s[i]=='1')
			ret=2*ret+1;
		else
			ret*=2;
		i++;
	}
	return ret;
}

void print(long long now)
{
	char s[]="0000000000000000000000000000000";
	int i;
	for(i=0;i<31;i++)
		if(now & 1<<i)
			s[30-i]='1';
	printf("%s",s);
}

int main()
{
	int t,cs=0;
	long long a,b,c,d;
	char sa[100],sb[100];
	scanf("%d",&t);
	while(t--)
	{
		if(cs)
			printf("\n");
		scanf("%s%s",sa,sb);
	//	printf("%s %s\n",sa,sb);
		cs++;
		a=str2bin(sa);
		b=str2bin(sb);
		print(a),printf(" "),print(b),printf("\n");
		while(b)
		{
			c= a ^ b;
			d= a & b;
			if(d & 1<<30  || !d)
				break;
			else
				print(c),printf(" "),d*=2,print(d),printf("\n");
			a=c,b=d;
		}
		print(c),printf(" ");
		if(d & 1<<30)
			printf("overflow\n");
		else
			print(d),printf("\n");
	}
	return 0;
}