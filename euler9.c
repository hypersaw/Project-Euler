#include <stdio.h>
#include <math.h>

int main(){
	int a = 1, b = 1;
	double c = 0;
	int result = 0;
	while(result != 1000){
		for(a = 1; a < 1000; ++a){
			for(b = 1; b < 1000;++b){
				c = sqrt((a * a) + (b * b));
				if((c - (int)c) == 0){
					result = a + b + (int)c;
					if(result == 1000)
						printf("Triple {%d, %d, %d}: %d\n",a,b,(int)c,result);
				}
			}
		}
	}
}
