%{
#include<stdio.h>
int n=0,flag=0;
%}
%%
[0-9]+ {n=atoi(yytext);if(n%2==0){printf("%dEVEN",n);}else{printf("%dODD",n);}}
.;
%%
int main(){
yylex();
}
