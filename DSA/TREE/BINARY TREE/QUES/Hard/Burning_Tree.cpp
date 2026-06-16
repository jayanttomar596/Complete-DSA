// BURNING TREE



/*

Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.

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



/*

T.C. -> O(NlogN)
S.C. -> O(N)

but if we use unordered_map the T.C. will be O(N) as map requires O(1)

*/


class Solution {
    private :    
      // Create mapping 
      // return target node
      node* createParentMapping(node* root , int target , map<node* , node*> &nodeToParent)
      {
        node* res = NULL ;
        
        queue<node*> q ;
        q.push(root) ;
        nodeToParent[root] = NULL ;
        
        while(!q.empty())
        {
          node* front = q.front() ;
          q.pop() ;
            
          if (front -> data == target)
              res = front ;
          
          if (front -> left)
          {
              nodeToParent[front -> left] = front ;
              q.push(front -> left) ;
          }
          
          if (front -> right)
          {
              nodeToParent[front -> right] = front ;
              q.push(front -> right) ;
          }
      
        }
        
        return res ;
      }
      
      
      int burnTree(node* root , map<node* , node*> &nodeToParent)
      {
          map<node* , bool> visited ;
          queue<node*> q ;
          
          q.push(root) ;
          visited[root] = true ;
          
          int ans = 0 ;
          
          while(!q.empty())
          {
              
              bool flag = 0 ;
              int size = q.size() ;
              
              for (int i = 0 ; i < size ; i++)
              {
                  
                  node* front = q.front() ;
                  q.pop() ;
                  
                  if (front -> left && !visited[front -> left])
                  {
                      flag = 1 ;
                      q.push(front -> left) ;
                      visited[front -> left] = 1 ;
                  }
                  
                  if (front -> right && !visited[front -> right])
                  {
                      flag = 1 ;
                      q.push(front -> right) ;
                      visited[front -> right] = 1 ;
                  }
                  
                  if (nodeToParent[front] && !visited[nodeToParent[front]])
                  {
                      flag = 1 ;
                      q.push(nodeToParent[front]) ;
                      visited[nodeToParent[front]] = 1 ;
                  }
              }
              
              if (flag == 1)
              {
                  ans++ ;
              }
          }
          
          return ans ;
      }
      
      
      
    public:
      int minTime(node* root, int target) {
          // Alg0 :
          // Step 1 : create nodeToParent mapping
          // Step 2 : find target node
          // Step 3 : burn the tree in min time
          
          int ans ;
          map<node* , node*> nodeToParent ;
          node* targetnode = createParentMapping(root , target , nodeToParent) ;
          
          ans = burnTree(targetnode , nodeToParent) ;
          
          
          return ans ;
      }
};







int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;

    Solution sol ;

    cout << "\nMinimum time required to burn the complete binary tree if the target is set on fire = " << sol.minTime(root , 8)  << endl;
    
    return 0;
}








