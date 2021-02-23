#include<stdio.h>
#include<string.h>

char c[100],c1;
long t,i,count;

int main(){
	while(gets(c)){
		t=strlen(c);
		count=0;
		for(i=1;i<t;i++){
			if((c[i]<'a'|| c[i]>'z')&& (c[i]<'A'|| c[i]>'Z')){
				if((c[i-1]>='a' && c[i-1]<='z')|| (c[i-1]>='A'&& c[i-1]<='Z'))
					count++;
			}
		}
		if((c[i-1]>='a'&& c[i-1]<='z') || (c[i-1]>='A'&& c[i-1]<='Z'))
			count++;
		printf("%ld\n",count);
	}
}
