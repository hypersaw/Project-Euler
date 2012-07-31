#include <stdio.h>

int main(){
	long long primenumber = 3;
	long long remainder = 0;
	int count = 1;

	while(count < 10001){
		long long i;
		for(i = 2; i < primenumber; ++i){
			remainder = primenumber % i;
			if(remainder == 0){
				//printf("%d is not a prime number!\n",primenumber);
				++primenumber;
				i = 1;
			}
		}

		++count;
		if(primenumber < 0)
			printf("woopsie!\n");
		printf("We found our %d prime number (%d)!\n",count,primenumber);
		++primenumber;
	}

	return 0;
}
