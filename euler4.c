#include <stdio.h>
#include <string.h>

int largestPalindrome = 0;
static int largestProduct = 6;	// Largest product (digit count)  of two 3-digit values

int main(int argc, char** argv){
	int digit1 = 999;
	int digit2 = 999;
	int palindrome = 0;
	char palindromeString[6];
	int notPalindrome = 1;

	while(digit1 > 99 && notPalindrome){
		while(digit2 > 99){
			palindrome = digit1 * digit2;
			// Extract palindrome
			palindromeString[5] = palindrome % 10;
			palindromeString[4] = palindrome % 100 / 10;
			palindromeString[3] = palindrome % 1000 / 100;
			palindromeString[2] = palindrome % 10000 / 1000;
			palindromeString[1] = palindrome % 100000 / 10000;
			palindromeString[0] = palindrome % 1000000 / 100000;

			int i = 0;
			int startPoint = 0;
			while(i < 6){
				if(palindromeString[i] == 0){
					++i;
				}
				else{
					startPoint = i;
					i = 6;
				}
			}

			i = (6 - startPoint) / 2;
			notPalindrome = 0;
			for(startPoint; startPoint < i; ++startPoint){
				if(palindromeString[startPoint] != palindromeString[5 - startPoint]){
					notPalindrome = 1;
					startPoint = i;
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
