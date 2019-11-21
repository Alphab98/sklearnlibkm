%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
%}

%%

[0-9]+                                          {yylval=atoi(yytext); return id;}
[-+\n]                                          {return *yytext;}
[*/%]                                           {return *yytext;}
[()]                                            {return *yytext;}

%%

int yywrap(){
	return 0;
}

