#include<stdio.h>
#include<stdlib.h>
int p[100], mt[100][100], st[100][100];
void print_optimal(int i , int j){
	if(i==j){
		printf("A%d ", i);
	}
	else{
		printf("(");
		print_optimal(i, st[i][j]);
		print_optimal(st[i][j] + 1, j);
		printf(")");
	}
}
int main(){
	int i, j, k, m,n, l, q;
	printf("Enter no. of elements in p: ", m);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("Enter the value P %d ", i);
		scanf("%d", &p[i]);
		printf("\n");
	}
	n = m - 1;
	for(i=1;i<=4;i++){
		mt[i][i] = 0;
		st[i][i] = 0;
	}
	for(l=2; l<=n;l++ ){
		for(i=1;i<=(n-l+1);i++){
			j = i+l-1;
			mt[i][j] = 1000000;
			for(k = i ; k<=(j-1); k++){
				q = mt[i][k] + mt[k+1][j] + (p[i-1] * p[k] * p[j]);
				if(q< mt[i][j]){
					mt[i][j] = q;
					st[i][j] = k;
				}
			}
		}
	}
	printf("\n\n M Table \n\n");
	for(i = 1; i<=4; i++){
		for(j=1;j<=4;j++){
			printf("%d 	", mt[i][j]);
		}
		printf("\n");
	}
	printf("\n\n S Table \n\n");
	for(i = 1; i<=4; i++){
		for(j=1;j<=4;j++){
			printf("%d 	", st[i][j]);
		}
		printf("\n");
	}
	print_optimal(1 , n);
	printf("\nHence minimum cost for multiplication will be = %d",
	mt[1][n]);
}
