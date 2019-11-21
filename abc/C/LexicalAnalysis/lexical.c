#include<stdio.h>
#include<string.h>
void main(){
	int a=1,b,i,j;
	FILE *filep;
	char tem1,tem2,data[200],fra[100][10];
	char key[32][10]={"char","auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","extern","return","union"
,"const","float","short","unsigned","continue","for","signed","void","default","goto","sizeof","volatile","do","if","static","while"};
	char rem[2][10]={"printf","scanf"};
	char ope[8][10]={"+","++","-","--","*","/","=","=="};
	for(i=0;i<100;i++){
		for(b=0;b<10;b++){
			fra[i][b]='\0';
		}
	}
	for(i=0;i<200;i++){
		data[i]='\0';
	}
	b=0;
	filep=fopen("fib.c","r");
	while(fgets(data,100,filep)!=NULL){
		for(i=0;i<100;i++){
			if(data[i]=='#'||data[i]=='<'||data[i]=='>'||data[i]=='('||data[i]==')'||data[i]==','||data[i]=='['||data[i]==']'||data[i]=='{'||data[i]=='}'||data[i]==';'||data[i]=='\t'||data[i]=='"'||data[i]=='\n')
				data[i]=' ';
		}
//		printf("%s",data);
		for(i=0;i<100;i++){
			if(data[i]=='+' && data[i+1]=='+'){
				tem1=' ';
				for(j=i;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i++;
				tem1=' ';
				for(j=i+2;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i=i+2;
			}
			if(data[i]=='+' && data[i+1]!='+'){
				tem1=' ';
				for(j=i;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				tem1=' ';
				for(j=i+2;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i=i+2;
			}
			if(data[i]=='-' && data[i+1]=='-'){
				tem1=' ';
				for(j=i;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i++;
				tem1=' ';
				for(j=i+2;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i=i+2;
			}
			if(data[i]=='-' && data[i+1]!='-'){
				tem1=' ';
				for(j=i;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				tem1=' ';
				for(j=i+2;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i=i+2;
			}
			if(data[i]=='/'){
				tem1=' ';
				for(j=i;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				tem1=' ';
				for(j=i+2;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i=i+2;
			}
			if(data[i]=='*'){
				tem1=' ';
				for(j=i;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				tem1=' ';
				for(j=i+2;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i=i+2;
			}
			if(data[i]=='=' && data[i+1]=='='){
				tem1=' ';
				for(j=i;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i++;
				tem1=' ';
				for(j=i+2;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i=i+2;
			}
			if(data[i]=='=' && data[i+1]!='='){
				tem1=' ';
				for(j=i;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				tem1=' ';
				for(j=i+2;tem1!='\0';j++){
					tem2=data[j];
					data[j]=tem1;
					tem1=tem2;
				}
				i=i+2;
			}
		}
		i=0;
		while(data[i]!='\0'){
			
			if(data[i]==' ')
				i++;
			else{
				fra[a][b]=data[i];
				i++;
				b++;
				if(data[i]==' '){
					fra[a][b]='\0';
					b=0;
					a++;
				}
			}
		}
	}
	printf("Header files:\n");
	for(i=0;i<100;i++){
		if(strcmp(fra[i],"include")==0){
			printf("%s\n",fra[i+1]);
			for(b=0;b<10;b++){
				fra[i][b]='\0';
				fra[i+1][b]='\0';
			}
		}
	}
	printf("Keywords are:\n");
	for(i=1;i<100;i++){
		for(a=0;a<32;a++){
			if(strcmp(fra[i],key[a])==0){
				printf("%s\n",fra[i]);
				for(b=0;b<10;b++){
					fra[i][b]='\0';
				}
			}
		}
	}
	printf("Operators are:\n");
	for(i=1;i<100;i++){
		for(a=0;a<8;a++){
			if(strcmp(fra[i],ope[a])==0){
				printf("%s\n",fra[i]);
				for(b=0;b<10;b++){
					fra[i][b]='\0';
				}
			}
		}
	}
	for(i=0;i<100;i++){
		for(a=0;a<2;a++){
			if(strcmp(fra[i],rem[a])==0){
				for(b=0;b<10;b++){
//					fra[i][b]='\0';
					fra[i+1][b]='\0';
				}
			}
		}
	}
	for(i=0;i<100;i++){
		if(fra[i][0]=='%'){
			for(b=0;b<10;b++){
				fra[i][b]='\0';
			}
		}
	}
	printf("Identifiers are:\n");
	for(i=0;i<100;i++){
		if(fra[i][0]!='\0'){
			printf("%s\n",fra[i]);
		}
	}
/*	for(i=0;i<100;i++){
		printf("%s\n",fra[i]);
	}*/
}
