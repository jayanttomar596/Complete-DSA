// Construct Binary Search Tree from Preorder Traversal



/*

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

*/




#include <iostream>
#include <queue>
#include <vector>
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



class Solution {
    private:
        Node* solve(vector<int> &preorder, int mini, int maxi, int &i, int size) {
            if (i >= size)  // Ensure index is within bounds
                return NULL;
    
            if (preorder[i] < mini || preorder[i] > maxi)
                return NULL;
    
            Node* root = new Node(preorder[i++]);  // Now this works correctly
            root->left = solve(preorder, mini, root->data, i, size);
            root->right = solve(preorder, root->data, maxi, i, size);
    
            return root;
        }
    
    public:
        Node* bstFromPreorder(vector<int>& preorder) {
            int mini = INT_MIN;
            int maxi = INT_MAX;
            int i = 0;
            int size = preorder.size() ;
            
            return solve(preorder , mini, maxi, i, size);
        }
};





int main() {

    Node* root = NULL ;

    // cout << "\nEnter data to create BST : " << endl ;
    // takeInput(root) ;
    // 10 8 21 7 27 5 4 3 -1

    vector<int> preorder = {8,5,1,7,10,12} ;

    Solution sol ;
    root = sol.bstFromPreorder(preorder) ;

    cout << "\nLevel Order Traversal : " <<endl;
    levelOrderTraversal(root) ;


    return 0 ;
}





