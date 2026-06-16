// Is Binary Tree Heap


/*

You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all Nodes are as far left as possible.
Max-Heap Property: The value of each Node is greater than or equal to the values of its children.

*/






#include <iostream>
#include <queue>
#include <stack>
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



Node* buildTree(Node* root)
{
    cout << "Enter the data : " ;
    int data ;
    cin >> data ;
    root = new Node(data) ;

    if (data == -1)
    {
        return NULL ;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left) ;

    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right) ;

    return root ;
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
                // queue still has some child Nodes
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





// T.C. -> O(N)
// S.C. -> O(H)

class Solution {
    int countNodes(Node* root)
    {
        // Base Case
        if (root == NULL)
            return 0 ;
        
        int ans = 1 + countNodes(root -> left) + countNodes(root -> right) ;
        return ans ;
    }
    
    
    bool isCBT(Node* root , int index , int cnt)
    {
        if (root == NULL)
            return true ;
        
        if (index >= cnt)
            return false ;
        else
        {
            bool left = isCBT(root -> left , 2*index + 1 , cnt) ;
            bool right = isCBT(root -> right , 2*index + 2 , cnt) ;
            
            return (left && right) ;
        }
    }
    
    
    // isMaxOrder jab check kar rahe honge jab patah hoga ki CBT hai
    bool isMaxOrder(Node* root)
    {
        // Leaf Node
        if (root -> left == NULL && root -> right == NULL)
        {
            return true ;
        }
        
        if (root -> right == NULL)
        {
            return (root -> data > root -> left -> data) ;
        }
        else
        {
            bool left = isMaxOrder(root -> left) ;
            bool right = isMaxOrder(root -> right) ;
            
            return (left && right && (root -> data > root -> left -> data 
            && root -> data > root -> right -> data)) ;
        }
    }
    
    
  public:
    bool isHeap(struct Node* tree) {
        
        int index = 0 ;
        int totalCount = countNodes(tree) ;
        if ( isCBT(tree , index , totalCount) && isMaxOrder(tree) )
        {
            return true ;
        }
        else
        {
            return false ;
        }
    }
};





int main() {

    Node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 10 9 5 -1 -1 4 -1 -1 8 2 -1 -1 -1


    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;

    Solution sol ;
    if (sol.isHeap(root))
    {
        cout << "\nThis BST is a HEAP" << endl;
    }
    else
    {
        cout << "\nThis BST is not a HEAP" << endl;
    }


    return 0;
}



