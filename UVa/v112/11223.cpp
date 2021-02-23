#include<stdio.h>
#include<string.h>

char map[130][10]={0};

void find(char *s){
	int i;
	for(i=0;i<130;i++){
		if(!strcmp(map[i],s)){
			putchar(i);
			return;
		}
	}
}
int main(){	
	int i,j,t,ct,k;
	char *p,str[10000];

	strcpy(map['A'],".-");		
	strcpy(map['J'],".---"); 	
	strcpy(map['S'],"...");
	strcpy(map['1'],".----");
	strcpy(map['.'],".-.-.-");
	strcpy(map[':'],"---...");
	strcpy(map['B'],"-...");
	strcpy(map['K'],"-.-"); 	
	strcpy(map['T'],"-"); 		
	strcpy(map['2'],"..---"); 	
	strcpy(map[','],"--..--");	
	strcpy(map[';'],"-.-.-.");
	strcpy(map['C'],"-.-."); 	
	strcpy(map['L'],".-.."); 	
	strcpy(map['U'],"..-"); 	
	strcpy(map['3'],"...--"); 	
	strcpy(map['?'],"..--.."); 	
	strcpy(map['='],"-...-");
	strcpy(map['D'],"-.."); 	
	strcpy(map['M'],"--"); 		
	strcpy(map['V'],"...-"); 	
	strcpy(map['4'],"....-"); 	
	strcpy(map['\''],".----."); 
	strcpy(map['+'],".-.-.");
	strcpy(map['E'],"."); 		
	strcpy(map['N'],"-."); 		
	strcpy(map['W'],".--"); 	
	strcpy(map['5'],"....."); 	
	strcpy(map['!'],"-.-.--"); 	
	strcpy(map['-'],"-....-");
	strcpy(map['F'],"..-."); 	
	strcpy(map['O'],"---"); 	
	strcpy(map['X'],"-..-"); 	
	strcpy(map['6'],"-...."); 	
	strcpy(map['/'],"-..-."); 	
	strcpy(map['_'],"..--.-");
	strcpy(map['G'],"--."); 	
	strcpy(map['P'],".--."); 	
	strcpy(map['Y'],"-.--"); 	
	strcpy(map['7'],"--..."); 	
	strcpy(map['('],"-.--."); 	
	strcpy(map['"'],".-..-.");
	strcpy(map['H'],"...."); 	
	strcpy(map['Q'],"--.-"); 	
	strcpy(map['Z'],"--.."); 	
	strcpy(map['8'],"---.."); 	
	strcpy(map[')'],"-.--.-"); 	
	strcpy(map['@'],".--.-.");
	strcpy(map['I'],".."); 		
	strcpy(map['R'],".-."); 	
	strcpy(map['0'],"-----"); 	
	strcpy(map['9'],"----."); 	
	strcpy(map['&'],".-...");

	scanf("%d",&t);
	gets(str);
	for(i=1;i<=t;i++){
		if(i>1)	puts("");
		printf("Message #%d\n",i);
		gets(str);

		for(j=ct=0;;){			
			while(str[j]==' ')
				ct++,j++;
			for(k=0;k<ct/2;k++)
				putchar(' ');

			if(!str[j])
				break;

			p=&str[j];
			while(str[j] && str[j]!=' ')
				j++;
			if(!str[j]){
				find(p);
				break;
			}
			else{
				str[j]=0;
				j++;
				find(p);
				ct=1;				
			}
		}		
		puts("");
	}

	return 0;
}