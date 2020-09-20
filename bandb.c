#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bandb.h"

/*Gets the bytes from any source and takes each byte from source and puts it in a char string */
void getbytes(unsigned char dest[], int bytes, void * src, int reverse){
    int i = 0;
    int k = 0;
    unsigned char * input = src;
    /*Gets the string in reverse by taking the rightmost bit needed first instead of the left.*/
    if(reverse != 0){
       for(i = (bytes-1); i >= 0; i--){
           dest[k] = input[i];
           k++;
       }
       dest[k] = '\0';
    }
    /*Otherwise just gets the bits needed in order*/
    else{
        for(i = 0; i < bytes; i++){   
            dest[i] = input[i];
        }
        dest[i] = '\0';
    }
}

/*Gets each individual bits from a source and prints each bit as a char in a string */
void getbits(char dest[], int bytes, void * src, int start, int end){
    unsigned char * byteArray = (unsigned char *)src;
    int i = bytes - (start/8) - 1;
    int k = (start % 8);
    int c = 0;
    int bitsNeeded = start - end;
    
    while(c < bitsNeeded){
        /*Shifts the bit needed into the rightmost position so we can check it with the 1 bit and see whether its on or off */
        /*The + '0' addition simply adds the ascii code of 0 to the original value in order to change it from a int to a char */
         dest[c] = ((byteArray[i] >> k) & 1) + '0';

         k--;
         if(k < 0){
             k = 7;
             i++;
         }
         c++;
    }
    dest[c] = '\0';
}

/*Takes a string of bits and converts it into its decimal value. */
unsigned long long bits2ull(char * bits){
    int i = strlen(bits)-1;
    int k = 0;
   
    unsigned long long ull = 0;

    while(bits[k] != '\0'){
        /*Takes every bit in bit string and multiplies it by 2 ^ of the bit position */;
        ull += (bits[k]-'0') * ((unsigned long long)1 << i); 
        i--;
        k++;
    }
    
    return(ull);

}
/*Takes a string of two's complement bits and converts it into its decimal value. */
long long bits2ll(char * bits){
    int i = strlen(bits)-1;
    int k = 0;
    long long ll = 0;
    /*Simply takes the first bit and makes it negative.*/
    ll += (-1) * (bits[k]-'0') * ((long long)1 << i);
    i--;
    k++;

    while(bits[k] != '\0'){
        /*Takes every bit in bit string and multiplies it by 2 ^ of the bit position */;
        ll += (bits[k]-'0') * ((long long)1 << i);
        i--;
        k++;
    }

    return(ll);

}

void spff(char * sign, char * exponent, char * significand, float * src){
    unsigned char dest[5];
    /*getbytes is only used to reverse the bytes in the src string so that it shows up forwards when using getbits*/
    getbytes(dest,4,src,1);
    getbits(sign,4,dest,31,30);
    getbits(exponent,4,dest,30,22);
    getbits(significand,4,dest,22,-1);
}

void dpff(char * sign, char * exponent, char * significant, double * src){
    /*getbytes is only used to reverse the bytes in the src string so that it shows up forwards when using getbits*/
    unsigned char dest[9];
    getbytes(dest,8,src,1);
    getbits(sign,8,dest,63,62);
    getbits(exponent,8,dest,62,51);
    getbits(significant,8,dest,51,-1);
}

