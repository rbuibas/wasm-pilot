#include <emscripten/emscripten.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100000000

int EMSCRIPTEN_KEEPALIVE prime(int n)
{
    int i,j,count=0;

    if (n == 1) {
        // printf("2\n");
        return 1;
    }
    for(i=3;i<=MAX;i+=2)
    {
        int isPrime=1;
        int jMax = sqrt(i);
        for(j=3;j<=jMax;j+=2)
        {
            if(i%j==0)
            {
                isPrime=0;
                break;
            }
        }
        if(isPrime)
        {
            if(++count==n)
            {
                return i;
            }
        }
    }
    return 0;
}

int main()
{
   printf("WebAssembly Benchamrk (with C and JS)\n\n");
   return 0;
}


#ifdef __cplusplus
extern "C" {
#endif

int EMSCRIPTEN_KEEPALIVE wasmMain(int argc, char ** argv) {
    int nth_prime = 50;
    //  printf("%dth prime number = %d [C timing ]", nth_prime, prime(nth_prime));
    // printf("%d",prime(nth_prime));
    return prime(nth_prime);
}

#ifdef __cplusplus
}
#endif