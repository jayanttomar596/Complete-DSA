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



// Approach - 1
// Function to check if two trees are identical.
bool isIdentical(node *r1, node *r2) {
    // Base Case
    if(r1 == NULL && r2 == NULL)
    {
        return true ;
    }
    
    if (r1 == NULL && r2 != NULL)
    {
        return false ;
    }
    
    if (r1 != NULL && r2 == NULL)
    {
        return false ;
    }
    
    bool left = isIdentical(r1 -> left , r2 -> left) ;
    bool right = isIdentical(r1 -> right , r2 -> right) ;
    
    bool value = r1 -> data == r2 -> data ;
    
    if (left && right && value)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}




// Approach - 2
// Using Level Order Traversal
bool isIdentical2(node* r1 , node* r2)
{
    if(r1 == NULL && r2 == NULL)
        return true ;
    
    if(r1 == NULL || r2 == NULL)
        return false ;
    
    // Using two queues for level order traversal
    queue<node*> q1 , q2 ;
    q1.push(r1) ;
    q2.push(r2) ;

    while(!q1.empty() && !q2.empty())
    {
        node* node1 = q1.front() ;
        node* node2 = q2.front() ;
        q1.pop() ;
        q2.pop() ;

        // check if the current nodes are identical
        if (node1->data != node2->data)
            return false ;
        
        // Check the left children
        if (node1->left  && node2->left){
            q1.push(node1->left) ;
            q2.push(node2->left) ;
        }
        else if (node1->left || node2->left)
        {
            return false ;
        }



        // Check the right children
        if (node1->right && node2->right)
        {
            q1.push(node1->right);
            q2.push(node2->right);
        } 
        else if (node1->right || node2->right)
        {
            return false ;
        }
    }

    // If both queues are empty , the trees are identical
    return q1.empty() && q2.empty() ;
}




int main() {

    node* root1 = NULL ;
    node* root2 = NULL ;

    // Creating a Tree using Recursion
    root1 = buildTree(root1) ;
    root2 = buildTree(root2) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nCheck for Identical : ";
    if(isIdentical(root1,root2))
    {
        cout << "Yes , Both are Identical" << endl;
    }
    else
    {
        cout << "No , Both are Not Identical" << endl;
    }



    cout << "\nCheck for Identical : ";
    if(isIdentical2(root1,root2))
    {
        cout << "Yes , Both are Identical" << endl;
    }
    else
    {
        cout << "No , Both are Not Identical" << endl;
    }

    return 0;
}



