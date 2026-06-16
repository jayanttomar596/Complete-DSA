// Maximum sum of Non-adjacent nodes

/*

Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen nodes is maximum under a constraint that no two chosen nodes in the subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

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





class Solution{

    private:
      //Function to return the maximum sum of non-adjacent nodes.
      pair<int , int> solve(node* root)
      {
          // Base Case
          if (root == NULL)
          {
              pair<int , int> p = make_pair(0,0) ;
              return p ;
          }
          
          pair<int , int> left = solve(root -> left) ;
          pair<int , int> right = solve(root -> right) ;
          
          pair<int , int> res ;
          
          res.first = root -> data + left.second + right.second ;
          res.second = max(left.first , left.second) + max(right.first , right.second) ;
          
          return res ;
      }
      
      
      public:
      int getMaxSum(node *root) 
      {
          pair<int , int> ans = solve(root) ;
          return max(ans.first , ans.second) ;
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
    cout << "\nMaximum Sum of Non - Adjacent Nodes = " << sol.getMaxSum(root) <<endl;
    
    return 0;
}










