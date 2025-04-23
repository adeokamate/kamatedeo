
#include <iostream>
 #define SIZE 5 //Define the maximum size of the queue
using namespace std;

class Queue {
private:
     int items[SIZE] , front , rear;
public:
    Queue() {
        front = -1;
        rear = -1;
}
// check if the queue is full
bool isFull() {
    return (rear + 1) %SIZE == front;
}
// check if the queue is empty
bool isEmpty() {
    return front ==-1;

}
//insert an element into the queue
void enqueue(int element) {
    if (isFull()) {
        cout << "queue is full! cannot enqueue." << endl;
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1)% SIZE;
    items[rear] = element;
    cout <<"inserted" <<element << "into queue."<< endl;
}
//Remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! cannot dequeue. " << endl;
        return;
    }
    cout << "Removed "<< items[front] << " from queue." << endl;
    if (front == rear) {
        front = rear = -1; //Reset que when last element is removed
    }else {
        front = (front + 1)% SIZE;
    }
}
//Get the front element of the queue
void peek() {
    if (isEmpty()) {
        cout <<"Queue is empty!" << endl;
    } else {
        cout << "Front element: " << items[front] << endl;
    }
}
//Display all elements of the queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << items[i] << " ";
        if (i == rear) break;
        i = (i = i + 1)% SIZE;


    }
    cout << endl;
}
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations:\n";
        cout << "1.Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout <<"Exiting program." <<endl;
                break;
            default:
                 cout <<"Invalid choice! please try again." << endl;


        }
    } while (choice != 5);

    return 0;
}