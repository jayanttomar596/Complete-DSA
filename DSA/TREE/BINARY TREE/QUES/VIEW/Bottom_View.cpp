// Bottom View of Binary Tree


/*

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

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



class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      vector<int> bottomView(node *root) {
          vector<int> ans ;
          if (root == NULL)
          {
              return ans ;
          }
          
          map<int , int> bottomNode ;
          queue<pair<node* , int>> q ;
          
          q.push(make_pair(root , 0 )) ;
          
          while(!q.empty())
          {
              pair<node* , int> temp = q.front() ;
              q.pop() ;
              node* frontNode = temp.first ;
              int hd = temp.second ;
              
              
              bottomNode[hd] = frontNode -> data ;
              
              if (frontNode -> left)
                  q.push(make_pair(frontNode -> left , hd-1)) ;
              if (frontNode -> right)
                  q.push(make_pair(frontNode -> right , hd+1)) ;
          }
          
          for (auto i : bottomNode)
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

    vector<int> bottomview = sol.bottomView(root) ;
    cout << "\nBottom View Of Binary Tree : " << endl;
    print_vector(bottomview);


    return 0;
}



