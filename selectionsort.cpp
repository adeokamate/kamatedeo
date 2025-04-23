#include <iostream>
#include <vector>
using namespace std;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

              int n;
            cout<< "How many elements do you want to sort in the selection sort? ";
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
            for(int i = 0;i<n-1;i++){
                    int minIndex = i;
                    for(int j = i+1;j<n;j++){
                        if(numbers[j]<numbers[minIndex]){
                            minIndex = j;
                        }
                    }
                    swap(numbers[i],numbers[minIndex]);

            }
            cout<< "\nThis is sorted ascendingly: ";
            for(int num:numbers){
                cout << num << " ";
            }
            return 0;
}
