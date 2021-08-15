#include<stdio.h>
#include<conio.h>
#define infinity 1000000
int D[100][100],PI[100][100],i,j,n,k;
int main(){
	printf("Enter no. of nodes:	");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if (i==j){
				D[i][j] = 0;
			}
			if (i!=j){			
				printf("Enter cost of D[%d][%d]	", i,j);
				scanf("%d", &D[i][j]);
			}
		}
		printf("\n");
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("Enter value of PI[%d][%d]	", i,j);
			scanf("%d", &PI[i][j]);	
		}
		printf("\n");
	}
	printf("\n\nMatrix D\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d	",D[i][j]);
		}
		printf("\n");
	}
	printf("\n\nMatrix PI\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d	",PI[i][j]);
		}
		printf("\n");
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(D[i][j] > (D[i][k] + D[k][j])){
					D[i][j] = (D[i][k] + D[k][j]);
					PI[i][j] = PI[k][j];
				}
			}
		}
	}
	printf("\n\nFinal D Matrix\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d	",D[i][j]);
		}
		printf("\n");
	}
	printf("\n\nFinal PI Matrix\n\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d	",PI[i][j]);
		}
		printf("\n");
	}
}



