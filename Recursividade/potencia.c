
#include <stdio.h>
#include <stdlib.h>

int potencia(int n1 , int n2){
	
	if (n2 == 0)
		return 1;
	else{
		return n1 * potencia(n1 ,n2 - 1);
	}	
	
}

int main(){
	
	int x,y;
	
	printf("Digite um número ");
	scanf("%d" , &x);
	printf("Digite outro número ");
	scanf("%d" , &y);
	potencia(x,y);
	printf("%d elevado a %d é : %d " , x , y , potencia(x,y));
	
}
