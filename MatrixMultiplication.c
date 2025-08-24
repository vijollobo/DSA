#include <stdio.h>
void input(int rows, int cols, int mat[rows][cols], char name) {
    printf("\nEnter %i elements of %c (%d x %d):\n", rows*cols, name, rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            printf("%c[%d][%d]: ", name, i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
}
void main(){
    
    int nr1,nc1,nr2,nc2;
    printf("Enter number of rows of the first matrix: ");
    scanf("%d",&nr1);
    printf("Enter number of columns of the first matrix : ");
    scanf("%d",&nc1);
    printf("Enter number of rows of the second matrix: ");
    scanf("%d",&nr2);
    printf("Enter number of columns of the second matrix : ");
    scanf("%d",&nc2);
    if (nc1!=nr2) printf("Given Matrices cannot be multiplied");
    else if (nc1==nr2){
        int mat1[nr1][nc1],mat2[nr2][nc2], product[nr1][nc2];
        input(nr1,nc1,mat1,'A');
        input(nr2,nc2,mat2,'B');
        
        for (int i=0;i<nr1;i++){
            for (int j=0;j<nc2;j++) {
                product[i][j]=0;
                for (int k=0;k<nc1;k++)
                    product[i][j] += mat1[i][k] * mat2[k][j];
            }
        } 
        printf("\nThe product of the given two matrices is :");
        for (int r=0;r<nr1;r++){printf("\n");
            for (int c=0;c<nc2;c++)
                printf("%i\t",product[r][c]);
        }
    }
}