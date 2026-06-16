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



class Solution {
    private :
        bool isBST(Node *root , long min , long max) // Use long to avoid overflow
        {
            if (root == NULL)
                return true ;
    
            if (root -> data > min && root -> data < max)
            {
                bool left = isBST(root -> left , min , root -> data) ;
                bool right = isBST(root -> right , root -> data , max) ;
                return left && right ;
            }  
            else
            {
                return false ;
            }  
        }
    
    public:
        bool isValidBST(Node* root) {
            return isBST(root , LONG_MIN , LONG_MAX) ; // Use LONG_MIN / MAX for safety
        }
    };
    




int main() {

    Node* root = NULL ;

    cout << "\nEnter data to create BST : " << endl ;
    takeInput(root) ;
    // 10 8 21 7 27 5 4 3 -1




    // Creating a Tree using Recursion
    // root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


    Solution sol ;
    if (sol.isValidBST(root))
    {
        cout << "\nIt's a Binary Search Tree" << endl;
    }
    else
    {
        cout << "\nIt's not a Binary Seach Tree" << endl << endl;
    }


    return 0;
}




