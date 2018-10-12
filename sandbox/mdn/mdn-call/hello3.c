#include <stdio.h>
#include <emscripten/emscripten.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char ** argv) {
    printf("Hello World\n");
}


// Common good ol' prime checker
bool is_prime(long int n){
  	int i;
	if(n%2==0) return false;
	int sRoot = sqrt((double)n);
	for(i = 3; i <= sRoot; i+=2){
		if(n%i==0) return false;
	}
	
	return true;
}

// My pandigital checker. Maps a digit to an array to check if it is repeated in a number
bool pandigital(long int n){
	bool stash[] = {true,true,true,true,true,true,true,true,true};
	int digit,i = 0;
	while (n != 0){
		digit = n % 10;
		if(digit == 0) return false;
		else stash[digit-1] = false;
		
		n /= 10;
		i++;
	}
	
	for (i = i-1; i >= 0; i--){	if (stash[i] != false) return false; }
	return true;
}

// Since we will be checking on pandigital numbers only, we can thoroughly optimize
// the algorithm to select only what numbers to scan through. (Considering nga base 10 rapud)

// Divisibility rule of 3 is that when the sum of the digit of a number is divisible by
// 3 then it means that the number is also divisible by 3 and dili na siya prime :D

// From that, makabalo ta nga only numbers with 4 digits and 7 digits are pandigital primes
// 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28  -> for 7 digits
// 1 + 2 + 3 + 4 = 10 -> for 4 digits
// Mga dili divisible by 3 and therefore can be primes :D


#ifdef __cplusplus
extern "C" {
#endif

void EMSCRIPTEN_KEEPALIVE myFunction(int argc, char ** argv) {
  long int i;
	
  // Mangita una from 7 digit range, skip to 4 digit if walay nakitan.
  // print and return daun sa pinaka.una nga dako nga makit.an if naa
	for (i = 7654321; i >= 1234; i--){
		if (i == 1234567) i = 4321;
		if (pandigital(i) && is_prime(i)) {
			printf("The Highest Pandigital Prime Number is: %ld\n",i);
			return;
		}
	}
	
  // If wala jud nakit an, meaning 1 ra ang pandigital prime (Agui.. haha)
    printf("The Highest Pandigital Prime Number is: 1\n");
    return;
}

#ifdef __cplusplus
}
#endif