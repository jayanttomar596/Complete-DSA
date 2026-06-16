// Lowest Common Ancestor in a BST



/*

Given a Binary Search Tree (with all values unique) and two nodes n1 and n2 (n1 != n2). You may assume that both nodes exist in the tree. Find the Lowest Common Ancestor (LCA) of the given two nodes in the BST.

LCA between two nodes n1 and n2 is defined as the lowest node that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).

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

    


class Solution_1 {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          // Base Case
          if (root == NULL)
              return NULL ;
          
          if (root -> data < n1 -> data && root -> data < n2 -> data)
          {
              return LCA(root -> right , n1 , n2) ;
          }
          
          if (root -> data > n1 -> data && root -> data > n2 -> data)
          {
              return LCA(root -> left , n1 , n2) ;
          }
          
          return root ;
      }
};



class Solution_2 {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          while(root != NULL)
          {
              if (root -> data < n1 -> data && root -> data < n2 -> data)
              {
                  root = root -> right ;
              }
              else if (root -> data > n1 -> data && root -> data > n2 -> data)
              {
                  root = root -> left ;
              }
              else
              {
                  return root ;
              }
          }
      }
};





int main() {

    Node* root = NULL ;

    cout << "\nEnter data to create BST : " << endl ;
    takeInput(root) ;
    // 10 8 21 7 27 5 4 3 -1
    
    Solution_1 sol_1 ;

    cout << "\nLCA = " << (sol_1.LCA(root , root->left->left , root -> right)) -> data << endl << endl;


    Solution_2 sol_2 ;

    cout << "\nLCA = " << (sol_2.LCA(root , root->left->left , root -> right)) -> data << endl << endl;


    return 0;
}





