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
    char * byteArray = src;
    int i = bytes -(start/8);
    int k = (start % 8);
    printf("%d i=%d k=%d\n",sizeof(unsigned short),i,k);
    int c = 0;
    int bingus = 0;
    /*
    int byteStart = bytes -(start/8) -1;
    int bitStart = (start%8);
    int byteEnd = bytes-(end/8) -1;
    int bitEnd = end%8;
    */
    int bitsNeeded = start - (end+1);

    while(strlen(dest) < bitsNeeded){

         bingus = (byteArray[i] >> k) & 1;
         
         if(bingus == 1){
             dest[c] = '1';
         }
         else{
             dest[c] = '0';
         }
        
         k--;
         if(k < 0){
             k = 7;
             i--;
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
    char * byteArray = (char *)src;
    int i = 3;
    int k = 7;
  
    int c = 0;
    int bingus = 0;
    /*
    int byteStart = bytes -(start/8) -1;
    int bitStart = (start%8);
    int byteEnd = bytes-(end/8) -1;
    int bitEnd = end%8;0.15625
    */
    

    

         bingus = (byteArray[i] >> k) & 1;
         
         if(bingus == 1){
             sign[0] = '1';
         }
         else{
             sign[0] = '0';
         }
         k--;
         sign[1] = '\0';

         while(c < 8){
             bingus = (byteArray[i] >> k ) & 1;
            
            if(bingus == 1){
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
         while(c < 23){
              bingus = (byteArray[i] >> k ) & 1;
            
            if(bingus == 1){
                significand[c] = '1';
            }
            else{
                significand[c] = '0';
            }
            k--;
            if(k < 0){
                k = 7;
                i--;
            }
            c++;
         }
   
    significand[c] = '\0';
}





void dpff(char * sign, char * exponent, char * significant, double * src){
    char * byteArray = (char *)src;
    int i = 7;
    int k = 7;
  
    int c = 0;
    int bingus = 0;
    /*
    int byteStart = bytes -(start/8) -1;
    int bitStart = (start%8);
    int byteEnd = bytes-(end/8) -1;
    int bitEnd = end%8;0.15625
    */
    

    

         bingus = (byteArray[i] >> k) & 1;
         
         if(bingus == 1){
             sign[0] = '1';
         }
         else{
             sign[0] = '0';
         }
         k--;
         sign[1] = '\0';

         while(c < 11){
             bingus = (byteArray[i] >> k ) & 1;
            
            if(bingus == 1){
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
              bingus = (byteArray[i] >> k ) & 1;
            
            if(bingus == 1){
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
}

