// K Sum Paths

/*

Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

*/






#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
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
// S.C. -> O(N)

class Solution1 {
    public:
      void solve(node* root , int k , int &count , vector<int> path)
      {
          // base case
          if (root == NULL)
              return ;
          
          path.push_back(root -> data);
          
          // Left
          solve(root -> left , k , count , path);
          // Right
          solve(root -> right , k , count , path);
          
          // Check for k sum
          int size = path.size() ;
          int sum = 0 ;
          
          for (int i = size - 1 ; i >= 0; i--)
          {
              sum += path[i];
              if (sum == k)
                  count++ ;
          }
          
          path.pop_back() ;
      }
      
      
      int sumK(node *root, int k) {
          vector<int> path ;
          int count = 0 ;
          solve(root , k , count , path) ;
          return count ;
      }
};





// T.C. -> O(N)
// S.C. -> O(N)

class Solution2 {
    public:
      void solve(node* root, int k, int currSum, unordered_map<int, int>& prefixSumCount, int& count) {
          if (root == NULL)
              return;
          
          // Add current node's data to running sum
          currSum += root->data;
          
          // If currSum itself is equal to k, one valid path is found
          if (currSum == k)
              count++;
          
          // Check if there is a prefix sum that satisfies currSum - prefixSum = k
          if (prefixSumCount.find(currSum - k) != prefixSumCount.end())
              count += prefixSumCount[currSum - k];
          
          // Increment prefix sum count for currSum
          prefixSumCount[currSum]++;
          
          // Recurse left and right
          solve(root->left, k, currSum, prefixSumCount, count);
          solve(root->right, k, currSum, prefixSumCount, count);
          
          // Backtrack - remove the current prefix sum as we return to the parent node
          prefixSumCount[currSum]--;
      }
  
      int sumK(node* root, int k) {
          unordered_map<int, int> prefixSumCount;
          int count = 0;
          solve(root, k, 0, prefixSumCount, count);
          return count;
      }
};





int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 1 1 -1 -1 1 -1 -1 1 1 -1 -1 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;


    Solution1 sol1 ;
    Solution2 sol2 ;
    int k ;
    cout << "Enter the value of k = " ;
    cin >> k ;
    cout << "\nNumber of Paths where sum of nodes values in path equals to " <<k<<" : "<< sol1.sumK(root,k) <<endl;

    cout << "\nNumber of Paths where sum of nodes values in path equals to " <<k<<" : "<< sol2.sumK(root,k) <<endl;
    
    
    return 0;
}










