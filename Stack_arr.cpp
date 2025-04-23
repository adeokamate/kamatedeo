#include <iostream>
#define SIZE 5 // Define the maximum size of the stack

using namespace std;
class Stack{
private:
    int items[SIZE], top;
public:
    Stack(){
        top = -1; // Stack is initially empty

    }

    // Check if the stack is full
    bool isFull() {
        return top == SIZE -1;
    }

    bool isEmpty(){
        return top == -1;

    }

    //Push an element onto the stack
    void push(int element){
        if (isFull()){
            cout << "Stack is full! Cannot push." << endl;
            return;
        }
        items[++top] = element;
        cout << "Pushed " << element << " onto the stack successfully."<< endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return;
        }
        cout<< "Popped " << items[top--] << "from the stack." << endl;
    }

    // Peek at the top element of the stack
    void peek(){
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
        }else{
            cout << "Top element: " << items[top] << endl;
        }
    }

    // Display all elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << items[i] << " ";
        }
        cout << endl;
        }
};
int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n Stack Operations:\n";
        cout << "choose any of these operations\n 1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;

        }
    } while (choice != 5);

    return 0;
}







































