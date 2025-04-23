#include <iostream>
#include <vector>
using namespace std;
void insertionsort(vector <int> & numbers){
    int n = numbers.size();
    for (int i = 1; i<n; i++){
        int key = numbers[i];
        int j = i-1;
        while (j >= 0 && numbers[j]>key){
            numbers[j+1]=numbers[j];
            j--;
        }
        numbers[j+1]=key;}
}
int main(){
int n;
            cout<< "How many elements do you want to sort using insertion sort? ";
            cin>> n;
            vector<int>numbers(n);

            for(int i=0;i<n;i++){

                cout<< "Enter element "<< (i+1)<< ": ";
                cin>> numbers[i];

            }
            cout<< "\nYou have entered: ";
            for(int num:numbers){
                cout<<num<< " ";}
            insertionsort(numbers);
            cout<< "\nThis is what is sorted ascendingly: ";
            for (int num : numbers){
                cout<< num << " ";
            }
return 0;
}
