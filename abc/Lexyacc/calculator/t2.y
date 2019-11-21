%{
#include<stdio.h> 
#include<stdlib.h> 
int yylex(void);
%}

%token id;
%left '+' '-';
%left '*' '/' '%';
%left '(' ')';

%%

start: E                    {printf("%d",$1);}
E    : '('E')'              {$$=$2;}
     | E'%'E                {$$=$1%$3;}
     | E'/'E                {$$=$1/$3;}
     | E'*'E                {$$=$1*$3;}
     | E'+'E                {$$=$1+$3;}
     | E'-'E                {$$=$1-$3;}
     | id                   {$$=$1;}
     ;

%%

int yyerror(){ 
	
	return 0;
}

int main(){
	yyparse();
	return 0;
}
