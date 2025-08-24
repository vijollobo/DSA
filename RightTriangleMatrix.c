#include <stdio.h>

int main(){
    int n;
    printf("Enter size of square matrix : ");
    scanf("%i",&n); //value of n input
    int mat[n][n]; //2D array of size n*n declared
    printf("Enter %i elements of the %i×%i matrix :\n",n*n,n,n);
    for (int r=0;r<n;r++){
        for (int c=0;c<n;c++){
            printf("Enter element a%i%i : ",r+1,c+1);
            scanf("%i",&mat[r][c]); 
        }
    } //elements of matrix input
    int flag=0; //flog to check if matrix is right triangle matrix or not
    for (int r=0;r<n;r++){
        for (int c=0;c<n;c++){
            if (r<c){
                if (mat[r][c]==0){
                    flag=1;
                    break;
                }
            }
        }
    }
    
    printf((flag)?"Given matrix is a right triangle matrix":"Given matrix isn't a right triangle matrix");

}
