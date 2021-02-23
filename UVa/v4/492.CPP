#include<stdio.h>
#include<math.h>
#include<string.h>

char c,w[100],p;
long i,k;

void haha(){
	if(w[1]=='a' || w[1]=='e' || w[1]=='i' || w[1]=='o' || w[1]=='u' || w[1]=='A' || w[1]=='E' || w[1]=='I' || w[1]=='O' || w[1]=='U')
		printf("%c",w[1]);
	for(k=2;k<i;k++)
		printf("%c",w[k]);
	if(w[1]=='a' || w[1]=='e' || w[1]=='i' || w[1]=='o' || w[1]=='u' || w[1]=='A' || w[1]=='E' || w[1]=='I' || w[1]=='O' || w[1]=='U')
		printf("ay");
	else
		printf("%cay",w[1]);
}
void main(){
	while((c=getchar())!=EOF){
		i=1;
		if((c>='a' && c<='z')|| (c>='A'&& c<='Z')){
			w[i++]=c;
			c=getchar();
			while((c>='a' && c<='z')|| (c>='A'&& c<='Z')){
				w[i++]=c;
				c=getchar();
			}
			w[i]='\0';
			haha();
		}
		if((c<'a' || c>'z')&&(c<'A'||c>'Z') && c!=' ');
			printf("%c",c);
	}
}