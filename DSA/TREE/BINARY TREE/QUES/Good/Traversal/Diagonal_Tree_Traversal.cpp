// Diagonal Tree Traversal


/*

Given a Binary Tree, return the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, return a single list containing all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtrees then left subtree diagonal element should be taken first and then right subtree. 

*/



// Sum of nodes on the longest path


/*

Given a binary tree root, you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

*/

// T.C. -> O(N)
// S.C. -> O(H)



// Tree Boundary Traversal

/*

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

*/


// Time Complexity -> O(N)
// Space Complexity (Auxiliary) -> O(H)
// Space Complexity (Including Output)	-> O(N)




#include <iostream>
#include <queue>
#include <vector>
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
      vector<int> diagonal(node *root) {
      vector<int> result;
      if (root == NULL) return result;
  
      queue<node*> q;
      q.push(root);
  
      while (!q.empty()) {
          node* temp = q.front();
          q.pop();
  
          // Traverse all nodes of current diagonal
          while (temp != NULL) {
              result.push_back(temp->data);
  
              // If there is a left child, it will be on the next diagonal
              if (temp->left) {
                  q.push(temp->left);
              }
  
              // Move to the right child
              temp = temp->right;
          }
      }
  
      return result;
  }
  
};



void Print_Vector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}




int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;


    Solution sol ;
    vector<int> result = sol.diagonal(root) ;
    cout << "\nDiagonal Tree Traversal : " << endl;
    Print_Vector(result);
    
    return 0;
}











