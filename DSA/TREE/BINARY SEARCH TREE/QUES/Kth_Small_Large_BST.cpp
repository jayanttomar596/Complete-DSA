// k-th Smallest in BST


/*

Given a BST and an integer k, the task is to find the kth smallest element in the BST. If there is no kth smallest element present then return -1.

*/



// T.C. -> O(N)
// S.C. -> O(H)



#include <iostream>
#include <queue>
using namespace std;


class Node 
{

public :
    int data ;
    Node* left ;
    Node* right ;
    
    Node(int d)
    {
        this -> data = d ;
        this -> left = NULL ;
        this -> right = NULL ;
    }
};




// T.C. -> O(H)
// S.C. -> O(H)
Node* insertIntoBST(Node* &root , int d)
{
    // Base Case
    if (root == NULL)
    {
        root = new Node(d) ;
        return root ;
    } 

    if (d > root -> data)
    {
        // Right part me insert karna hai
        root -> right = insertIntoBST(root -> right , d) ;
    }
    else
    {
        // Left part me insert karna hai
        root -> left = insertIntoBST(root -> left , d);
    }

    return root ;
}



void takeInput(Node* &root)
{

    int data ;
    cin >> data ;

    while(data != -1)
    {
        insertIntoBST(root , data) ;
        cin >> data ;
    }
}




void levelOrderTraversal(Node* root)
{
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty())
    {
        Node* temp = q.front() ;
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



void inorder(Node* root)
{
    // base case
    if (root == NULL)
        return ;
    
    inorder(root -> left );
    cout << root -> data << " ";
    inorder(root -> right);
}




class Solution_kth_min {
    private :
      int solve(Node* root , int &i , int k)
      {
          // Base Case
          if (root == NULL)
          {
              return -1 ;
          }
      
          // Left 
          int left = solve(root -> left , i , k) ;
      
          if (left != -1)
          {
              return left ;
          }
      
          // Node
          i++ ;
          if (i == k)
              return root -> data ;
      
          // Right 
          return solve(root -> right , i , k) ;
      }

      
    public:
      // Return the Kth smallest element in the given BST
      int kthSmallest(Node *root, int k) {
          int i = 0 ;
          int ans = solve(root , i , k) ;
          
          return ans ;
      }
};



class Solution_kth_large {
    private:
      int solve(Node* root , int &i , int k , int n)
      {
          // Base Case
          if (root == NULL)
          {
              return -1 ;
          }
        
          // Left 
          int left = solve(root -> left , i , k , n) ;
        
          if (left != -1)
          {
              return left ;
          }
        
          // Node
          i++ ;
          if (i == n-k+1)
              return root -> data ;
        
          // Right 
          return solve(root -> right , i , k , n) ;
      }
      
      void no_of_nodes(Node* root , int &n)
      {
          // Base Case
          if (root == NULL)
              return ;
          
          no_of_nodes(root -> left , n) ;
          n++ ;
          no_of_nodes(root -> right , n) ;
      }
      
    
    public:
      int kthLargest(Node *root, int k) {
          int i = 0 , n = 0 ;
          no_of_nodes(root , n) ;
          int ans = solve(root , i , k , n) ;
            
          return ans ;
      }
};



class Solution2_kth_large {
    public:
        // Helper function for reverse inorder traversal
        void reverseInorder(Node* root, int& k, int& result) {
            if (root == nullptr || k <= 0) {
                return;
            }
    
            // Visit right subtree first (larger elements)
            reverseInorder(root->right, k, result);
            
            // Decrease k and check if this is the kth element
            k--;
            if (k == 0) {
                result = root->data;
                return;
            }
            
            // Visit left subtree (smaller elements)
            reverseInorder(root->left, k, result);
        }
    
        int kthLargest(Node* root, int K) {
            int result = -1;
            reverseInorder(root, K, result);
            return result;
        }
};





int main() {

    Node* root = NULL ;

    cout << "\nEnter data to create BST : " << endl ;
    takeInput(root) ;
    // 10 8 21 7 27 5 4 3 -1

    int k ;
    cout << "\nEnter the value of k to find kth smallest element = " ;
    cin >> k ;


    Solution_kth_min sol1 ;
    cout << k << "th Smallest Element in BST = " << sol1.kthSmallest(root , k) << endl;

    Solution_kth_large sol2 ;
    cout << k << "th Smallest Element in BST = " << sol2.kthLargest(root , k) << endl;


    return 0;
}










