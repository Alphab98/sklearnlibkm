#include<stdio.h>  
#include<string.h>  
#define SIZE 10 
int num;
char production[25][SIZE];

int main () {  
    char non_terminal;  
    int index=3; 
    int j;
    int count=0;
    int n;
    printf("Enter Number of Production : ");  
    scanf("%d",&num);  
    printf("Enter the grammar as E->E-A :\n");  
    for(int i=0;i<num;i++){  
        scanf("%s",production[i]);  
    }  
    for(int i=0;i<num;i++){ 
        printf("\nGRAMMAR : : : %s",production[i]);  
        non_terminal=production[i][0];  
        if(non_terminal==production[i][index]) {  
            printf(" is left recursive.\n"); 
			printf("Grammar without left recursion:\n");
            j=i+1;
            while(j<num) {
                if(production[j][0]==production[i][0]) {
                    count++;
                    n=strlen(production[j]);
                    production[j][n]=production[j][0];
                    production[j][n+1]='\'';
                    production[j][n+2]='\0';
					printf("%s\n",production[j]);
                }
                j++;
            }
            if(count>0) {
				char str[6];
				str[0]=production[i][0];
				str[1]='\'';
				str[2]='-';
				str[3]='>';
				str[4]='@';
				str[5]='\0';
                count=0;
                n=strlen(production[i]);
                while(production[i][count]!='-')
                    count++;
                production[i][n+1]='\0';
                for(j=n;j>=count;j--)
                    production[i][j]=production[i][j-1];
                production[i][count]='\'';
                count=0;
                n=strlen(production[i]);
                while(production[i][count]!='>')
                    count++;
                for(j=count+1;j<n-1;j++)
                    production[i][j]=production[i][j+1];
                production[i][j]=production[i][0];
                production[i][j+1]='\'';
                production[i][j+2]='\0';
                strcpy(production[num],str);
                num++;
                printf("%s\n",production[i]);
                printf("%s\n",production[num-1]);
                
            }
            else
                printf(" can't be reduced\n");
            
		}  
        else  
            printf(" is not left recursive.\n");   
    }  
} 

 