#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define LL long long

char buf[10005];
int coef[105],e;

bool issign(char u)
{
	return (u=='+' || u=='-');
}

void placep(void)
{
	if(issign(buf[1]))
		return;
	int i = strlen(buf);
	for(;i>=1;i--)
		buf[i+1] = buf[i];
	buf[1] = '+';
}

void process(char s[])
{
//	printf("%s\n",s);
	int sign = s[0]=='+' ? 1 : -1;
	int val = 0;
	int i = 1;
	while(isdigit(s[i]) && s[i])
		val = val*10 + s[i] - '0',
		i++;
	if(!s[i])
	{
		coef[0] = val * sign;
		if(e==-1)
			e = 0;
		return;
	}
	if(!val)
		val=1;
	while(!isdigit(s[i]) && s[i])
		i++;
	int p = 0;
	while(isdigit(s[i]) && s[i])
		p = p*10 + s[i] - '0',
		i++;
	if(!p)
		p = 1;
	if(e<p)
		e=p;
	coef[p] = val*sign;
	//printf("%d %d\n",p,coef[p]);
}

LL modpow(LL b,LL p,LL mod)
{
	if(!p)
		return 1%mod;
	if(p%2)
	{
		LL now = modpow(b,p-1,mod);
		return (now*b)%mod;
	}
	else
	{
		LL now = modpow(b,p/2,mod);
		return (now*now)%mod;
	}
}

bool check(int val,int d)
{
	LL sum = 0;
	int i;
	for(i=0;i<=e;i++)
	{
		LL v = (coef[i] * modpow(val,i,d))%d;
		sum = (sum + v)%d;
	}
	return (sum!=0);
}

int main()
{
	int i,j,k,cs=0;
	while(scanf("%s",buf)==1)
	{
		if(buf[0]=='.')
			break;
		memset(coef,0,sizeof(coef));
		e = -1;
		placep();
		i=1;
		while(buf[i]!=')')
		{
			char temp[105];
			temp[0] = buf[i];
			j = i+1;
			k = 1;
			while(!issign(buf[j]) && buf[j]!=')')
				temp[k++] = buf[j++];
			temp[k] = 0;
			process(temp);
			i=j;
		}
		i+=2;
		int d=0;
		while(buf[i])
			d = d*10 + buf[i] - '0',
			i++;

		int f=1;
		for(i=1;i<=e+2;i++)
			if(check(i,d))
				f=0;

		if(f)
			printf("Case %d: Always an integer\n",++cs);
		else
			printf("Case %d: Not always an integer\n",++cs);
	}
	return 0;
}