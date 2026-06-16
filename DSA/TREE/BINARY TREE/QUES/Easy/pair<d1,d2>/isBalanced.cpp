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




// T.C. -> O(N^2) 
class Solution1 {
    private :
      int height(node* node)
      {
          // base case
          if (node == NULL)
              return 0 ;
          
          int left = height(node -> left);
          int right = height(node -> right);
          
          int ans = max(left , right) + 1 ;
          
          return ans ;
      }
      
      
    public:
      bool isBalanced(node* root) {
          // Base Case
          if (root == NULL)
              return true ;
          
          
          bool left = isBalanced(root -> left) ;
          bool right = isBalanced(root ->right) ;
          
          bool diff = abs (height(root -> left) - height(root -> right) ) <= 1 ;
          
          if (left && right && diff)
          {
              return 1 ;
          }
          else
          {
              return false ;
          }
      }
};




// T.C. -> O(N)
class Solution2 {
    private :
      pair<bool , int> isBalancedFast(node* root)
      {
          // base case
          if (root == NULL)
          {
              pair<bool , int> p = make_pair(true , 0) ;
              return p ;
          }
          
          pair<int , int> left = isBalancedFast(root -> left) ;
          pair<int , int> right = isBalancedFast(root -> right) ;
          
          
          bool leftAns = left.first ;
          bool rightAns = right.first ;
          
          bool diff = abs (left.second - right.second) <= 1 ;
          
          pair<bool,int> ans ;
          ans.second = max(left.second , right.second) + 1 ;
          
          if (leftAns && rightAns && diff)
          {
              ans.first = true ;
          }
          else
          {
              ans.first = false ;
          }
          
          return ans ;
      }
      
      
    public:
      bool isBalanced(node* root)
      {
          return isBalancedFast(root).first ;
      }
};





int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nLevel Order Traversal of Binary Tree : "<< endl;
    levelOrderTraversal(root);



    // Example for Not Balanced Tree
    // 1 3 7 8 9 -1 -1 -1 -1 11 -1 -1 5 -1 -1

    cout << "\nIs Balanced : " ;
    Solution1 sol1 ;
    if(sol1.isBalanced(root))
    {
        cout << "Its a Balanced Binary Tree" << endl;
    }
    else
    {
        cout << "Its not a Balanced Binary Tree" << endl;
    }



    cout << "\nIs Balanced : " ;
    Solution2 sol2 ;
    if(sol2.isBalanced(root))
    {
        cout << "Its a Balanced Binary Tree" << endl;
    }
    else
    {
        cout << "Its not a Balanced Binary Tree" << endl;
    }
    

    return 0;
}







