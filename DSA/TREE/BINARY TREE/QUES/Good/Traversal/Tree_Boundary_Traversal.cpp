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
    private:
    void traverseLeft(node* root , vector<int> &ans)
    {
        // Base Case
        if ( (root == NULL) || (root -> left == NULL && root -> right == NULL))
             return ;
        
        ans.push_back(root -> data);
        if (root -> left)
            traverseLeft(root -> left , ans) ;
        else
            traverseLeft(root -> right , ans) ;
    }
    
    
    void traverseLeaf(node* root , vector<int> &ans)
    {
        // Base Case
        if (root == NULL)
            return ;
        
        if (root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(root -> data) ;
            return ;
        }
        
        traverseLeaf(root -> left , ans) ;
        traverseLeaf(root -> right , ans) ;
    }
    
    
    void traverseRight(node* root , vector<int> &ans)
    {
        // Base Case
        if ( (root == NULL) || (root -> left == NULL && root -> right == NULL) )
              return ;
        
        if (root -> right)
            traverseRight(root -> right ,ans);
        else
            traverseRight(root -> left , ans);
        
        // wapas aagye
        ans.push_back(root -> data) ;
    }

    public:

      vector<int> boundaryTraversal(node *root) {
          vector<int> ans ;
          if (root == NULL)
               return ans ;
          
          ans.push_back(root -> data) ;   
          
          // Left part print/store
          traverseLeft(root -> left , ans) ;
          
          
          // Traverse Leaf Nodes
          // left subtree
          traverseLeaf(root -> left , ans) ;
          // right subtree
          traverseLeaf(root -> right , ans) ;
          
          // Traverse right part
          traverseRight(root -> right , ans) ;
          
          return ans ;
      }
  };



void print_vector(vector<int> v)
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


    cout << "\nTree Boundary Traversal Vector : ";
    Solution sol ;
    vector<int> boudary_v = sol.boundaryTraversal(root) ;
    print_vector(boudary_v) ;

    
    return 0;
}







