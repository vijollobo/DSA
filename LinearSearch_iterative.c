#include <stdio.h>

int main(){
    int n; //stores number of elements in array
    printf("Enter number of elements you wish to enter : ");
    scanf("%i",&n);
    int a[n], n2search,found=0; // array of size n and n2search declared, value of found declared 0 (i.e. False)
    printf("Enter %i numbers :\n",n);
    for(int i=0;i<n;i++) scanf("%i",&a[i]); //elements of array input
    printf("Enter number to search : ");
    scanf("%i",&n2search); //number to be searched input
    int index=0; 
    for(;index<n;index++){ //loop run with index stored in global variable index
        if(a[index]==n2search) {
            found=1; //value of found turned 1 (i.e. True)
            break;
        }
    }
    (found)?printf("%i found in array at index %i",n2search,index):printf("%i not found in the array",n2search); //displays appropriate message
    
}
