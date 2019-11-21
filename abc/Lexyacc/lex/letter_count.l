%{
#include<stdio.h>
int count=0;
%}

%%
[A-Za-z]    {count++;}
[\n]        {printf("%d\n",count);
             count=0;}
[#]         {return 0;}
%%

int main(){
	yylex();
	return 0;
}
