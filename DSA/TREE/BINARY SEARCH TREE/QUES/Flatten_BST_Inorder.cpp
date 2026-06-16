// Flatten BST to sorted list


/*

You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect




Input:
          5
        /    \
       3      7
      /  \    /   \
     2   4  6     8
Output: 2 3 4 5 6 7 8
Explanation: 
After flattening, the tree looks
like this
    2
     \
      3
       \
        4
         \
          5
           \
            6
             \
              7
               \
                8
Here, left of each node points
to NULL and right contains the
next node.


*/





#include <iostream>
#include <queue>
using namespace std;


class Node 
{

public :
    int data ;
    Node* left ;
    Node* right ;
    
    Node(int d)
    {
        this -> data = d ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};




// T.C. -> O(H)
// S.C. -> O(H)
Node* insertIntoBST(Node* &root , int d)
{
    // Base Case
    if (root == NULL)
    {
        root = new Node(d) ;
        return root ;
    } 

    if (d > root -> data)
    {
        // Right part me insert karna hai
        root -> right = insertIntoBST(root -> right , d) ;
    }
    else
    {
        // Left part me insert karna hai
        root -> left = insertIntoBST(root -> left , d);
    }

    return root ;
}



void takeInput(Node* &root)
{

    int data ;
    cin >> data ;

    while(data != -1)
    {
        insertIntoBST(root , data) ;
        cin >> data ;
    }
}




void levelOrderTraversal(Node* root)
{
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty())
    {
        Node* temp = q.front() ;
        q.pop() ;

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl; 
            if (!q.empty())
            {
                // queue still has some child nodes
                q.push(NULL) ;
            }
        }
        else
        {
            cout << temp -> data << " ";

            if (temp -> left)
            {
                q.push(temp -> left) ;
            }

            if (temp -> right)
            {
                q.push(temp -> right) ;
            }
        }
    }
}



void inorder(Node* root)
{
    // base case
    if (root == NULL)
        return ;
    
    inorder(root -> left );
    cout << root -> data << " ";
    inorder(root -> right);
}



class Solution
{
private:
    void inorder(Node *root , vector<int> &in)
    {
        if (root == NULL)
            return ;
        
        inorder(root -> left , in) ;
        in.push_back(root -> data) ;
        inorder(root -> right , in) ;
    }
    


public :

    Node* flattenBST(Node* root)
    {
        vector<int> inorderVal ;
        
        // Store Inorder -> Sorted values
        inorder(root , inorderVal) ;
        int n = inorderVal.size() ;
        
        Node* newRoot = new Node(inorderVal[0]) ;
        
        Node* curr = newRoot ;
        
        
        // 2nd Step
        for (int i = 1 ; i < n ; i++)
        {
            Node* temp = new Node(inorderVal[i]) ;
            
            curr -> left = NULL ;
            curr -> right = temp ;
            curr = temp ;
        }
        
        
        // 3rd Step
        curr -> left = NULL ;
        curr -> right = NULL ;
        
        return newRoot ;
    }
};



class Solution2
{
public:
    void flatten(Node* root)
    {
        if (!root)
            return;

        Node* curr = root;
        
        while (curr)
        {
            if (curr->left)
            {
                // Find the rightmost node in the left subtree
                Node* pred = curr->left;
                while (pred->right)
                    pred = pred->right;

                // Attach the original right subtree to the rightmost node
                pred->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = NULL;  // Set left to NULL
            }

            // Move to the next node
            curr = curr->right;
        }
    }
};





int main() {

    Node* root = NULL ;

    cout << "\nEnter data to create BST : " << endl ;
    takeInput(root) ;
    // 10 8 21 7 27 5 4 3 -1

    cout << "\nLevel Order Traversal : " << endl ;
    levelOrderTraversal(root) ;
    cout << endl;


    Solution sol;
    root = sol.flattenBST(root) ;
    Node* temp = root ;

    cout << "\nFlatten BST :" << endl;
    while(temp->right != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> right ;
    }
    cout << endl;


    return 0;
}




