#include <stdio.h>

int sum = 0;
int fibonacciSequence(int first, int second);

int main(int argc, char** argv){
	sum += 2;
	fibonacciSequence(1, 2);

	printf("Sum of the even-valued terms below 4,000,000: %d\n",sum);
	return 0;
}

int fibonacciSequence(int first, int second){
	int third = first + second;
	if(third < 4000000){
		if(third % 2 == 0){
			sum += third;
		}
		fibonacciSequence(second, third);
	}
	return third;
}
