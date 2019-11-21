#include<stdio.h>  
#include<string.h>  
#include<ctype.h>
#define SIZE 10 
int num;
char production[25][SIZE];
char non();
void lf();
int main () { 

    printf("Enter Number of Production : ");  
    scanf("%d",&num);
    printf("Enter the grammar as E->E-A :\n");  
    for(int i=0;i<num;i++){  
        scanf("%s",production[i]); 
    }
	lf();
}

char non() {
    char ch[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count=1;
    for(int k=0;k<26;k++){
        if(count==1) {
            for(int j=0;j<num;j++){
                if(production[j][0]!=ch[k])
                    count=0;
                else{
                    count=1;
                    break;
                }
            }
        }else
        return ch[k-1];
    }
}

void lf(){
    char ch;
	for(int m=0;m<num;m++) {
	    for(int n=0;n<num;n++) {
	        char modified[20],new1[20],new2[20];
	        int i,j=0,k=3,l=0,pos;
	        if(n!=m && production[m][3]==production[n][3] && production[m][0]==production[n][0]){
	            modified[0]=production[m][0];
	            modified[1]='-';
	            modified[2]='>';
            	for(i=3;i<strlen(production[m])||i<strlen(production[n]);i++){  
            		if(production[m][i]==production[n][i]){  
            			modified[k]=production[m][i];  
            			k++;  
            			pos=i+1;  
            		} 
					else
						break;
            	}
            	ch=non();
				modified[k]=ch;
            	modified[++k]='\0';
            	new1[0]=ch;
            	new1[1]='-';
            	new1[2]='>';
            	for(i=pos,j=3;production[m][i]!='\0';i++,j++)
            			new1[j]=production[m][i];
            	new1[j]='\0';
            	new2[0]=ch;
            	new2[1]='-';
            	new2[2]='>';
            	for(i=pos,j=3;production[n][i]!='\0';i++,j++)  
            			new2[j]=production[n][i];
            	new2[j]='\0';
				strcpy(production[m],modified);
            	strcpy(production[n],new2);
            	strcpy(production[num],new1);
            	    num++;
            	//printf("\n %s",production[num-1]);  
            	//printf("\n %s\n",production[m]); 
            	//printf("\n %s\n",production[n]);
	        }
	    }
	}
	printf("\n\n");
	for(int i=0;i<num;i++)
		printf("%s\n",production[i]);
}
 

