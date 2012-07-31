#include <stdio.h>
#include <string.h>
#include <math.h>

int largestPalindrome = 0;
static int largestProduct = 6;	// Largest product (digit count)  of two 3-digit values

int main(int argc, char** argv){
	int digit1 = 999;
	int digit2 = 999;
	int palindrome = 0;
	char palindromeString[largestProduct];
	int notPalindrome = 1;
	int iterator;
	int startPoint;

	while(digit1 > 99 && notPalindrome){
		while(digit2 > 99){
			palindrome = digit1 * digit2;
			// Extract palindrome
			for(iterator = 1; iterator <= largestProduct; ++iterator){
				palindromeString[largestProduct - iterator] = palindrome % (int)pow(10,iterator) / (int)pow(10,iterator-1);
			}

			iterator = 0;
			startPoint = 0;
			for(iterator; iterator < largestProduct; ++iterator){
				if(palindromeString[iterator] != 0){
					startPoint = iterator;
					iterator = largestProduct;
				}
			}

			iterator = (largestProduct - startPoint) / 2;
			notPalindrome = 0;
			for(startPoint; startPoint < iterator; ++startPoint){
				if(palindromeString[startPoint] != palindromeString[(largestProduct - 1) - startPoint]){
					notPalindrome = 1;
					startPoint = iterator;
				}
			}

			if(!notPalindrome){
				if(palindrome > largestPalindrome){
					largestPalindrome = palindrome;
				}
			}

			--digit2;
		}

		--digit1;
		digit2 = digit1;
	}

	printf("The largest palindrome from two 3-digit values being multiplied is: %d\n",largestPalindrome);

	return 0;
}
