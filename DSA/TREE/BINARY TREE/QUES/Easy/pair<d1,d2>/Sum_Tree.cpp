// Balanced Tree Check

/* Problem Statement
Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.
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



pair<bool,int> isSumTreeFast(node* root)
    {
        // base case
        if(root == NULL)
        {
            pair<bool,int> p = make_pair(true , 0) ;
            return p ;
        }
        
        // Leaf Node
        if (root -> left == NULL && root -> right == NULL)
        {
            pair<bool,int> p = make_pair(true , root -> data) ;
            return p ;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root -> left) ;
        pair<bool,int> rightAns = isSumTreeFast(root -> right) ;
        
        bool isLeftSumTree = leftAns.first ;
        bool isRightSumTree = rightAns.first ;
        
        int leftSum = leftAns.second ;
        int rightSum = rightAns.second ;
        
        bool condn = root -> data == leftSum + rightSum ;
        
        pair<bool , int> ans ;
        
        if(isLeftSumTree && isRightSumTree && condn)
        {
            ans.first = true ;
            ans.second = root -> data + leftSum + rightSum ;
        }
        else
        {
            ans.first = false ;
        }
        
        return ans ;
    }
    
    
    bool isSumTree(node* root) {
        return isSumTreeFast(root).first ;
        
    }





int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 8 3 1 -1 -1 2 -1 -1 1 1 -1 -1 -1

    cout << "\nLevel Order Traversal of Binary Tree : "<< endl;
    levelOrderTraversal(root);



    cout << "\nIs Sum Tree : " ; ;
    if(isSumTree(root))
    {
        cout << "Its a Sum Tree" << endl;
    }
    else
    {
        cout << "Its not a Sum Tree" << endl;
    }
    

    return 0;
}







