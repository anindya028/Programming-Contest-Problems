#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>


using namespace std;

char S[1009];

char change(char ch)
{
	switch(ch)
	{
		case '4':
			return 'q';
		case '5':
			return 'j';
		case '6':
			return 'l';
		case '7':
			return 'm';
		case '8':
			return 'f';
		case '9':
			return 'p';
		case '0':
			return '/';
		case '-':
			return '[';
		case '=':
			return ']';
		case '$':
			return 'Q';
		case '%':
			return 'J';
		case '^':
			return 'L';
		case '&':
			return 'M';
		case '*':
			return 'F';
		case '(':
			return 'P';
		case ')':
			return '?';
		case '_':
			return '{';
		case '+':
			return '}';
		case 'q':
			return '4';
		case 'Q':
			return '$';
		case 'w':
			return '5';
		case 'W':
			return '%';
		case 'e':
			return '6';
		case 'E':
			return '^';
		case 'r':
			return '.';
		case 'R':
			return '>';
		case 't':
			return 'o';
		case 'T':
			return 'O';
		case 'y':
			return 'r';
		case 'Y':
			return 'R';
		case 'u':
			return 's';
		case 'U':
			return 'S';
		case 'i':
			return 'u';
		case 'I':
			return 'U';
		case 'o':
			return 'y';
		case 'O':
			return 'Y';
		case 'p':
			return 'b';
		case 'P':
			return 'B';
		case '[':
			return ';';
		case '{':
			return ':';
		case ']':
			return '=';
		case '}':
			return '+';
		case 'a':
			return '7';
		case 'A':
			return '&';
		case 's':
			return '8';
		case 'S':
			return '*';
		case 'd':
			return '9';
		case 'D':
			return '(';
		case 'f':
			return 'a';
		case 'F':
			return 'A';
		case 'g':
			return 'e';
		case 'G':
			return 'E';
		case 'j':
			return 't';
		case 'J':
			return 'T';
		case 'k':
			return 'd';
		case 'K':
			return 'D';
		case 'l':
			return 'c';
		case 'L':
			return 'C';
		case ';':
			return 'k';
		case ':':
			return 'K';
			//check
		case 39:
			return '-';
		case '"':
			return '_';
		case 'z':
			return '0';
		case 'Z':
			return ')';
		case 'x':
			return 'z';
		case 'X':
			return 'Z';
		case 'c':
			return 'x';
		case 'C':
			return 'X';
		case 'v':
			return ',';
		case 'V':
			return '<';
		case 'b':
			return 'i';
		case 'B':
			return 'I';
		case 'm':
			return 'w';
		case 'M':
			return 'W';
		case ',':
			return 'v';
		case '<':
			return 'V';
		case '.':
			return 'g';
		case '>':
			return 'G';
		case '/':
			return 39;
		case '?':
			return '"';
		default:
			return ch;
	}
}


int main(void)
{
	int i;
	while(gets(S))
	{
		for(i=0;S[i];i++)
			printf("%c",change(S[i]));
		printf("\n");
	}
	return 0;
}