#include<stdio.h>
#include<string.h>
char gra[10][20],cha,cha2,has[10][10][10];
void trans(int);
void fst(int,int,int,int,int);
void main(){
	int n,i,j;
	printf("Insert number of productions\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",gra[i]);
	}
	for(i=0;i<n;i++){
		trans(i);
	}
/*	for(i=0;i<n;i++){
		for(j=0;j<10;j++){
			printf("%s\n",has[i][j]);
		}
	}*/
	for(i=0;i<n;i++){
		printf("%c=",has[i][0][0]);
		fst(n,i,0,0,0);
		printf("\n");
	}
}
void trans(int a){
	int i,j,x,y;
	i=0;
	j=0;
	has[a][i][j]=gra[a][0];
	i++;
	x=a;
	y=2;
	while(y<20){
		if(gra[x][y]!='|' || gra[x][y]!='\0'){
			has[a][i][j]=gra[x][y];
			j++;
			y++;
		}
		if(gra[x][y]=='|'){
			has[a][i][j]='\0';
			i++;
			j=0;
			y++;
		}
		if(gra[x][y]=='\0'){
			has[a][i][j]='\0';
			y=20;
			i++;
		}
	}
}
void fst(int n,int a,int x,int y,int z){
	int i,j,k,flag,flag2;
	i=1;
	while(has[a][i][0]!='\0'){
		flag=0;
		cha=has[a][i][0];
		for(j=0;j<n;j++){
			if(cha==has[j][0][0]){
				flag=1;
			}
			
		}
		if(cha=='E'){
//			printf("E  ");
			cha2=has[x][y][z+1];
			if(cha2!='\0'){
				flag2=0;
				for(k=0;k<n;k++){
					if(has[k][0][0]==cha2){
						fst(n,k,x,y,z+1);
						flag2=1;
					}
				}
				if(flag2==0){
					printf("%c  ",cha2);
				}
			}
			else{
				printf("E  ");
			}
		}
		else{
			if(flag==1){
				for(k=0;k<n;k++){
					if(has[k][0][0]==cha){
						fst(n,k,a,i,0);
					}
				}
			}
			else{
				printf("%c  ",cha);
			}
		}
		i++;
	}
}
