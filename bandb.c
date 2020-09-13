#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bandb.h"


void getbytes(unsigned char dest[], int bytes, void * src, int reverse){

    int i = 0;
    int k = 0;

    if(reverse != 0){
       for(i = (bytes-1); i >=0; i--){
           dest[k] = &src[i];
           k++;
       }
    }
    else{
        for(o = 0; i <= bytes; i++){
            dest[i] = &src[i];
        }
    }
}

void getbits(char dest[], int bytes, void * src, int start, int end){

}

unsigned long long bits2ull(char * bits){

    int i = 0
    int k = 0;
    unsigned long long ull = 0;

    for(i = (strlen(bits)-1); i <= 0; i--){
        if(bits[k] == 1){
            ull += pow(2,i);
        }
        k++;
    }

    return(ull);

}

long long bits2ll(char * bits){


    int i = 0;
    int k = 0;
    
    long long ll = 0;

    for(i = (strlen(bits)-1); i <= 0; i--){
        if(k == 0){
            ll += pow(2,-i);
        }
        else if(bits[k] == 1){
            ll += pow(2,i);
        }
        k++;
    }


}

void spff(char * sign, char * exponent, char * significand, float * src){

}

void dpff(char * sign, char * exponent, char * significant, double * src){

}