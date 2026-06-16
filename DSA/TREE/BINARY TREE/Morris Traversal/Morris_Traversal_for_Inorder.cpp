// Morris traversal for Inorder


/*

Given a Binary Tree, the task is to print its Inorder Traversal, without using recursion or stack.


Step by step implementation:

Initialize current as root and repeat the following steps, as long as the current node is not NULL.
If the current node does not have a left child, print its data and move to the right, i.e., current = current->right.
Else, find inorder predecessor of current (rightmost node in current left subtree or node whose right child is equal to current).
If we found that right child of inorder predecessor is equal to current then,
update its the right child as NULL and print current’s data.
Go to the right, i.e. current = current->right.
Else
Make current as the right child of its inorder predecessor; and
Go to current’s left child, i.e., current = current->left.
Morris-traversal-for-Inorder-1.webp


*/



#include <iostream>
#include <queue>
#include <stack>
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




// T.C. -> O(N)
// S.C. -> O(1)

// Function to perform Morris Inorder Traversal
void morrisInorderTraversal(node* root)
{
    node* current = root ;

    while(current != NULL)
    {
        if (current -> left == NULL)
        {
            // No left child , print the current node and move to right
            cout << current -> data << " ";
            current = current -> right ;
        }
        else
        {
            // Find the inorder predecessor of current
            node* predecessor = current -> left ;

            // Find the rightmost node in the left subtree or the node that already points back to current 
            while(predecessor -> right != NULL && predecessor -> right != current)
            {
                predecessor = predecessor -> right ;
            }

            // If the right child of predecessor is NULL , establish a link back to current 
            if (predecessor -> right == NULL)
            {
                predecessor -> right = current ;
                current = current -> left ;
            }
            // If the right child already points to current , its time to remove the link and move to right subtree
            else
            {
                predecessor -> right = NULL ;
                cout << current -> data << " ";
                current = current -> right ;
            }
        }
    }
}






int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1


    cout << "\nLevel Order Traversal : "<<endl; 
    levelOrderTraversal(root) ;



    cout << "\nMorris Inorder Traversal: ";
    morrisInorderTraversal(root);
    cout << endl;
    // Output : 4 7 2 5 1 3 6 


    return 0;
}



