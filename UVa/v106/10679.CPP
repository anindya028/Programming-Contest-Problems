//my code->tle->board says it should be done using kmp;
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
//#define Long __int64
//#define Long long long
char  s1[100005],s2[1005];
int len;
int give(int ind)
{
	int i,j;
	for(i=ind,j=len=0;;i++,j++)
	{
		if(!s1[i] || !s2[j])return 0;
		if(s1[i]!=s2[j])
		{
			if(s1[i]==s2[0])
				return give(i);
			else
				return give(i+1);
		}
		else len++;
		if(len==strlen(s2))return 1;
	}
	return 0;
}
int main()
{
	int n,i,j,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s%d",s1,&q);
		for(j=0;j<q;j++)
		{
			scanf("%s",s2);
			if(give(0))printf("y\n");
			else printf("n\n");
        }
	}
	return 0;
}
//this is code from board->ac 
#include<iostream.h> 
#include<string.h> 
int main(){ 
char a[100001],b[100001]; 
int k,i,j,c,d; 
cin >> c; 
for(i=0;i<c;i++){ 
cin.get(); 
cin >> a; 
cin >> d; 
cin.get(); 
for(j=0;j<d;j++){ 
cin >> b; 
int sw=0,len=strlen(a),z=0,len2=strlen(b); 
for(k=0;;k++){ 
if(sw==len2) 
break; 
if(b[sw]==a[z]){ 
sw++; 
z++; 
} 
else{ 
z++; 
sw=0; 
} 
if(z==len2) 
break; 
} 
if(sw==len2) 
cout << "y" << endl; 
else 
cout << "n" << endl; 
} 
} 
return 0; 
}












