#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert a node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// In-order traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Pre-order traversal
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Find a node by value
Node* find(Node* root, int value) {
    if (root == nullptr || root->data == value)
        return root;

    if (value < root->data)
        return find(root->left, value);
    else
        return find(root->right, value);
}

// Display child nodes of a given node
void showChildren(Node* root, int value) {
    Node* node = find(root, value);
    if (node == nullptr) {
        cout << "Node not found.\n";
        return;
    }

    if (node->left)
        cout << "Left child of " << value << " is " << node->left->data << endl;
    else
        cout << "Left child of " << value << " does not exist.\n";

    if (node->right)
        cout << "Right child of " << value << " is " << node->right->data << endl;
    else
        cout << "Right child of " << value << " does not exist.\n";
}

int main() {
    Node* root = nullptr;
    int choice, value;

    cout << "Binary Search Tree Simulation in C++\n";

    // Input loop
    while (true) {
        cout << "\n1. Insert node\n2. Traverse tree\n3. Show root\n4. Show children of a node\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "Choose traversal: \n1. In-order\n2. Pre-order\n3. Post-order\nEnter choice: ";
            cin >> choice;
            cout << "Traversal result: ";
            if (choice == 1)
                inorder(root);
            else if (choice == 2)
                preorder(root);
            else if (choice == 3)
                postorder(root);
            else
                cout << "Invalid traversal choice.";
            cout << endl;
            break;

        case 3:
            if (root)
                cout << "Root of the tree is: " << root->data << endl;
            else
                cout << "Tree is empty.\n";
            break;

        case 4:
            cout << "Enter the node value to find its children: ";
            cin >> value;
            showChildren(root, value);
            break;

        case 5:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
