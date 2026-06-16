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




// T.C. -> O(N^2)
class Solution1 {
    private :
      // Function to find the height of a binary tree
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
        int diameter(node* root) {
          // Base Case
          if (root == NULL)
          {
              return 0 ;
          }
          
          int op1 = diameter(root -> left);
          int op2 = diameter(root -> right);
          int op3 = height(root -> left) + height(root -> right) + 1 ;
        //   upar walli line me se agar 1 hatta doge toh root count nahi hoga {edge case lenge aur abhi node count kar rahe , 1 hatta diya toh edge count honge}
          
          int ans = max(op1 , max(op2 , op3));
          
          return ans ;
        }
};



// T.C. -> O(N)
class Solution2 {
    private :
      
      pair <int,int> diameterFast(node* root)
      {
          // base case
          if (root == NULL)
          {
              pair<int,int> p = make_pair(0,0) ;
              return p ;
          }
          
          pair<int, int> left = diameterFast(root -> left);
          pair<int, int> right = diameterFast(root -> right);
          
          int op1 = left.first ;
          int op2 = right.first ;
          int op3 = left.second + right.second + 1 ;
        //   uper walli line me se agar 1 hata doge toh root count nahi hoga {edge case ho jayega aur edge hi count honge abhi node count ho rahe hai }
          
          pair<int,int> ans ;
          ans.first = max(op1 , max(op2 , op3));
          ans.second = max(left.second , right.second) + 1 ;
          
          return ans ;
      }
      
    public:
      int diameter(node* root) {
          
          return diameterFast(root).first ;
      }
};




int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nLevel Order Traversal of Binary Tree : "<< endl;
    levelOrderTraversal(root);

    Solution1 sol1 ;
    cout << "\nDiameter of this Binary Tree = " << sol1.diameter(root) << endl;

    Solution2 sol2 ;
    cout << "\nDiameter of this Binary Tree = " << sol2.diameter(root) << endl;
    

    return 0;
}



