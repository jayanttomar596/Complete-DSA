// COUNT LEAF NODES

/*Problem statement
You are given a Binary tree. You have to count and return the number of leaf nodes present in it.

A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child

A node is a leaf node if both left and right child nodes of it are NULL.

*/




#include <iostream>
#include <queue>
using namespace std;


class node
{
public :
    int data ;
    node* left ;
    node* right ;

    node(int d)
    {
        this -> data = d ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};



node* buildTree(node* root)
{
    cout << "Enter the data : " ;
    int data ;
    cin >> data ;
    root = new node(data) ;

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



void levelOrderTraversal(node* root)
{
    queue<node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty())
    {
        node* temp = q.front() ;
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



int noOfLeafNodes(node *root) {

    // Base case: If the root is null, return 0
    if (root == NULL) {
        return 0;
    }

    // If the node is a leaf node, return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Recursively count leaf nodes in left and right subtrees
    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}



void inorder(node* root , int &count)
{
    // Base Case
    if (root ==NULL)
    {
        return ; 
    }

    inorder(root -> left , count) ;

    // Leaf Node
    if (root -> left == NULL && root -> right == NULL)
    {
        count++ ;
    }

    inorder(root -> right , count) ;
}


int NoOfLeafNodes(node* root)
{
    int cnt = 0 ;
    inorder(root , cnt) ;
    return cnt ;
}




int main() {


    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nBinary Tree : "<<endl;
    levelOrderTraversal(root) ;


    cout << "\nNo of Leaf Nodes = "<<noOfLeafNodes(root) << endl;

    cout << "\nNo of Leaf Nodes = "<<NoOfLeafNodes(root) << endl;
    
    return 0;
}




