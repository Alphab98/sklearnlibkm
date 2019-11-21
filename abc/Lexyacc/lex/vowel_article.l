%{
#include<stdio.h>
char tab[50][2][10];
%}

%%
(play|eat|dance|write|sing|run|walk)            {printf("%s is a verb\n",yytext);}
(mohit|avaneesh|harsh|shashank|aviral)          {printf("%s is a noun\n",yytext);}
(i|he|she|it|they)                              {printf("%s is a pronoun\n",yytext);}
(then|there|gently|quietly)                     {printf("%s is a adverb\n",yytext);}
(hot|beautiful|antique|fragrent)                {printf("%s is a adjective\n",yytext);}
(for|and|not|but|or|yet|so)                     {printf("%s is a conjunctions\n",yytext);}
(who|what|where|when|why)                       {printf("%s is a interrogative word\n",yytext);}
[A-Za-z]+                                       {printf("%s in  not defined\n",yytext);}
[$]                                             {return 0;}
%%

int main(){
	yylex();
	return 0;
}
