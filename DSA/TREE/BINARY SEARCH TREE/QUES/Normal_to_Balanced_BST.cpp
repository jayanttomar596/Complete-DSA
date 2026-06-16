// Normal BST to Balanced BST


/*

Given a root of a Binary Search Tree, modify and return the given BST such that it is balanced and has minimum possible height. If there is more than one answer, return any of them.

Note: The height of balanced BST returned by you will be compared with the expected height of the balanced tree.

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





// T.C. -> O(N)
// S.C. -> O(N)

class Solution {
    private :
      void inorder(Node* root , vector<int> &in)
      {
          if (root == NULL)
              return ;
          
          inorder(root -> left , in) ;
          in.push_back(root -> data) ;
          inorder(root -> right , in) ;
      }
      
      Node* inorderToBST(int s , int e , vector<int> &in)
      {
          // Base Case
          if (s > e)
              return NULL ;
          
          int mid = (s+e)/2 ;
          Node* root = new Node(in[mid]) ;
          root -> left = inorderToBST(s , mid-1 , in) ;
          root -> right = inorderToBST(mid+1 , e , in) ;
          
          return root ;
      }
  
    public:
      Node* balanceBST(Node* root) {
          vector<int> inorderVal ;
          // Store Inorder -> Sorted Values
          inorder(root , inorderVal) ;
          
          return inorderToBST(0 , inorderVal.size() - 1 , inorderVal);
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


    Solution sol ;
    root = sol.balanceBST(root) ;

    cout << "\nLevel Order Traversal : " << endl ;
    levelOrderTraversal(root) ;
    cout << endl;


    return 0;
}






