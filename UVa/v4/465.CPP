/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
#define MAX 1000

char num[3][MAX];

int getvalue(char s){
	if(s >= '0' && s <= '9')
		return s - '0';
	else if(s >='A' && s <= 'Z')
		return s - 'A' + 10;
	else if(s >='a' && s <= 'z')
		return s - 'a' + 36;
	else
		return NULL;
}

char setvalue(int s){
	if(s < 10)
		return s + '0';
	else if(s < 36)
		return s + 'A' - 10;
	else if(s < 62)
		return s + 'a' - 36;
	else
		return NULL;
}

int comparenum(char *num1,char *num2){
/*	return values:
		1 : if num1 > num2
		0 : if num1 = num2
	   -1 : if num1 < num2
*/
/*	int i,len1,len2,a,b;
	len1=strlen(num1);
	len2=strlen(num2);
	if(len1 > len2)
		return 1;
	else if(len1 < len2)
		return -1;
	else{
		for(i=len1-1;i>=0;i--){
			a=getvalue(num1[i]);
			b=getvalue(num2[i]);
			if(a > b)
				return 1;
			else if(a < b)
				return -1;
		}
		return 0;
	}
}

void myset(char *dest,int range,char value){
	int i;
	for(i=0;i<range;i++)
		dest[i]=value;
}

void strreverse(char *dest){
	int len,i;
	char tmp;
	len=strlen(dest);
	for(i=0;i < len/2;i++){
		tmp=dest[i];
		dest[i]=dest[len-1-i];
		dest[len-1-i]=tmp;
	}
}

void swapstrs(char *s1,char *s2){   //swap two strings
	int i,len1,len2,maxlen;
	char tmp;
	len1=strlen(s1);
	len2=strlen(s2);
	if(len1>len2)
		maxlen=len1;
	else
		maxlen=len2;
	for(i=0;i<maxlen;i++){
		tmp=s1[i];
		s1[i]=s2[i];
		s2[i]=tmp;
	}
}

int cuttrzero(char *num){   //clear trailing zeros
	int i,count=0,len;
	len=strlen(num);
	for(i=len-1;i>0;i--){
		if(num[i]=='0'){
			num[i]='\0';
			count++;
		}
		else
			break;
	}
	return count;			//number of zeros been cut
}

/*int cutldzero(char *num){	//clear leading zeros
	int count;
	strreverse(num);
	count=cuttrzero(num);
	strreverse(num);
	return count;			//number of zeros been cut
}*/

/*void add(int base,char *num1,char *num2,char *sum){
	int i,a,b,carry=0,len1,len2,maxlen;
	len1=strlen(num1);
	len2=strlen(num2);
	if(len1>len2)	maxlen=len1;
	else			maxlen=len2;
	for(i=0;i<maxlen || carry;i++){
		if(i<len1)	a=getvalue(num1[i]);
		else		a=0;
		if(i<len2)	b=getvalue(num2[i]);
		else		b=0;
		sum[i]=setvalue((a+b+carry) % base);
		carry=(a+b+carry) / base;
	}
	sum[i]='\0';
}
void multiply(int base,char *num1,char *num2,char *ans){
	int i,j,a,b,carry,tot,len1,len2;
	myset(ans,MAX,'\0');
	ans[0]='0';
	len1=strlen(num1);
	len2=strlen(num2);
	for(i=0;i<len1;i++){
		a=getvalue(num1[i]);
		carry=0;
		for(j=0;j<len2 || carry;j++){
			if(j<len2)
				b=getvalue(num2[j]);
			else
				b=0;
			tot=a*b+carry;
			if(ans[i+j])
				tot+=getvalue(ans[i+j]);
			ans[i+j]=setvalue(tot%base);
			carry=tot / base;
		}
	}
	ans[i+j-1]='\0';
	cuttrzero(ans);
}*/
/*int main()
{
	int base=10;
        char p[]={"2147483647"};
	char oper[5],s[MAX];
	while(gets(s))
	{
		printf("%s\n",s);
		sscanf(s,"%s %s %s",num[0],oper,num[1]);
		cutldzero(num[0]);
		cutldzero(num[1]);
		if(strlen(num[0])>10)
			printf("first number too big\n");
		else if(strlen(num[0])==10)
		{
			if(strcmp(num[0],p)>0)printf("first number too big\n");
		}
		if(strlen(num[1])>10)
			printf("second number too big\n");
		else if(strlen(num[1])==10)
		{
			if(strcmp(num[1],p)>0)printf("first number too big\n");
		}
		strreverse(num[0]);
		strreverse(num[1]);
		if(oper[0]=='+')
			add(base,num[0],num[1],num[2]);
		else if(oper[0]=='*')
			multiply(base,num[0],num[1],num[2]);
		strreverse(num[2]);
		if(strlen(num[2])>10)
			printf("result too big\n");
		else if(strlen(num[2])==10)
		{
			if(strcmp(num[2],p)>0)printf("result too big\n");
		}
		num[2][0]='\0';
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double n1,n2,p=2147483647,ans;
	char c,s[1000];
	while(gets(s))
	{
		sscanf(s,"%lf %c%lf",&n1,&c,&n2);
		printf("%s\n",s);
		if(c=='+')ans=n1+n2;
		else if(c=='*')ans=n1*n2;
		if(n1>p)printf("first number too big\n");
		if(n2>p)printf("second number too big\n");
		if(ans>p)printf("result too big\n");
	}
	return 0;
}












