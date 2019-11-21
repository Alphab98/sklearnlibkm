%{ 
int count=0;
int a=0,b=0,c=0,d=0,e=0,f=0;
char st[6][50][10];
void enter(char *,int,int);
void print();
%}

%% 
(play|eat|dance|write|sing|run|walk) { enter(yytext,0,a); a++;}
(mohit|shilong) {enter(yytext,1,b); b++;}
(i|he|she|it|they) {enter(yytext,2,c); c++; }
(hot|beatifull|antique|frag) {enter(yytext,3,d); d++;}
(then|there|gently|quiently) {enter(yytext,4,e); e++; }
(in|for|and|not|but|or) {enter(yytext,5,f); f++; }
[\n] {print();}
%%

void enter(char *ptr,int i,int x){
int ind=0;
int y=0;
for(int j=0;j<50;j++){
	ind =0;
	for(int k=0;k<10;k++){
		if(*(ptr+ind)=='\0')
			return;
		if(st[i][j][k] == *(ptr+ind))
			ind++;
		else
			break;
	}
}
ind = 0;
	while(*(ptr+ind)!='\0'){		
		st[i][x][y] = *(ptr+ind);
		ind++;
		y++;
}
}	

void print(){
printf("verb -- >");
for(int i=0;i<50;i++){
	for(int j=0;j<10;j++){
		printf("%c",st[0][i][j]);
	}
	printf("   ");
}
printf("\nnoun -- >");
for(int i=0;i<50;i++){
	for(int j=0;j<10;j++){
		printf("%c",st[1][i][j]);
	}
	printf("   ");
}
printf("\npronoun -- >");
for(int i=0;i<50;i++){
	for(int j=0;j<10;j++){
		printf("%c",st[2][i][j]);
	}
	printf("   ");
}
printf("\nadjective -- >");
for(int i=0;i<50;i++){
	for(int j=0;j<10;j++){
		printf("%c",st[3][i][j]);
	}
	printf("   ");
}
printf("\nadverb -- >");
for(int i=0;i<50;i++){
	for(int j=0;j<10;j++){
		printf("%c",st[4][i][j]);
	}
	printf("   ");
}
printf(" conjuction-- >");
for(int i=0;i<50;i++){
	for(int j=0;j<10;j++){
		printf("%c",st[5][i][j]);
	}
	printf("   ");
}
}
int main(){
yylex();
}
