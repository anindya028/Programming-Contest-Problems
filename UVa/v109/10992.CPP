#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
///#define Long __int64
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
int eleven(void)
{
	int j,length=strlen(num[2]),sum1,sum2,dif;
	for(j=sum1=0;j<length;j+=2)
	{
		sum1+=(num[2][j]-'0');
	}
	for(j=1,sum2=0;j<length;j+=2)
	{
		sum2+=(num[2][j]-'0');
	}
	dif=labs(sum1-sum2);
	if(dif%11==0)return 1;
	else return 0;
}
int three(void)
{
	int j,sum1,length=strlen(num[2]);
	for(j=sum1=0;j<length;j++)
		sum1+=(num[2][j]-'0');
	if(sum1%3==0)return 1;
	else return 0;
}
int leap(void)
{
	int dig=(num[0][1]-'0')*10+(num[0][0]-'0');
	if(dig%4==0)
	{
		if(dig)return 1;
	}
	if(!dig)
	{
		dig=(num[0][3]-'0')*10+(num[0][2]-'0');
		if(dig%4==0)return  1;
	}
	return 0;
}
int four(void)
{
	int length=strlen(num[2]);
	int dig=(num[2][length-2]-'0')*10+(num[2][length-1]-'0');
	if(dig%4==0)return 1;
	else return 0;
}
int nine(void)
{
	int j,sum1,length=strlen(num[2]);
	for(j=sum1=0;j<length;j++)
		sum1+=(num[2][j]-'0');
	if(sum1%9==0)return 1;
	else return 0;
}
int seven(void)
{
	int j,sum=0,length=strlen(num[2]),flag=1;
	for(j=length-1;j>=0;j-=3)
	{
		if(j>=2)
                {
			if(flag)
			{
				sum+=((num[2][j-2]-'0')*100+(num[2][j-1]-'0')*10+(num[2][j]-'0'));
				flag=0;
			}
			else
			{
				sum-=((num[2][j-2]-'0')*100+(num[2][j-1]-'0')*10+(num[2][j]-'0'));
				flag=1;
			}
		}
		else if(j==1)
		{
			if(flag)sum+=((num[2][j-1]-'0')*10+(num[2][j]-'0'));
			else sum-=((num[2][j-1]-'0')*10+(num[2][j]-'0'));
		}
		else
		{
			if(flag)sum+=(num[2][j]-'0');
			else sum-=(num[2][j]-'0');
		}
	}
	sum=abs(sum);
	if(sum%7==0)return  1;
	else return 0;
}
int main()
{
	num[1][0]='2';
	num[1][1]='1';
	num[1][2]='4';
	num[1][3]='8';
	num[1][4]='\0';
        int cs=0,n,flag=0,length;
	while(scanf("%s",num[0])==1)
	{
		if(num[0][0]=='0'&&num[0][1]=='\0')break;
		if(cs)printf("\n");
		cutldzero(num[0]);
		printf("%s\n",num[0]);
                flag=0;
		if(strlen(num[0])<=4)
		{
			sscanf(num[0],"%d",&n);
			if(n<2148)
			{
				printf("No ghost will come in this year\n");
				cs++;
				continue;
                        }
			else if(n==2148)
			{
				printf("Ghost of Tanveer Ahsan!!!\n");
				printf("Ghost of Shahriar Manzoor!!!\n");
				printf("Ghost of Adrian Kugel!!!\n");
				printf("Ghost of Anton Maydell!!!\n");
				printf("Ghost of Derek Kisman!!!\n");
				printf("Ghost of Rezaul Alam Chowdhury!!!\n");
				printf("Ghost of Jimmy Mardell!!!\n");
				printf("Ghost of Monirul Hasan!!!\n");
				printf("Ghost of K. M. Iftekhar!!!\n");
				cs++;
                                continue;
			}
		}
		strreverse(num[0]);
		strreverse(num[1]);
		cuttrzero(num[0]);
		substract(10,num[0],num[1],num[2]);
		strreverse(num[2]);
                length=strlen(num[2]);
		if((num[2][length-1]-'0')%2==0)
		{
			printf("Ghost of Tanveer Ahsan!!!\n");
			flag=1;
		}
		if(num[2][length-1]=='5'||num[2][length-1]=='0')
		{
			printf("Ghost of Shahriar Manzoor!!!\n");
			flag=1;
		}
		if(seven())
		{
			printf("Ghost of Adrian Kugel!!!\n");
			flag=1;
		}
		if(eleven())
		{
			printf("Ghost of Anton Maydell!!!\n");
			flag=1;
		}
		if(three()&&(num[2][length-1]=='5'||num[2][length-1]=='0'))
		{
			printf("Ghost of Derek Kisman!!!\n");
			flag=1;
		}
		if(four()&&(num[2][length-1]=='5'||num[2][length-1]=='0'))
		{
			printf("Ghost of Rezaul Alam Chowdhury!!!\n");
			flag=1;
		}
		if(four()&&seven())
		{
			printf("Ghost of Jimmy Mardell!!!\n");
			flag=1;
		}
		if(four()&&nine())
		{
			printf("Ghost of Monirul Hasan!!!\n");
			flag=1;
		}
		if(leap())
		{
			printf("Ghost of K. M. Iftekhar!!!\n");
			flag=1;
		}
		if(!flag)printf("No ghost will come in this year\n");
		num[2][0]='\0';
		strreverse(num[1]);
		cs++;
	}
	return 0;
}













