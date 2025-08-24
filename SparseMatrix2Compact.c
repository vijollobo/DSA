#include <stdio.h>
void main(){
    //take input of sparse matrix
    int nr,nc;
    printf("Enter number of rows : ");
    scanf("%i",&nr); //No. of rows input
    printf("Enter number of columns : ");
    scanf("%i",&nc); //No. of colums input
    int sparse[nr][nc]; //2D array (matrix) declared
    printf("Enter %i elements of the matrix :\n",nr*nc);
    for (int r=0;r<nr;r++){ 
        for (int c=0;c<nc;c++){
            printf("Enter element %i%i : ",r,c);
            scanf("%i",&sparse[r][c]);
        }
    } //Elements in sparse matrix input
    printf("\nEntered Sparse Matrix:\n");
    for (int r=0;r<nr;r++) {printf("\n");
        for (int c=0;c<nc;c++)
            printf("%i ", sparse[r][c]);
    }//Entered sparse matrix Displayed
    
    //conversion of sparse matrix into compact matrix
    int nz=0; //stores no of non-zero elements in matrix
    for (int r=0;r<nr;r++){
        for (int c=0;c<nc;c++){
            if (sparse[r][c]!=0) nz++; //nz incremented by 1 if element isn't 0
        }
    }
    //Making of compact matrix
    int compact[nz+1][3];
    compact[0][0]=nr;
    compact[0][1]=nc;
    compact[0][2]=nz;
    int i=1;
    for (int r=0;r<nr;r++){ 
        for (int c=0;c<nc;c++){
            if (sparse[r][c]!=0){
                compact[i][0]=r;
                compact[i][1]=c;
                compact[i][2]=sparse[r][c];
                i++;
            }
        }
    }
    //Display the compact matrix
    printf("\n\nCompact matrix : ");
    for (int r=0;r<=nz;r++){printf("\n");
        for (int c=0;c<3;c++)
            printf("%i ",compact[r][c]);
    }
    
    //Convert compact matrix into transpose of sparse matrix
    nr=compact[0][1],nc=compact[0][0];
    int sparse_transpose[nr][nc]; //transpose matrix created 
    
    for (int r=0;r<nr;r++) { 
        for (int c=0;c<nc;c++)
            sparse_transpose[r][c]=0; // All values of transpose matrix initialized as 0
    }
    
    for (int i=1;i<=nz;i++) sparse_transpose[compact[i][1]][compact[i][0]]=compact[i][2];
    
    // Display the transposed sparse matrix
    printf("\n\nTransposed Sparse Matrix  :");
    for (int r=0;r<nr;r++) {printf("\n");
        for (int c=0;c<nc;c++)
            printf("%i ", sparse_transpose[r][c]);
    }
}