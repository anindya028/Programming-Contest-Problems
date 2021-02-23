/* 10844 - Bloques code of sunny bhaia*/
/* 11 May, 2005 */
#include<stdio.h>

#define size1 905
#define size2 200
#define base 1000000000

long int len1,len2;
long int n;

long int tri[size1][size2],prev[size1][size2];
long int len[size1][size1];
long int final[size1][size2];


void initialize();

long int add(long int *n1,long int *n2,long int *r)
{
	bool f;
	long int res[size2];
	register long int i,carry,t;
	register long int min_len,max_len;

	len1<len2?(min_len=len1,f=0,max_len=len2):(min_len=len2,f=1,max_len=len1);
	carry=0;
	for(i=0;i<min_len;i++)
	{
		res[i]=n1[i]+n2[i]+carry;
		if(res[i]<base)
			carry=0;
		else
		{
			res[i]=res[i] - base;
			carry=1;
		}
	}
	if(f)
	{
		for(i=min_len;i<max_len;i++)
		{
			t=n1[i]+carry;
			if(t<base)
			{
				res[i] = t;
				carry = 0;
			}
			else
			{
				res[i]=t-base;
				carry=1;
			}
		}
	}
	else
	{
		for(i=min_len;i<max_len;i++)
		{
			t=n2[i]+carry;
			if(t<base)
			{
				res[i] = t;
				carry = 0;
			}
			else
			{
				res[i]=t-base;
				carry=1;
			}
		}
	}
	if(carry)
		res[max_len++]=carry;

	for(i=0;i<max_len;i++)
		r[i]=res[i];

	return max_len;
}


int main()
{
	long int i,reslen;

	initialize();
	while(1)
	{
		scanf(" %ld",&n);
		if(!n)
			break;


		printf("%ld, ",n);
		reslen = len[n][n];

		for(i=reslen-1;i>-1;i--)
		{
			if(i==reslen-1)
				printf("%ld",final[n][i]);
			else
				printf("%09ld",final[n][i]);
		}
		printf("\n");
		//printf("%ld\n",reslen);
	}
	return 0;
}

void initialize()
{
	long int i,j,k;
	tri[1][0] = 1;
	len[1][1] = 1;
	prev[1][0] = 1;
	final[1][0] = 1;

	for(i=2;i<901;i++)
	{
		for(j=0;j<len[i-1][i-1];j++)
			tri[1][j] = prev[i-1][j];
		len[i][1] = len[i-1][i-1];

		for(j=2;j<=i;j++)
		{
			len1 = len[i][j-1];
			len2 = len[i-1][j-1];

			len[i][j] = add(tri[j-1],prev[j-1],tri[j]);
		}

		for(j=1;j<=i;j++)
		{
			for(k=0;k<len[i][j];k++)
				prev[j][k] = tri[j][k];
		}

		for(j=0;j<len[i][i];j++)
			final[i][j] = tri[i][j];
	}

}
/*my  code-tle,tle,tle
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define MAX 3000
struct bigint
{
	char num[MAX];
	int len;
}bell[905],temp1[905],temp2[905];
void strreverse(char *dest,int len)
{
	int i;
	char tmp;
	for(i=0;i < len/2;i++)
	{
		tmp=dest[i];
		dest[i]=dest[len-1-i];
		dest[len-1-i]=tmp;
	}
	return;
}
bigint add(int base,bigint num1,bigint num2)
{
	bigint sum;
	int i,a,b,carry=0,maxlen;
	if(num1.len>num2.len)
		maxlen=num1.len;
	else
		maxlen=num2.len;
	for(i=0;i<maxlen || carry;i++)
	{
		if(i<num1.len)	
			a=num1.num[i]-'0';
		else
			a=0;
		if(i<num2.len)
			b=num2.num[i]-'0';
		else
			b=0;
		sum.num[i]=(a+b+carry) % base +'0';
		carry=(a+b+carry) / base;
	}
	sum.num[i]='\0';
	sum.len=i;
	return sum;
}
int main()
{
	int i,j,n;
	bell[1].num[0]=temp1[0].num[0]='1';
	bell[1].num[1]=temp1[0].num[1]='\0';
	bell[1].len=temp1[0].len=1;
	for(i=2;i<901;i++)
	{
		temp2[0]=temp1[i-2];
		for(j=1;j<i;j++)
			temp2[j]=add(10,temp2[j-1],temp1[j-1]);
		bell[i]=temp2[j-1];
		for(j=0;j<i;j++)
			temp1[j]=temp2[j];
	}
	for(i=2;i<901;i++)
		strreverse(bell[i].num,bell[i].len);
	while(scanf("%d",&n)==1)
	{
		if(!n)break;
		printf("%d, %s\n",n,bell[n].num);
	}
	return 0;
}
*/












