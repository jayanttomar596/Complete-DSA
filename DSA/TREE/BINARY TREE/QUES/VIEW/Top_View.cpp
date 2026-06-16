// Top View of Binary Tree


/*

You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.


Note: 

Return the nodes from the leftmost node to the rightmost node.

If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 

*/


// T.C. -> O(NlogN)
// S.C. -> O(N)


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



class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      vector<int> topView(node *root) {
          vector<int> ans ;
          if (root == NULL)
          {
              return ans ;
          }
          
          map<int , int> topNode ;
          queue<pair<node* , int>> q ;
          
          q.push(make_pair(root , 0 )) ;
          
          while(!q.empty())
          {
              pair<node* , int> temp = q.front() ;
              q.pop() ;
              node* frontNode = temp.first ;
              int hd = temp.second ;
              
              // If one value is present for a HD , then do nothing
              if (topNode.find(hd) == topNode.end())
                  topNode[hd] = frontNode -> data ;
              
              if (frontNode -> left)
                  q.push(make_pair(frontNode -> left , hd-1)) ;
              if (frontNode -> right)
                  q.push(make_pair(frontNode -> right , hd+1)) ;
          }
          
          for (auto i : topNode)
          {
              ans.push_back(i.second) ;
          }
          
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

    Solution sol ;

    vector<int> topview = sol.topView(root) ;
    cout << "\nTop View Of Binary Tree : " << endl;
    print_vector(topview);


    return 0;
}



