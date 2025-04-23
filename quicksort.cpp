#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


int main(){
  int n;

    // Ask the user for the number of elements
            cout << "Enter the number of elements: ";
            cin >> n;

            int arr[n];

    // Ask the user for the elements
            cout << "Enter the elements: ";
            for (int i = 0; i < n; i++) {
                cin >> arr[i];
    }

    // Print the original array
            cout << "Original array: ";
            printArray(arr, n);

    // Sort the array using QuickSort
            quickSort(arr, 0, n - 1);

    // Print the sorted array
            cout << "Sorted array: ";
            printArray(arr, n);

            return 0;
}
