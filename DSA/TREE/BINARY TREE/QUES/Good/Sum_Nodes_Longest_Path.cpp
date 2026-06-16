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
      void solve(node* root , int sum , int &maxSum , int len , int &maxLen)
      {
          // Base Case
          if (root == NULL)
          {
              if (len > maxLen)
              {
                  maxLen = len ;
                  maxSum = sum ;
              }
              else if (len == maxLen)
              {
                  maxSum = max(sum , maxSum);
              }
              
              return ;
          }   
          
          sum = sum + root -> data ;
          
          solve(root -> left , sum , maxSum , len+1 , maxLen);
          solve(root -> right , sum , maxSum , len+1 , maxLen);
          
      }
      
    public:
      int sumOfLongRootToLeafPath(node *root) {
          int len = 0 ; 
          int maxLen = 0 ;
          
          int sum = 0 ;
          int maxSum = INT_MIN ;
          
          solve(root , sum , maxSum , len , maxLen) ;
          
          return maxSum ;
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
    cout << "\nSum of Nodes on the Longest Path = " << sol.sumOfLongRootToLeafPath(root) <<endl;
    
    return 0;
}










