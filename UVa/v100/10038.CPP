#include<stdio.h>

long i,n,a1,a,d,s[3010];
char ref[][15]={"Jolly\n","Not jolly\n"};

void main(){
	int flag;
	while(scanf("%ld",&n)==1){
		flag=0;
		if(n<1){
			printf("%s",ref[1]);
			continue;
		}
		if(n==1){
			scanf("%ld",&a1);
			printf("%s",ref[0]);
			continue;
		}
		scanf("%ld",&a1);
		for(i=0;i<n;i++)
			s[i]=0;
		for(i=1;i<n;i++){
			scanf("%ld",&a);
			d=a1-a;
			if(d<0)	d=-d;
			if(!d || d>n-1)	flag=1;
			else if(s[d]==1)	flag=1;
			s[d]=1;
			a1=a;
		}
		printf("%s",ref[flag]);
	}
}