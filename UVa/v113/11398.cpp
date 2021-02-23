//Adhoc
#include<stdio.h>
#include<string.h>

#define SIZE 1000

char res[SIZE];
int ct;

void add(int flag, int n){
	int i;
	for(i=0;i<n;i++,ct++)
		res[ct]=flag+'0';
}

void print(){
	int i;
	long long out=0;

	for(i=0;i<ct;i++){
		out*=2;
		out+=res[i]-'0';
	}

	printf("%lld\n",out);
}

int main(){
	char str[SIZE];
	int flag,l;

	while(scanf("%s",str) && *str!='~'){
		ct=0;
		while(*str != '#'){
			l=strlen(str);

			if(l==1){
				flag=1;
			}
			else if(l == 2){
				flag = 0;
			}
			else if(l>2){
				add(flag,l-2);
			}

			scanf("%s",str);
		}

		res[ct]=0;
		print();
	}

	return 0;
}