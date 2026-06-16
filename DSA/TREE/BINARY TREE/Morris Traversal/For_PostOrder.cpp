#include <iostream>
#include <vector>
#include <algorithm>
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

// Helper to reverse the path and collect nodes
void reversePath(Node* from, Node* to, vector<int>& res) {
    vector<int> temp;
    Node* cur = from;
    while (cur != to) {
        temp.push_back(cur->data);
        cur = cur->right;
    }
    temp.push_back(to->data);

    // Reverse to simulate postorder
    reverse(temp.begin(), temp.end());
    res.insert(res.end(), temp.begin(), temp.end());
}

void morrisPostorderTraversal(Node* root) {
    vector<int> result;

    Node* dummy = new Node(0);
    dummy->left = root;
    Node* current = dummy;

    while (current != nullptr) {
        if (current->left == nullptr) {
            current = current->right;
        } else {
            Node* predecessor = current->left;

            // Find predecessor (rightmost node in left subtree)
            while (predecessor->right != nullptr && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == nullptr) {
                // Make a thread
                predecessor->right = current;
                current = current->left;
            } else {
                // Reverse the nodes from current->left to predecessor
                reversePath(current->left, predecessor, result);

                // Remove the thread
                predecessor->right = nullptr;
                current = current->right;
            }
        }
    }

    // Output result
    cout << "Morris Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
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

    morrisPostorderTraversal(root);

    return 0;
}






