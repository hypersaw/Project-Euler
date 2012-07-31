#include <stdio.h>

void howManyFactors(unsigned long long number, int* count);
unsigned long long highestDivisor = 0;

int main(int argc, char** argv){
	unsigned long long naturalSum = 0;
	int iterator;
	int count = 0;

	for(iterator = 0; count < 500; ++iterator){
		count = 0;
		naturalSum += iterator;
		howManyFactors(naturalSum,&count);

		if(count > highestDivisor){
			highestDivisor = count;
			printf("Natural Sum (%lld) has the highest count at %d\n",naturalSum,count);
		}
	}

	printf("%lld is the first triangle number to have over five hundered divisors!\n",naturalSum);
	return 0;
}

void howManyFactors(unsigned long long number, int* count){
	int iterator;

	for(iterator = 1; iterator <= number; ++iterator){
		if(number % iterator == 0){
			++(*count);
		}
	}
}
