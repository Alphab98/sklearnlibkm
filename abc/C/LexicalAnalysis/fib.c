#include<stdio.h>
void main(){
	int i,j,k,l,n;
	i=1;
	j=1;
	scanf("%d",&n);
	printf("1\n1\n");
	for(l=2;l<n;l++){
		k=i+j;
		printf("%d\n",k);
		i=j;
		j=k;
	}
}
