#include<stdio.h>
#include<string.h>

char m[20],n[20];
long l1,l2,i,c,a,b,carry,max;

void main(){
	while(scanf("%s%s",m,n)==2){
		if(n[0]=='0'&& n[1]=='\0' && m[0]=='0'&& m[1]=='\0')
			break;
		l1=strlen(m);
		l2=strlen(n);
		if(l1>l2)
			max=l1;
		else
			max=l2;
		for(i=c=carry=0;i<max||carry;i++){
			if(i<l1)
				a=m[l1-1-i]-'0';
			else
				a=0;
			if(i<l2)
				b=n[l2-1-i]-'0';
			else
				b=0;
			//=(a+b+carry)%10;
			c+=carry=(a+b+carry)/10;
		}
		if(!c)
			printf("No carry operation.\n");
		else if(c==1)
			printf("1 carry operation.\n");
		else if(c>1)
			printf("%ld carry operations.\n",c);
	}
}