#include <stdio.h>

int main(){
	int natural = 0;
	int sum = 0;

	// Find sum of squares and sum of natural
	int i = 1;
	for(i; i < 101; ++i){
		natural += i;
		sum += (i * i);
	}

	// Square of natural
	natural *= natural;

	printf("Difference: %d\n",natural - sum);

	return 0;
}

