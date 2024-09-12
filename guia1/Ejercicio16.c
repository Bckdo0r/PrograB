#include <stdio.h>

void main() {
	unsigned int seg,hs=0,min=0;
	printf("Ingrese una cantidad de segundos: ");
	scanf("%d",&seg);

	while(seg>=60){
		seg-=60;
		min++;

		if (min>=60){
			hs++;
			min-=60;
		}		
	}

	printf("%02d:%02d:%02d",hs,min,seg);

}