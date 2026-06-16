// Construct Tree from Inorder & Preorder


/*

Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

Note: The output is written in postorder traversal.

*/




#include <iostream>
#include <queue>
#include <vector>
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


/*
T.C. -> O(NlogN)
S.C. -> O(N)

T.C. is nlogn while using map
T.C. will be n while using unordered map due to diff in T.C. for searching in map and unordered_map
*/


class Solution {
    private:
      
      void createMapping(vector<int> &in, map<int, int> &nodeToIndex, int n)
      {
          for (int i = 0; i < n; i++)
          {
              nodeToIndex[in[i]] = i;
          }
      }
      
      node* solve(vector<int> &in, vector<int> &pre, int &index, int inorderStart,int inorderEnd, int n, map<int, int> &nodeToIndex)
      {
          // Base Case
          if (index >= n || inorderStart > inorderEnd)
          {
              return NULL;
          }
          
          // Create a root node for element 
          int element = pre[index++];
          node* root = new node(element);
          
          // find element's index in inorder
          int position = nodeToIndex[element];
          
          // Recursive Call
          root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
          root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);
          
          return root;
      }
      

      public : 
      // Function to build the tree from given inorder and preorder traversals
      node* buildTree(vector<int> &inorder, vector<int> &preorder) {
          int n = inorder.size(); // <-- add this to get n
          int preOrderIndex = 0;
          map<int, int> nodeToIndex;
          
          // Create nodes to index mapping
          createMapping(inorder, nodeToIndex, n);
          
          node* ans = solve(inorder, preorder, preOrderIndex, 0, n - 1, n, nodeToIndex);
          
          return ans;
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




vector<int> postorder(node* root )
{
    vector<int> postOrder;

    // Base Case
    if (root == NULL)
        return postOrder;

    // Get postorder traversal of left subtree
    vector<int> leftPost = postorder(root->left);
    // Get postorder traversal of right subtree
    vector<int> rightPost = postorder(root->right);

    // Add left subtree postorder to current postOrder vector
    postOrder.insert(postOrder.end(), leftPost.begin(), leftPost.end());
    // Add right subtree postorder to current postOrder vector
    postOrder.insert(postOrder.end(), rightPost.begin(), rightPost.end());

    // Add root node's data
    postOrder.push_back(root->data);

    return postOrder;
}





int main() {

    // node* root = NULL ;

    // Creating a Tree using Recursion
    // root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout << "\nLevel Order Traversal : " << endl;
    // levelOrderTraversal(root) ;

    Solution sol ;

    vector<int> inorder = {3, 1, 4, 0, 2, 5} ;
    vector<int> preorder = {0, 1, 3, 4, 2, 5} ;

    node* root = sol.buildTree(inorder,preorder) ;
    
    cout << "\nInOrder : ";
    print_vector(inorder) ;

    cout << "PreOrder : ";
    print_vector(preorder);

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;

    vector<int> postOrder = postorder(root) ;
    cout << "\nPost Order : ";
    print_vector(postOrder);
    
    return 0;
}













