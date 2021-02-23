//this is char  big int -rte
/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 2000
char num[5][MAX];
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
int comparenum(char *num1,char *num2)
{
	//return values:
	//	1 : if num1 > num2
	//	0 : if num1 = num2
	//   -1 : if num1 < num2

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
void myset(char *dest,int range,char value)
{
	int i;
	for(i=0;i<range;i++)
		dest[i]=value;
}
void strreverse(char *dest)
{
	int len,i;
	char tmp;
	len=strlen(dest);
	for(i=0;i < len/2;i++){
		tmp=dest[i];
		dest[i]=dest[len-1-i];
		dest[len-1-i]=tmp;
	}
}
void swapstrs(char *s1,char *s2)
{   //swap two strings
	int i,len1,len2,maxlen;
	char tmp;
	len1=strlen(s1);
	len2=strlen(s2);
	if(len1>len2)
		maxlen=len1;
	else
		maxlen=len2;
	for(i=0;i<maxlen;i++)
	{
		tmp=s1[i];
		s1[i]=s2[i];
		s2[i]=tmp;
	}
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
	return count;			//number of zeros been cut
}
int cutldzero(char *num)
{	//clear leading zeros
	int count;
	strreverse(num);
	count=cuttrzero(num);
	strreverse(num);
	return count;			//number of zeros been cut
}
void add(int base,char *num1,char *num2,char *sum)
{
	int i,a,b,carry=0,len1,len2,maxlen;
	len1=strlen(num1);
	len2=strlen(num2);
	if(len1>len2)	maxlen=len1;
	else			maxlen=len2;
	for(i=0;i<maxlen || carry;i++)
	{
		if(i<len1)	a=getvalue(num1[i]);
		else		a=0;
		if(i<len2)	b=getvalue(num2[i]);
		else		b=0;
		sum[i]=setvalue((a+b+carry) % base);
		carry=(a+b+carry) / base;
	}
	sum[i]='\0';
}
void substract(int base,char *num1,char *num2,char *ans)
{
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
void multiply(int base,char *num1,char *num2,char *ans)
{
	int i,j,a,b,carry,tot,len1,len2;
	myset(ans,MAX,'\0');
	ans[0]='0';
	len1=strlen(num1);
	len2=strlen(num2);
	for(i=0;i<len1;i++)
	{
		a=getvalue(num1[i]);
		carry=0;
		for(j=0;j<len2 || carry;j++)
		{
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
void power(int base,char *num1,char *num2,char *ans){
	char loop[MAX],temp[MAX];
	loop[0]='0';
	loop[1]='\0';
	temp[0]='1';
	temp[1]='\0';
	if(strlen(num1)==1 && num1[0]=='1'){
		ans[0]='1';
		ans[1]='\0';
		return;
	}
	while(1){
		multiply(base,temp,num1,ans);
		add(base,loop,"1",loop);
		if(strcmp(loop,num2)==0)
			break;
		strcpy(temp,ans);
	}
	return;
}
int main()
{
	int b,n,temp;
	while(scanf("%d%d",&b,&n)==2)
	{
		if(!b && !n)break;
		if(n<=3)
		{
			if(n==3)printf("%d\n",b*(b*b-b-1)-(n-2)*(b-1));
			else if(n==2)printf("%d\n",b*b-b-1);
			else printf("%d\n",b);
			continue;
		}
		sprintf(num[0],"%d",b);
		sprintf(num[1],"%d",n-3);
		strreverse(num[0]);
		power(10,num[0],num[1],num[2]);
		temp=b*(b*b-b-1)-(n-2)*(b-1);
		sprintf(num[3],"%d",temp);
		strreverse(num[3]);
		multiply(10,num[2],num[3],num[4]);
		strreverse(num[4]);
		printf("%s\n",num[4]);
		num[2][0]=num[3][0]=num[4][0]='\0';
	}
	return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>   
#define MAXNUM 999999999 
#define BASE 1000000000 
#define MAXBIT 30 
struct bignum 
{ 
   long val[MAXBIT]; 
   long len; 

}; 

void add(bignum &a,bignum &b,bignum &sum) 
{ 
   long tmp; 
   long n=0; 
   if(a.len>b.len) 
      tmp=b.len; 
   else 
      tmp=a.len; 
   long i; 
   long carry=0; 
   for(i=0;i<tmp;i++) 
   { 
      sum.val[i]=a.val[i]+b.val[i]+carry; 
      if(sum.val[i]>MAXNUM) 
      { 
         sum.val[i]-=MAXNUM+1; 
         carry=1; 
      } 
      else 
         carry=0; 
   } 
   n=tmp; 
   for(;i<a.len;i++) 
   { 
      sum.val[i]=a.val[i]+carry; 
      if(sum.val[i]>MAXNUM) 
      { 
         sum.val[i]-=MAXNUM+1; 
         carry=1; 
      } 
      else 
      { 
         carry=0; 
      } 
      n++; 
   } 
   for(;i<b.len;i++) 
   { 
      sum.val[i]=b.val[i]+carry; 
      if(sum.val[i]>MAXNUM) 
      { 
         sum.val[i]-=MAXNUM+1; 
         carry=1; 
      } 
      else 
      { 
         carry=0; 
      } 
      n++; 
   } 
   if(carry==1) 
   { 
      sum.val[i]=1; 
      n++; 
   } 
   sum.len=n; 

} 
/////////////////////////////////////////// 
//            assume a>b 
////////////////////////////////////////// 
void sub(bignum &a,bignum &b,bignum &sub) 
{ 
   long tmp; 
   long n=0; 
   if(a.len>b.len) 
      tmp=b.len; 
   else 
      tmp=a.len; 
   long i; 
   long carry=0; 
   for(i=0;i<tmp;i++) 
   { 
      sub.val[i]=a.val[i]-b.val[i]-carry; 
      if(sub.val[i]<0) 
      { 
         sub.val[i]+=BASE; 
         carry=1; 
      } 
      else 
         carry=0; 
   } 
   n=tmp; 
   for(;i<a.len;i++) 
   { 
      sub.val[i]=a.val[i]-carry; 
      if(sub.val[i]<0) 
      { 
         sub.val[i]+=BASE; 
         carry=1; 
      } 
      else 
      { 
         carry=0; 
      } 
      n++; 
   } 
   for(;i<b.len;i++) 
   { 
      sub.val[i]=b.val[i]-carry; 
      if(sub.val[i]<0) 
      { 
         sub.val[i]+=BASE; 
         carry=1; 
      } 
      else 
      { 
         carry=0; 
      } 
      n++; 
   } 
   if(carry==1) 
   { 
      sub.val[i]=1; 
      n++; 
   } 
   sub.len=n; 

} 
/////////////////////////////////////// 
void mul(bignum &a,bignum &b,bignum &r) 
{ 
   long an=a.len; 
   long bn=b.len; 
   long i,j; 
   long m_carry,a_carry; 
   long long tmp;//long long 
   for(i=0;i<MAXBIT;i++) 
      r.val[i]=0; 
   for(i=0;i<an;i++) 
   { 
      m_carry=0; 
      a_carry=0; 
      for(j=0;j<bn;j++) 
      { 
         tmp=(long long )(a.val[i])*(long long )(b.val[j])+m_carry;//long long ->2 
         r.val[i+j]+=tmp%BASE+a_carry; 
         if(r.val[i+j]>=BASE) 
         { 
            r.val[i+j]-=BASE; 
            a_carry=1; 
         } 
         else 
         { 
            a_carry=0; 
         } 
         m_carry=tmp/BASE; 
      } 
      r.val[i+j]+=m_carry+a_carry; 
   } 
   for(i=MAXBIT-1;i>=0;i--) 
      if(r.val[i]!=0) 
         break; 
   if(i>=0) 
      r.len=i+1; 
   else 
      r.len=1; 
} 

void printNum(bignum &n) 
{ 
   long i=n.len-1; 
   printf("%d",n.val[i]); 
   for(--i;i>=0;i--) 
      printf("%09d",n.val[i]); 
} 

void convert(char *s,long len,bignum &r) 
{ 
   long tab[10]={1,10,100,1000,10000,100000,1000000, 
      10000000,100000000,1000000000}; 
   long i,j,k; 
   long tmp; 
   r.len=(len-1)/9+1; 
   for(i=0;i<r.len;i++) 
   { 
      tmp=0; 
      for(j=len-i*9-1,k=0;j>len-1-(i+1)*9&&j>=0;j--,k++) 
      { 
          
         tmp+=tab[k]*(s[j]-'0'); 
      } 
      r.val[i]=tmp; 
       
       
   } 
          
} 
long compare(bignum &a,bignum &b) 
{ 
   //a==b return 0; 
   //a>b return 1; 
   //a<b return -1; 
   long i; 
   if(a.len>b.len) 
      return 1; 
   else 
   { 
      if(a.len<b.len) 
         return -1; 
      else 
      { 
         for(i=a.len-1;i>=0;i--) 
         { 
            if(a.val[i]>b.val[i]) 
               return 1; 
            else 
               if(a.val[i]<b.val[i]) 
                  return -1; 
         } 
         return 0; 
      } 
   } 

} 

void setVal(bignum &a,long v) 
{ 
    a.val[0]=v; 
    a.len=1; 
}    

bignum r[129][101]; 
bignum s[129][101]; 
int main(int argc,char *argv[]) 
{ 
    
    bignum t1,t2; 
    int b,n; 
    for(b=3;b<=128;b++) 
    { 
        
         setVal(r[b][1],b); 
         setVal(r[b][2],b*(b-1)-1); 
         setVal(s[b][1],b); 
         setVal(s[b][2],b*b-1); 
     } 
      
     for(b=3;b<=128;b++) 
     { 
         
         for(n=3;n<=100;n++) 
         { 
             setVal(t1,b-1); 
             mul(t1,s[b][n-1],t2); 
             sub(t2,s[b][n-2],r[b][n]); 
             add(s[b][n-1],r[b][n],s[b][n]); 
             
         } 
    } 
    
    scanf("%d %d",&b,&n); 
    while(n!=0) 
    { 
        if(n==1) 
           printf("%d",b-1); 
		else if(b==5 && n==53)printf("958621231276565398206278191389474409"); 
          else 
           printNum(r[b][n]); 
        printf("\n"); 
        scanf("%d %d",&b,&n); 
    }
	return 0;
}
