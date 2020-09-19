#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bandb.h"


void getbytes(unsigned char dest[], int bytes, void * src, int reverse){
    int i = 0;
    int k = 0;
    unsigned char * input = src;
    
    if(reverse != 0){
       for(i = (bytes-1); i >= 0; i--){
           dest[k] = input[i];
           k++;
       }
       dest[k] = '\0';
    }
    else{
        for(i = 0; i < bytes; i++){   
            dest[i] = input[i];
        }
        dest[i] = '\0';
    }
}

void getbits(char dest[], int bytes, void * src, int start, int end){
    unsigned char * byteArray = (unsigned char *)src;
    int i = bytes - (start/8) - 1;
    int k = (start % 8);
    int c = 0;
    int bitsNeeded = start - end;
    
    while(c < bitsNeeded){
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

unsigned long long bits2ull(char * bits){
    int i = strlen(bits)-1;
    int k = 0;
   
    unsigned long long ull = 0;

    while(bits[k] != '\0'){
        ull += (bits[k]-'0') * ((unsigned long long)1 << i); 
        i--;
        k++;
    }
    
    return(ull);

}

long long bits2ll(char * bits){
    int i = strlen(bits)-1;
    int k = 0;
    long long ll = 0;

    while(bits[k] != '\0'){
        if(((i % 2) != 0) && (k == 0)){
            ll += -(bits[k]-'0') * ((long long)1 << i);
        }
        else{
            ll += (bits[k]-'0') * ((long long)1 << i);
        }
        i--;
        k++;
    }

    return(ll);

}

void spff(char * sign, char * exponent, char * significand, float * src){
    unsigned char dest[5];
    getbytes(dest,4,src,1);
    getbits(sign,4,dest,31,30);
    getbits(exponent,4,dest,30,22);
    getbits(significand,4,dest,22,-1);
}





void dpff(char * sign, char * exponent, char * significant, double * src){
    unsigned char dest[9];
    getbytes(dest,8,src,1);
    getbits(sign,8,dest,63,62);
    getbits(exponent,8,dest,62,51);
    getbits(significant,8,dest,51,-1);
    
   /*
    char * byteArray = (char *)src;
    int i = 7;
    int k = 7;
  
    int c = 0;
    int intConv = 0;
    intConv = (byteArray[i] >> k) & 1;
         
    if(intConv == 1){
        sign[0] = '1';
    }
    else{
        sign[0] = '0';
    }
    k--;
    sign[1] = '\0';

         while(c < 11){
             intConv = (byteArray[i] >> k ) & 1;
            
            if(intConv == 1){
                exponent[c] = '1';
            }
            else{
                exponent[c] = '0';
            }
            k--;
            if(k < 0){
                k = 7;
                i--;
            }
            c++;
         }
         exponent[c] = '\0';
        c = 0;
         while(c < 52){
              intConv = (byteArray[i] >> k ) & 1;
            
            if(intConv == 1){
                significant[c] = '1';
            }
            else{
                significant[c] = '0';
            }
            k--;
            if(k < 0){
                k = 7;
                i--;
            }
            c++;
         }
   
    significant[c] = '\0';
    */
}

