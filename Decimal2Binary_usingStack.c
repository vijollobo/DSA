#include <stdio.h>
int main(){
    int dec,i=0;
    printf("Enter decimal number : ");
    scanf("%i",&dec);
    int bin[sizeof(int)*8];
    for(;dec>0;dec/=2) bin[i++]=dec%2; //PUSH
    for(int j=i-1;j>=0;j--)printf("%i",bin[j]); //DISPLAY 
}