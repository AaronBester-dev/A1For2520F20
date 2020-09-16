#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

}







unsigned long long bits2ull(char * bits){

    int i = strlen(bits)-1;
    int k = 0;
    unsigned long long ull = 0;

    while(bits[k] != '\0'){
        if(bits[k] == '1'){
            ull += (unsigned long long)pow(2,i);
           
        }
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
        if(k == 0 && bits[k] == '1'){
            ll += (long long)pow(-2,i);
           
        }
        else if( k != 0 && bits[k] == '1' ){
            ll += (long long)pow(2,i);
        
        }
        i--;
        k++;
    }

    return(ll);

}






void spff(char * sign, char * exponent, char * significand, float * src){

}





void dpff(char * sign, char * exponent, char * significant, double * src){

}

