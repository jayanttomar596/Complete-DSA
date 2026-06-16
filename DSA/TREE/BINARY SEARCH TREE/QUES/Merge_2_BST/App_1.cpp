// Merge Two BSTs




#include <iostream>
#include <queue>
#include <vector>
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






// T.C. -> O(m+n)
// S.C. -> O(m+n)

class Solution {
    private :
        void inorder(Node* root , vector<int> &v)
        {
            if (root == NULL)
                return ;
            
            inorder(root -> left , v) ;
            v.push_back(root -> data) ;
            inorder(root -> right , v) ;
        }
        
        vector<int> mergeArray(vector<int> &a , vector<int> &b)
        {
            vector<int> ans(a.size() + b.size()) ;
            
            int i = 0 , j = 0  , k = 0 ;
            
            while( i < a.size() && j < b.size())
            {
                if (a[i] < b[j])
                {
                    ans[k++] = a[i++] ;
                }
                else
                {
                    ans[k++] = b[j++] ;
                }
            }
            
            while(i < a.size())
            {
                ans[k++] = a[i++] ;
            }
            
            while(j < b.size())
            {
                ans[k++] = b[j++] ;
            }
            
            return ans ;
        }

        Node* inorderToBST(int s , int e , vector<int> &in)
        {
            // Base Case
            if (s > e)
            {
                return NULL ;
            }

            int mid = (s+e)/2 ;
            Node* root = new Node(in[mid]) ;
            root -> left = inorderToBST(s , mid-1 , in) ;
            root -> right = inorderToBST(mid+1 , e , in) ;

            return root ;
        }
        


    public:
      
      Node* merge(Node *root1, Node *root2) {
          vector<int> bst1 ;
          vector<int> bst2 ;
          
          inorder(root1 , bst1 ) ;
          inorder(root2 , bst2 ) ;
          
          vector<int> mergedArray = mergeArray(bst1 , bst2) ;
          
          int s = 0 , e = mergedArray.size() - 1 ;

          return inorderToBST(s , e , mergedArray) ;
      }
};






int main() {

    Node* root1 = NULL ;
    Node* root2 = NULL ;



    cout << "\nEnter data to create BST [root1] : " << endl ;
    takeInput(root1) ;
    // 10 8 21 7 27 5 4 3 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root1) ;

    cout << "\nInorder Traversal : " ;
    inorder(root1) ; 




    
    cout << "\nEnter data to create BST [root1] : " << endl ;
    takeInput(root2) ;

    // 2 9 13 16 85 1 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root2) ;

    cout << "\nInorder Traversal : " ;
    inorder(root1) ; 




    Solution sol ;

    Node* root = sol.merge(root1 , root2) ;


    cout << "\n AFTER MERGING " << endl;

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;

    cout << "\nInorder Traversal : " ;
    inorder(root) ; 
    cout << endl;


    return 0 ;
}





