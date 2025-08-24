#include <stdio.h>
#include <time.h>
int LinearSearch(int a[], int size, int search){
    if (size==0) return -1;
    if (a[size-1]==search) return size-1;
    return LinearSearch(a,size-1,search);
}
void main(){
    clock_t start, end;
    double cpu_time_used;

    int n, key;
    printf("Enter number of elements : "); scanf("%i",&n);
    int arr[n];
    printf("Enter %i elements :\n",n);
    for(int i=0;i<n;i++) scanf("%i",&arr[i]);
    printf("Enter element to search : ");scanf("%i",&key);
    start=clock();
    int res=LinearSearch(arr,n,key);
    end=clock();
    
    (res!=-1)?printf("%i found at %i",key, res):printf("%i not found",key);
    
    cpu_time_used=((double)(end-start));
    CLOCKS_PER_SEC;
    printf("\nTotal time Taken: %f",cpu_time_used);

}