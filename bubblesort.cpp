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
            cout<< "How many elements do you want sort using bubble sort? ";
            cin>> n;
            vector<int>numbers(n);

            for(int i=0;i<n;i++){

                cout<< "Enter element "<< (i+1)<< ": ";
                cin>> numbers[i];

            }
            cout<< "\nYou have entered: ";
            for(int num:numbers){
                cout<<num<< " ";}
            for (int i = 0; i<n-1;i++){
                for (int j = 0;j<n-i-1;j++){
                    if(numbers[j]>numbers[j+1]){
                        swap(numbers[j],numbers[j+1]);
                    }
                }
            }

            cout<<"\nSorted numbers in ascending order: ";
            for(int num:numbers){
                cout<<num<< " ";
            }
            return 0;
}
