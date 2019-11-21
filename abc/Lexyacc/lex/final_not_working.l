/*a=verb,b=noun,c=pronoun,d=adverb,e=adjective,f=conjunctions,g=interrogative word,h=not defined
*/
%{
#include<stdio.h>
#include<string.h>
char tab[50][2][25];
int i=0;
void p();
void f(char *);
%}

%%
(play|eat|dance|write|sing|run|walk)            {tab[i][1][0]='a';
                                                 tab[i][1][1]='\0';
                                                 f(yytext);
                                                 i++;}
(mohit|avaneesh|harsh|shashank|aviral)          {tab[i][1][0]='b';
                                                 tab[i][1][1]='\0';
                                                 f(yytext);
                                                 i++;}
(i|he|she|it|they)                              {tab[i][1][0]='c';
                                                 tab[i][1][1]='\0';
                                                 f(yytext);
                                                 i++;}
(then|there|gently|quietly)                     {tab[i][1][0]='d';
                                                 tab[i][1][1]='\0';
                                                 f(yytext);
                                                 i++;}
(hot|beautiful|antique|fragrent)                {tab[i][1][0]='e';
                                                 tab[i][1][1]='\0';
                                                 f(yytext);
                                                 i++;}
(for|and|not|but|or|yet|so)                     {tab[i][1][0]='f';
                                                 tab[i][1][1]='\0';
                                                 f(yytext);
                                                 i++;}
(who|what|where|when|why)                       {tab[i][1][0]='g';
                                                 tab[i][1][1]='\0';
                                                 f(yytext);
                                                 i++;}
[A-Za-z]+                                       {tab[i][1][0]='h';
                                                 tab[i][1][1]='\0';
                                                 f(yytext);
                                                 i++;}
[$]                                             {return 0;}
[\n]                                            {i=0;}
%%
/*
void p(){
	int j;
	for(j=0;j<i;j++){
		printf("%s is %s\n",tab[i][0],tab[i][1]);
	}
	i=0;
}
*/
void f(char *pt){
	int j=0,k=0,flag=0;
	int in=0;
	int t=0;
	for(j=0;j<i;j++){
		while(*(pt+in)!='\0' && tab[i][0][k]!='\0'){
			if(*(pt+in)==tab[i][0][k])
				flag=0;
			else
				break;
			in++;
			k++;
		}
		if(tab[i][0][k]=='\0' && *(pt+in)!='\0')
			//flag=1;
		k=0;
		in=0;
	}
	if(flag==0){
	while(*(pt+in)!='\0'){
		tab[i][0][t]=*(pt+in);
		in++;
		t++;
	}
	tab[i][0][t]='\0';
//	p();
	printf("%s is %s\n",tab[i][0],tab[i][1]);
	}
}

int main(){
	yylex();
	return 0;
}
