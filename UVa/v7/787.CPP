#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1000
struct bigint
{
	char num[MAX];
	int len;
	int flag;
}big[3];
int getvalue(char s)
{
	if(s >= '0' && s <= '9')
		return s - '0';
	else if(s >='A' && s <= 'Z')
		return s - 'A' + 10;
	else if(s >='a' && s <= 'z')
		return s - 'a' + 36;
	else
		return NULL;
}
char setvalue(int s)
{
	if(s < 10)
		return s + '0';
	else if(s < 36)
		return s + 'A' - 10;
	else if(s < 62)
		return s + 'a' - 36;
	else
		return NULL;
}
void swapstrs(bigint *s1,bigint *s2)
{   //swap two strings
	bigint tmp;
	tmp=*s1;
	*s1=*s2;
	*s2=tmp;
	return;
}
int comparenum(bigint num1,bigint num2)
{
/*	return values:
		1 : if num1 > num2
		0 : if num1 = num2
	   -1 : if num1 < num2
*/
	int i,a,b;
	if(num1.flag>num2.flag)
		return 1;
	else if(num1.flag<num2.flag)
		return -1;
	if(!num1.flag)
		swapstrs(&num1,&num2);
	if(num1.len > num2.len)
		return 1;
	else if(num1.len < num2.len)
		return -1;
	else
	{
		for(i=0;i<num1.len;i++)
		{
			a=getvalue(num1.num[i]);
			b=getvalue(num2.num[i]);
			if(a > b)
				return 1;
			else if(a < b)
				return -1;
		}
		return 0;
	}
}
void myset(char *dest,int range,char value)
{
	int i;
	for(i=0;i<range;i++)
		dest[i]=value;
	return;
}
void strreverse(char *dest)
{
	int len,i;
	char tmp;
	len=strlen(dest);
	for(i=0;i < len/2;i++)
	{
		tmp=dest[i];
		dest[i]=dest[len-1-i];
		dest[len-1-i]=tmp;
	}
	return;
}
int cuttrzero(char *num)
{   //clear trailing zeros
	int i,count=0,len;
	len=strlen(num);
	for(i=len-1;i>0;i--)
	{
		if(num[i]=='0')
		{
			num[i]='\0';
			count++;
		}
		else
			break;
	}
	return count;			
}
int cutldzero(char *num)
{	//clear leading zeros
	int count;
	strreverse(num);
	count=cuttrzero(num);
	strreverse(num);
	return count;			
}
bigint multiply(int base,bigint num1,bigint num2)
{
	bigint ans;
	int i,j,a,b,carry,tot,gar;
	strreverse(num1.num);
	strreverse(num2.num);
	myset(ans.num,MAX,'\0');
	ans.num[0]='0';
	for(i=0;i<num1.len;i++)
	{
		a=getvalue(num1.num[i]);
		carry=0;
		for(j=0;j<num2.len || carry;j++)
		{
			if(j<num2.len)
				b=getvalue(num2.num[j]);
			else
				b=0;
			tot=a*b+carry;
			if(ans.num[i+j])
				tot+=getvalue(ans.num[i+j]);
			ans.num[i+j]=setvalue(tot%base);
			carry=tot/base;
		}
	}
	ans.num[i+j-1]='\0';
	gar=cuttrzero(ans.num);
	ans.len=strlen(ans.num);
	if((num1.flag==1 && num2.flag==1) || (num1.flag==0 && num2.flag==0))
		ans.flag=1;
	else ans.flag=0;
	strreverse(ans.num);
	return ans;
}
int main()
{
	bigint max,num[105],maxpos[105],maxneg[105],zero;
	int i,n;
	zero.num[0]='0';
	zero.num[1]='\0';
	zero.len=zero.flag=1;
	num[0]=maxpos[0]=maxneg[0]=zero;
	while(scanf("%d",&n)==1)
	{
		if(n<0)
		{
			num[1].flag=0;
			n*=-1;
		}
		else num[1].flag=1;
		sprintf(num[1].num,"%d",n);
		num[1].len=strlen(num[1].num);
		for(i=2;;i++)
		{
			scanf("%d",&n);
			if(n==-999999)break;
			if(n<0)
			{
				num[i].flag=0;
				n*=-1;
			}
			else num[i].flag=1;
			sprintf(num[i].num,"%d",n);
			num[i].len=strlen(num[i].num);
		}
		n=i;
		for(i=1;i<n;i++)
		{
			if(num[i].num[0]=='0' && num[i].len==1)
			{
				maxpos[i]=maxneg[i]=zero;
			}
			else if(num[i].flag)
			{
				if(!(maxpos[i-1].num[0]=='0' && maxpos[i-1].len==1))
					maxpos[i]=multiply(10,maxpos[i-1],num[i]);
				else maxpos[i]=num[i];
				if(!(maxneg[i-1].num[0]=='0' && maxneg[i-1].len==1))
					maxneg[i]=multiply(10,maxneg[i-1],num[i]);
				else maxneg[i]=zero;
			}
			else
			{
				if(!(maxneg[i-1].num[0]=='0' && maxneg[i-1].len==1))
					maxpos[i]=multiply(10,maxneg[i-1],num[i]);
				else maxpos[i]=zero;
				if(!(maxpos[i-1].num[0]=='0' && maxpos[i-1].len==1))
					maxneg[i]=multiply(10,maxpos[i-1],num[i]);
				else maxneg[i]=num[i];
			}
		}
		max=maxpos[0];
		for(i=1;i<n;i++)
				if(comparenum(maxpos[i],max)>0)
					max=maxpos[i];
		if(n==2 && !num[1].flag)
			max=num[1];
		if(!max.flag/* && !(max.num[0]=='0' && max.len==1)**/)
			printf("-");
		printf("%s\n",max.num);
	}
	return 0;
}













