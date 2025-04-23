#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int data;
    node *next;
    node(int data) : data(data), next(nullptr) {}
};

class linkedlist {
private:
    node *head;
    int length;
    static const int MAX_SIZE = 5;

public:
    linkedlist() : head(nullptr), length(0) {}

    bool is_empty() {
        return head == nullptr;
    }

    void add(int data, int position = 0) {
        if (length >= MAX_SIZE) {
            cout << "List has reached its maximum size of " << MAX_SIZE << endl;
            return;
        }

        node *new_node = new node(data);

        // Ensure position is valid and not beyond length
        if (position > length) {
            position = length;  // Add at the end of the list
        }

        if (position == 0 || head == nullptr) {
            // Add at the beginning (position 0)
            new_node->next = head;
            head = new_node;
        } else {
            // Add at a specific position
            node *current = head;
            node *prev = nullptr;
            int index = 0;
            while (current && index < position) {
                prev = current;
                current = current->next;
                index++;
            }
            if (prev) {
                prev->next = new_node;
                new_node->next = current;
            }
        }
        length++;
    }

    void remove(int position) {
        if (is_empty()) {
            cout << "List is empty" << endl;
            return;
        }

        node *current = head;
        node *prev = nullptr;
        int index = 0;
        while (current && index < position) {
            prev = current;
            current = current->next;
            index++;
        }

        if (current == nullptr) {
            cout << "Position out of range" << endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        length--;
    }

    int pop() {
        if (is_empty()) {
            cout << "List is empty" << endl;
            return -1;
        }
        if (head->next == nullptr) {
            int value = head->data;
            delete head;
            head = nullptr;
            length--;
            return value;
        }
        node *current = head;
        node *prev = nullptr;
        while (current->next) {
            prev = current;
            current = current->next;
        }

        prev->next = nullptr;
        int value = current->data;
        delete current;
        length--;
        return value;
    }

    int index(int data) {
        node *current = head;
        int index = 0;
        while (current) {
            if (current->data == data)
                return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    int size() {
        return length;
    }

    void append(int data) {
        add(data, length);  // Always append at the end
    }

    void display() {
        node *current = head;
        while (current) {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    linkedlist list;

    int a = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Enter a number: ";
        cin >> a;
        list.add(a, i); // Add at position i
    }

    list.display(); // Display the list
    // Choose operation
    string operation;
    cout << "Choose operation (\n 1.add \n 2.remove\n 3.pop\n 4.index\n 5.size\n 6.append\n 7.display): ";
    cin >> operation;
    if (operation == "1") {
        int data, position;
        cout << "Enter data and position: ";
        cin >> data >> position;
        list.add(data, position);
    } else if (operation == "2") {
        int position;
        cout << "Enter position to remove: ";
        cin >> position;
        list.remove(position);
    } else if (operation == "3") {
        cout << "Popped value: " << list.pop() << endl;
    } else if (operation == "4") {
        int data;
        cout << "Enter data to find index: ";
        cin >> data;
        cout << "Index of " << data << ": " << list.index(data) << endl;
    } else if (operation == "5") {
        cout << "Size of the list: " << list.size() << endl;
    } else if (operation == "6") {
        int data;
        cout << "Enter data to append: ";
        cin >> data;
        list.append(data);
    } else if (operation == "7") {
        list.display();
    }


    // list.append(1); // Add 1
    // list.append(2); // Add 2
    // list.add(5, 0); // Add 5 at position 0
    // list.append(3); // Add 3
    // list.append(4); // Add 4
    // list.append(5); // Attempt to add 5 again (fails because of MAX_SIZE)

    return 0;
}
