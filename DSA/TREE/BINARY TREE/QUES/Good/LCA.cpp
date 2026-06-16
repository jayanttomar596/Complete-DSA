// LCA in Binary Tree (Least Common Anestor)


/*

Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the lowest common ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them are present.

LCA: It is the first common ancestor of both the nodes n1 and n2 from bottom of tree.

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



class Solution {
    public:
      // Function to return the lowest common ancestor in a Binary Tree.
      node* lca(node* root, int n1, int n2) {
          // Base Case
          if (root == NULL)
              return NULL ;
          

          if (root -> data == n1 || root -> data == n2)
              return root ;
          

          node* leftAns = lca(root -> left , n1 , n2);
          node* rightAns = lca(root -> right , n1 , n2);
          

          if (leftAns != NULL && rightAns != NULL)
              return root ;
          else if (leftAns != NULL && rightAns == NULL) 
              return leftAns ;
          else if (leftAns == NULL && rightAns != NULL)
              return rightAns ;
          else
              return NULL ;
      }
};





int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;


    Solution sol ;
    int n1 , n2 ;
    cout << "Enter the Value of n1 = ";
    cin >> n1 ;
    cout << "Enter the Value of n2 = ";
    cin >> n2 ;

    cout << "\nLowest Common Ancestor of " << n1 << " and " << n2 << " = " << sol.lca(root,n1,n2)->data <<endl;
    
    return 0;
}











