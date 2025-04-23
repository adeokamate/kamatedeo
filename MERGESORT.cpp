
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &numbers,int left, int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1),rightArr(n2);
    for(int i = 0;i<n1;i++){
        leftArr[i] = numbers[left+i];

    }
    for(int j = 0; j<n2; j++){
        rightArr[j] = numbers[mid+1+j];
    }
    int i = 0,j = 0,k = left;
    while(i<n1 && j<n2){
        if(leftArr[i] <= rightArr[j]){
            numbers[k]=leftArr[i];
            i++;

        }
        else{
            numbers[k]=rightArr[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        numbers[k] = leftArr[i];
        i++;
        j++;
    }
    while(j<n2){
        numbers[k]= rightArr[j];
        j++;
        k++;
    }
}


void mergesort(vector <int>&numbers,int left,int right){
    if(left<right){
        int mid = left + (right-left)/2;
        mergesort(numbers,left,mid);
        mergesort(numbers,mid+1,right);
        merge(numbers,left,mid,right);
    }

    }

int main(){
    int n;
            cout<< "How many elements do you want to sort using merge sort? ";
            cin>> n;
            vector<int>numbers(n);

            for(int i=0;i<n;i++){

                cout<< "Enter element "<< (i+1)<< ": ";
                cin>> numbers[i];

            }
            cout<< "\nYou have entered: ";
            for(int num:numbers){
                cout<<num<< " ";
            }
            mergesort(numbers,0,n-1);
            cout<< "\n Sorted numbers: ";
            for(int num:numbers){
                cout<<num<< " ";
            }
    return 0;
}

