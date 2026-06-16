// Flatten binary tree to linked list


/*

Given the root of a binary tree, flatten the tree into a "Linked list":

The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Input: 
          1
        /   \
       2     5
      / \     \
     3   4     6
Output : 1 2 3 4 5 6 

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




void flatten(node *root)
{
    node* curr = root ;
    
    while(curr != NULL)
    {
        if (curr -> left)
        {
            node* pred = curr -> left ;
            while(pred -> right)
            {
                pred = pred -> right ;
            }
            
            pred -> right = curr -> right ;
            curr -> right = curr -> left ;
            curr -> left = NULL ;
        }
        
        curr = curr -> right ;
    }
    
    // // Left Part NULL
    // curr = root ;
    // while(curr != NULL)
    // {
    //     curr -> left = NULL ;
    //     curr = curr -> right ;
    // }

}




int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


    // Creating a tree using Level Order
    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    flatten(root) ;
    
    cout << "\nPreOrder Linked List : " << endl;
    node* temp = root ;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> right ;
    }
    cout << endl;

    return 0;
}





