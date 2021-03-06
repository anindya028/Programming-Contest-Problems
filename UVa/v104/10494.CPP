#include<stdio.h>
//Bigint
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
	int i,len1,len2,a,b;
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

int cutldzero(char *num){	//clear leading zeros
	int count;
	strreverse(num);
	count=cuttrzero(num);
	strreverse(num);
	return count;			//number of zeros been cut
}

void add(int base,char *num1,char *num2,char *sum){
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

void substract(int base,char *num1,char *num2,char *ans){
	int i,a,b,take=0,len1,len2,maxlen,flag=0,lzr;
	if(comparenum(num1,num2)==-1){
		swapstrs(num1,num2);
		flag=1;
	}
	len1=strlen(num1);
	len2=strlen(num2);
	if(len1>len2)
		maxlen=len1;
	else
		maxlen=len2;
	for(i=0;i<maxlen;i++){
		if(i<len1)
			a=getvalue(num1[i]);
		else
			a=0;
		if(i<len2)
			b=getvalue(num2[i]);
		else
			b=0;
		b+=take;
		if(b==base){
			b=0;
			take=1;
		}
		else if(a < b){
			a+=base;
			take=1;
		}
		else
			take=0;
		ans[i]=setvalue((a-b) % base);
	}
	ans[i]='\0';
	lzr=cuttrzero(ans);
	if(flag==1)
		ans[i-lzr]='-';
	ans[i-lzr+flag]='\0';
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
}

void divide(int base,char *num1,char *num2,char *ans){
	int i,j,len;
	char tmp[5],s[MAX],gunfall[MAX];
	len=strlen(num1);
	s[0]='\0';
	for(i=0;i<len;i++){
		tmp[0]=num1[len-1-i];
		tmp[1]='\0';
		strreverse(s);
		strcat(s,tmp);
		strreverse(s);
		cuttrzero(s);
		for(j=base-1;j>=0;j--){
			tmp[0]=setvalue(j);
			tmp[1]='\0';
			myset(gunfall,MAX,'\0');
			multiply(base,tmp,num2,gunfall);
			if(comparenum(s,gunfall) >= 0){
				substract(base,s,gunfall,s);
				break;
			}
		}
		ans[i]=setvalue(j);
	}
	ans[i]='\0';
	strreverse(ans);
	cuttrzero(ans);
}

void mod(int base,char *num1,char *num2,char *remainder){
	char s1[MAX],s2[MAX];
	myset(s1,MAX,'\0');
	myset(s2,MAX,'\0');
	divide(base,num1,num2,s1);
	multiply(base,num2,s1,s2);
	substract(base,num1,s2,remainder);
}
int main()
{
	int base=10;     //base --> 2 to 62
	char oper[5];
	while(scanf("%s%s%s",num[0],oper,num[1])==3)
	{
		strreverse(num[0]);
		strreverse(num[1]);
		cuttrzero(num[0]);
		cuttrzero(num[1]);
		if(oper[0]=='/')
			divide(base,num[0],num[1],num[2]);
		else if(oper[0]=='%')
			mod(base,num[0],num[1],num[2]);
		strreverse(num[2]);
		printf("%s\n",num[2]);
		num[2][0]='\0';
        }
	return 0;
}













