#include <stdio.h>

#include <string.h>
#include <stdbool.h>


void linear_search(int arr[], int n, int key,int *comparisons){
    bool found = false;
    for(int i=0;i<n;i++){
            (*comparisons)++;
        if(arr[i] == key){
            found = true;
            printf("key found at index %d", i);
            break;
        }
    }
    if(!found){
        printf(" search not successful key not found");
    }
}
int main(){

    int comparisons = 0;
    printf("THE LINEAR SEARCH ALGORITHM");
    int n, key;
    // get number of sample elements
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];  // An array with size n

    //create a sample array

    printf("\n please create a sample array of %d elements by simply inputting them with space in between  e.9 20 30 \n", n);
    for(int i = 0;i < n; i++){
    scanf("\n %d", &arr[i]); //input array elements one by one

    }
    // display all the values in a single line
    printf("\n These are your elements in the array: ");
    for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
    }
    // search for a key value
    printf("\n please enter the value of the key you are searching: ");
    scanf("%d", &key);

linear_search(arr, n,key,&comparisons);
printf("\nTotal comparisons (time complexity) is: %d",comparisons);
    return 0;
}
