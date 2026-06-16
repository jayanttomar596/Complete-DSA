// Top View of Binary Tree


/*

You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.


Note: 

Return the nodes from the leftmost node to the rightmost node.

If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 

*/




#include <iostream>
#include <queue>
#include <map>
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





class Solution_Left {
    private: 
      void solve(node* root , vector<int> &ans , int level)
      {
          // Base Case
          if (root == NULL)
              return ;
          
          // We entered into a new level
          if (level == ans.size())
              ans.push_back(root -> data);
          
          solve(root -> left , ans , level + 1);
          solve(root -> right , ans , level + 1);
      }
      
    public:
      vector<int> leftView(node *root) {
          vector<int> ans ;
          solve(root , ans , 0) ;
          return ans ;
      }
};

  


class Solution_Right {
    private: 
      void solve(node* root , vector<int> &ans , int level)
      {
          // Base Case
          if (root == NULL)
              return ;
          
          // We entered into a new level
          if (level == ans.size())
              ans.push_back(root -> data);
          
          solve(root -> right , ans , level + 1);
          solve(root -> left , ans , level + 1);
      }
      
    public:
      vector<int> rightView(node *root) {
          vector<int> ans ;
          solve(root , ans , 0) ;
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

    cout<<"\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;

    Solution_Left left_sol ;

    vector<int> leftview = left_sol.leftView(root) ;
    cout << "\nTop View Of Binary Tree : " << endl;
    print_vector(leftview);

    

    Solution_Right right_sol ;
    vector<int> rightview = right_sol.rightView(root) ;
    cout << "\nTop View Of Binary Tree : " << endl;
    print_vector(rightview);


    return 0;
}



