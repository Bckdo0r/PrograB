#include <stdio.h>
void main(){
	int N,i,j;
	printf("Ingrese un N: ");
	scanf("%d",&N);

	for(i=0;i<N;i++)
		printf("#");
	printf("\n");
	
	for (j=2; j < N; j++){
		i=1;
		while (i<=N){
			if (i==1 || i==N)
				printf("#");
			else
				printf(" ");		
			i++;
		}
		printf("\n");		
	}

	for(i=0;i<N;i++)
		printf("#");
	printf("\n");
	printf("\n");
	printf("\n");

	for ( i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1)
				printf("#");
			else 
				printf(" ");
		}
		printf("\n");
	}
}