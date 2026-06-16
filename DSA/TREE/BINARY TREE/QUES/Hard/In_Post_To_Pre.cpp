// Binary Tree from Inorder and Postorder


/*

Given inorder and postorder traversals of a binary tree(having n nodes) in the arrays inorder[] and postorder[] respectively. The task is to construct a unique binary tree from these traversals and return its root.
Driver code will print the preorder traversal of the constructed tree.

Note: The inorder and postorder traversals contain unique values, and every value present in the postorder traversal is also found in the inorder traversal.

Examples:

Input: inorder[] = [4, 8, 2, 5, 1, 6, 3, 7], postorder[] = [8, 4, 5, 2, 6, 7, 3, 1]
Output: [1, 2, 4, 8, 5, 3, 6, 7]
Explanation: For the given postorder and inorder traversal of tree the resultant binary tree will be
          1
       /      \
     2        3
   /  \      /  \
  4   5     6    7
   \
    8

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
    private :
      void createMapping(vector<int> &in, map<int, int> &nodeToIndex, int n)
      {
          for (int i = 0; i < n; i++)
          {
              nodeToIndex[in[i]] = i;
          }
      }
      
      node* solve(vector<int> &in, vector<int> &post, int &index, int inorderStart,
                  int inorderEnd, int n, map<int, int> &nodeToIndex)
      {
          // Base Case
          if (index < 0 || inorderStart > inorderEnd)
          {
              return NULL;
          }
          
          // Create a root node for element 
          int element = post[index--];
          node* root = new node(element);
          
          // find element's index in inorder
          int position = nodeToIndex[element];
          
          // Recursive Call
          root->right = solve(in, post, index, position + 1, inorderEnd, n, nodeToIndex);
          root->left = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex);
          
          return root;
      }
      
    public:
  
      // Function to return a tree created from postorder and inoreder traversals.
      node* buildTree(vector<int> inorder, vector<int> postorder) {
          int n = inorder.size(); // <-- add this to get n
          int postOrderIndex = n-1;
          map<int, int> nodeToIndex;
          
          // Create nodes to index mapping
          createMapping(inorder, nodeToIndex, n);
          
          node* ans = solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);
          
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




vector<int> preorder(node* root )
{
    vector<int> preOrder;

    // Base Case
    if (root == NULL)
        return preOrder;

    // Add root node's data first
    preOrder.push_back(root->data);

    // Get preorder traversal of left subtree
    vector<int> leftPre = preorder(root->left);
    // Get preorder traversal of right subtree
    vector<int> rightPre = preorder(root->right);

    // Add left subtree preorder to current preOrder vector
    preOrder.insert(preOrder.end(), leftPre.begin(), leftPre.end());
    // Add right subtree preorder to current preOrder vector
    preOrder.insert(preOrder.end(), rightPre.begin(), rightPre.end());

    return preOrder;
}






int main() {

    // node* root = NULL ;

    // Creating a Tree using Recursion
    // root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // cout << "\nLevel Order Traversal : " << endl;
    // levelOrderTraversal(root) ;

    Solution sol ;

    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7} ;
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1} ;

    node* root = sol.buildTree(inorder,postorder) ;
    
    cout << "\nInOrder : ";
    print_vector(inorder) ;

    cout << "PostOrder : ";
    print_vector(postorder);

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;

    vector<int> preOrder = preorder(root) ;
    cout << "\nPreOrder : ";
    print_vector(preOrder);
    
    return 0;
}
