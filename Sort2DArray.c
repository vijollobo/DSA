#include <stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int items[5][2]={{1,300},{2,500},{3,100},{4,200},{5,400}};
    
    printf("Initial table :\nItem : ");
    for (int _=0;_<5;_++) printf("%i    ",items[_][0]);
    printf("\nPrice :"); for (int _=0;_<5;_++) printf("%i  ",items[_][1]);
    
    for (int i = 0; i <4; i++) {
        int swapped = 1;
        for (int j = 0; j < 4-i; j++) {
            if (items[j][1] < items[j + 1][1]) {
                swap(&items[j][0], &items[j + 1][0]);
                swap(&items[j][1], &items[j + 1][1]);
                swapped = 0;
            }
        }
        if(swapped) break;
    }
    
    printf("\n\nSorted table :\nItem : ");
    for (int _=0;_<5;_++) printf("%i    ",items[_][0]);
    printf("\nPrice :"); for (int _=0;_<5;_++) printf("%i  ",items[_][1]);

}