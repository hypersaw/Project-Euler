#include <stdio.h>

int main(){
	int number = 2520;
	int i;

	for(i = 1; i < 21; ++i){
		if((number % i) != 0){
			++number;
			i = 0;
		}
	}

	printf("Smallest number evenly divisable from 1 to 20 is %d\n",number);

	return 0;
}
