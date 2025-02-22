%{
#include<stdio.h>
%}

%%
[A-Z]+[ \t\n] {printf("%s is a capital letter", yytext);}
. ;
%%
int main()
{
printf("\n Enter the input string:");	
yylex();
}

int yywrap()
{
return 1;
}
