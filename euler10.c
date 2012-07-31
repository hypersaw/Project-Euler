#include <stdio.h>

int isPrime(unsigned long number);

unsigned long goTo = 2000000;

int main(){
	unsigned long i,stored = 0;
	unsigned long long  sum = 0;
	for(i = 0; i < goTo; ++i){
		if(isPrime(i)){
			if(i > (stored * 2)){
				printf("%lu\n",i);
				stored = i;
			}
			sum += i;
		}
	}

	printf("Sum: %llu\n",sum);
}

int isPrime(unsigned long number){
	int prime = 1;
	if((number == 0) || (number == 1))
		return !prime;
	else{
		unsigned long i;

		for(i = 2; i < ((number/2) + 1); i = i + 2){
			if(number % i == 0){
				return !prime;
			}
		}

		return prime;
	}
}
