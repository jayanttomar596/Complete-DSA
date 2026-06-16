// Largest BST in Binary Tree



/*

You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

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





class info {
    public :
        int maxi ;
        int mini ;
        bool isBST ;
        int size ;
};



// T.C. -> O(N)
// S.C. -> O(H)

class Solution{
    public:
    
    info solve(Node* root , int &ans)
    {
        // Base Case
        if (root == NULL)
        {
            return {INT_MIN , INT_MAX , true , 0} ;
        }
        
        info left = solve(root -> left , ans ) ;
        info right = solve(root -> right , ans) ;
        
        info currNode ;
        
        currNode.size = left.size + right.size + 1 ;
        currNode.maxi = max(root -> data , right.maxi) ;
        currNode.mini = min(root -> data , left.mini) ;
        
        if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
        {
            currNode.isBST = true ;
        }
        else
        {
            currNode.isBST = false ;
        }
        
        // Answer Update
        if (currNode.isBST)
        {
            ans = max(ans , currNode.size) ;
        }
        
        return currNode ;
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	int maxSize = 0 ;
    	info temp = solve(root , maxSize) ;
    	return maxSize ;
    }
};

    




int main() {

    Node* root = NULL ;

    // cout << "\nEnter data to create BST : " << endl ;
    // takeInput(root) ;
    // 10 8 21 7 27 5 4 3 -1


    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;
    cout << endl;


    Solution sol ;
    cout << "\nLargest BST in Binary Tree = " << sol.largestBst(root) << endl;


    return 0;
}








