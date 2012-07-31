#include <stdio.h>

int main(int argc, char** argv){
	int sum = 0;
	int x;

	for(x = 0; x < 1000; ++x){
		if((x % 3) == 0 || (x % 5) == 0){
			sum += x;
		}
	}

	printf("Sum of all multiples of 3 or 5 below 1000: %d\n", sum);
	return 0;
}
