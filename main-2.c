#include <stdio.h>
#include <stdlib.h>

void printHex(long long int a){
     printf("0x%016llX\n", a);
}

typedef union byte{
     
    struct each{
        char b[8];
    }each;
    
    long long int value;
    
} byte;

long long int hton64(long long int c){
     byte result;
     result.value = c;
     
     
    for (int i =0; i<4;i++){
         char temp = result.each.b[i]; 
         result.each.b[i]= result.each.b[7-i];
         result.each.b[7-i]=temp;
    }
     return result.value;
}

int main() {
    long long int a = 0x123456789ABCDEF0; 
    long long int res = hton64(a);
    printf("ORIGINAL: ");
    printHex(a);
    printf("\n");
    printf("MODIFIED: ");
    printHex(res);
    return 0;
}