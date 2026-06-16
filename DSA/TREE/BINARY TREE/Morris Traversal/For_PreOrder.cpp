#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void morrisPreorderTraversal(Node* root) {
    Node* current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        } else {
            Node* predecessor = current->left;
            // Find rightmost node in the left subtree (predecessor)
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                // Visit before making the thread
                cout << current->data << " ";
                predecessor->right = current;
                current = current->left;
            } else {
                // Thread already exists, remove it
                predecessor->right = nullptr;
                current = current->right;
            }
        }
    }
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Morris Preorder Traversal: ";
    morrisPreorderTraversal(root);
    cout << endl;

    return 0;
}
