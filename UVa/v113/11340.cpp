#include<stdio.h>
#include<string.h>

#define SIZE 10009

typedef long long myint;

int arr[500];
myint res;

int main(){
	int n,m,i,val,k;
	char str[SIZE],ch;
	char str1[200];

	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);

		memset(arr,0,sizeof(arr));

		gets(str1);
		while(k--){
			gets(str1);			
			sscanf(str1,"%c %d",&ch,&val);
			arr[ch+128]=val;
		}
		scanf("%d",&m);
		gets(str1);
		res =0;
		while(m--){
			while(1){
				//scanf("%[^\n]",str);
				scanf("%c",&ch);
				if(ch=='\n') break;
				res+=arr[ch+128];
			}
			//gets(str);
			//for(i=0;str[i];i++)	res += arr[str[i]+128];
		}

		double d = res*1.0/100;
		printf("%.2lf$\n",d);
		/*
		if(res/100)
			printf("%lld.%02lld$",res/100,res%100);
		else
			printf("0.%02lld$",res%100);

		puts("");*/

	}

	return 0;
}