#include <stdio.h>

void factor(unsigned long long number);

int largestPrime = 0;

int main(int argc, char** argv){
	factor(600851475143);

	printf("The largest prime factor of 600851475143 is: %d\n",largestPrime);

	return 0;
}

void factor(unsigned long long number){
	unsigned long long factored = number / 4;
	int divisible = 0;
	int i = 2;
	while(i < factored && !divisible){
		if(number % i == 0){
			divisible = 1;
			factor(i);
			factor(number/i);
		}
		++i;
	}

	if(!divisible && (number > 2)){
		if(number > largestPrime){
			largestPrime = number;
		}
	}
}
