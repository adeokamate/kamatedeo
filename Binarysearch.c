# include <stdio.h>
# include <string.h>



int binary_search(int arr[], int low, int high, int key){


    if(low <= high){
        int mid = low + (high - low)/2;
        if(key==arr[mid]){
        printf("The value %d found at index %d", key, mid);
        return key;
        }
        if (key < arr[mid]){
            return binary_search(arr, low, mid-1, key);
        }
        return binary_search(arr,mid+1,high,key);
        }


        printf("Search unsuccessful, no results found\n");
        return -1;
    }


    int main(){
printf("\t  THE BINARY SEARCH ALGORITHM\n");
       int low,high,mid,key, n=0;

    // number of items to search from
    printf("\n Please enter the number of items of the list to search from: ");
    scanf("%d",&n);

    int arr[n]; // declare an array of maximum size n
    // sample array section
    printf("Please enter a sample of sorted array e.g(24 89 67) \n");
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);

    }

    //display an array


    printf("\n Here is your array: ");
    for(int i=0;i<n;i++){
    printf("%d ", arr[i]);
}



// Ask for the key

printf("\n Please enter the value of the key you are searching for: ");
scanf("%d",&key);

binary_search(arr,0,n-1,key);

    }






