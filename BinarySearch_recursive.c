#include <stdio.h>
#include <time.h>
// Function to perform binary search using recursion
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) return -1; 
    int mid=low+(high-low)/2; 
    if (arr[mid] == key)return mid;
    if (key<arr[mid]) return binarySearch(arr, low, mid - 1, key);
    return binarySearch(arr, mid + 1, high, key);
}

void main() {
    clock_t start, end;
    double cpu_time_used;
    int n, key;
    printf("Enter the number of elements: "); scanf("%i", &n);
    int arr[n];
    printf("Enter %i elements in ascenfing order: ", n);
    for (int i=0;i<n;i++)scanf("%i", &arr[i]);
    printf("Enter the element to search: ");scanf("%i", &key);
    start=clock();
    int result=binarySearch(arr,0,n-1,key);
    end=clock();
    
    (result!=-1)?printf("Element found at index %i\n", result):printf("Element not found\n");
    
    cpu_time_used=((double)(end-start));
    CLOCKS_PER_SEC;
    printf("\nTotal time Taken: %f",cpu_time_used);
}
