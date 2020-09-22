#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bandb.h"

/*Gets the bytes from any source and takes each byte from source and puts it in a char string */
void getbytes(unsigned char dest[], int bytes, void * src, int reverse){
    int byteIndex = 0;
    int reversedArrayIndex = 0;
    unsigned char * input = src;
    /*Gets the string in reverse by taking the rightmost bit needed first instead of the left.*/
    if(reverse != 0){
       for(byteIndex = (bytes-1); byteIndex >= 0; byteIndex--){
           dest[reversedArrayIndex] = input[byteIndex];
           reversedArrayIndex++;
       }
       dest[reversedArrayIndex] = '\0';
    }
    /*Otherwise just gets the bits needed in order*/
    else{
        for(byteIndex = 0; byteIndex < bytes; byteIndex++){   
            dest[byteIndex] = input[byteIndex];
        }
        dest[byteIndex] = '\0';
    }
}

/*Gets each individual bits from a source and prints each bit as a char in a string */
void getbits(char dest[], int bytes, void * src, int start, int end){
    unsigned char * byteArray = (unsigned char *)src;
    int currentByte = bytes - (start/8) - 1;
    int currentBit = (start % 8);
    int i = 0;
    int bitsNeeded = start - end;
    
    while(i < bitsNeeded){
        /*Shifts the bit needed into the rightmost position so we can check it with the 1 bit and see whether its on or off */
        /*The + '0' addition simply adds the ascii code of 0 to the original value in order to change it from a int to a char */
         dest[i] = ((byteArray[currentByte] >> currentBit) & 1) + '0';

         currentBit--;
         if(currentBit < 0){
             currentBit = 7;
             currentByte++;
         }
         i++;
    }
    dest[i] = '\0';
}

/*Takes a string of bits and converts it into its decimal value. */
unsigned long long bits2ull(char * bits){
    int bitPosition = strlen(bits)-1;
    int currentBit = 0;
   
    unsigned long long ull = 0;

    while(bits[currentBit] != '\0'){
        /*Takes every bit in bit string and multiplies it by 2 ^ of the bit position */;
        /* 1 is type casted to unsigned long long because 1 is naturally a integer but a integer only has 32 bits so you can only go up to 2^31 where as the highest test case needs to go to
        2^63 so you need to make 1 have 64 bits by type casting it to a 64 or higher bit type.*/
        ull += (bits[currentBit]-'0') * ((unsigned long long)1 << bitPosition); 
        bitPosition--;
        currentBit++;
    }
    
    return(ull);

}
/*Takes a string of two's complement bits and converts it into its decimal value. */
long long bits2ll(char * bits){
    int bitPosition = strlen(bits)-1;
    int currentBit = 0;
    long long ll = 0;
    /*Simply takes the first bit and makes it negative.*/
    /* 1 is type casted to unsigned long long because 1 is naturally a integer but a integer only has 32 bits so you can only go up to 2^31 where as the highest test case needs to go to
    2^63 so you need to make 1 have 64 bits by type casting it to a 64 bit or higher type.*/
    ll += (-1) * (bits[currentBit]-'0') * ((long long)1 << bitPosition);
    bitPosition--;
    currentBit++;

    while(bits[currentBit] != '\0'){
        /*Takes every bit in bit string and multiplies it by 2 ^ of the bit position */;
        ll += (bits[currentBit]-'0') * ((long long)1 << bitPosition);
        bitPosition--;
        currentBit++;
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

