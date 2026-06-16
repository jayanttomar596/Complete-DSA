// Kth Ancestor in a Tree


/*

Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.

*/




#include <iostream>
#include <queue>
#include <vector>
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






// T.C. -> O(N)
// S.C. -> O(H)

class Solution1
{
private:

bool find_path(node* root , int node , vector<int> &path)
{
    if (root == NULL)
        return false ;
    
    // Add current node to path
    path.push_back(root -> data) ;
    
    // If current node is the target node
    if (root -> data == node)
        return true ;
    
    // Recurse left or right 
    if (find_path(root -> left , node , path) || find_path(root -> right , node , path))
        return true ;
    
    
    // Node not found in either subtree => Backtrack
    path.pop_back() ;
    return false ;
}


public :

int kthAncestor(node *root, int k, int node)
{
    vector<int> path ;
    
    bool found = find_path(root , node , path) ;
    
    // If node not found or k is too large
    if ( !found || path.size() < k )
        return -1 ;
    
    int index = path.size() - k - 1 ;
    
    if (index < 0)
        return -1 ;
    
    return path[index] ;
    
}

};






// T.C. -> O(N)
// S.C. -> O(H)

class Solution2
{

    node* solve(node* root , int &k , int targetnode)
    {
        // BASE CASE
        if (root == NULL)
            return NULL ;
        
        if (root -> data == targetnode)
            return root ;
        
        node* leftAns = solve(root -> left , k , targetnode) ;
        node* rightAns = solve(root -> right , k , targetnode) ;
        
        if (leftAns != NULL && rightAns == NULL)
        {
            k-- ;
            if (k <= 0)
            {
                // Answer lock
                k = INT_MAX ;
                return root ;
            }
            return leftAns ;
        }
        
        if (leftAns == NULL && rightAns != NULL)
        {
            k-- ;
            if (k <= 0)
            {
                // Answer lock
                k = INT_MAX ;
                return root ;
            }
            return rightAns ;
        }
        
        return NULL ;
    }
    
    public :

    int kthAncestor(node *root, int k, int targetnode)
    {
        node* ans = solve(root , k , targetnode) ;
        if (ans == NULL || ans -> data == targetnode)
            return -1 ;
        else
            return ans -> data ;
    }    
};





int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;

    Solution1 sol1 ;
    Solution2 sol2 ;
    int node , k ;

    cout << "\n| To find Kth Ancestor |\nEnter the value at node = ";
    cin >> node ;
    cout << "Enter the value of k = ";
    cin >> k ;

    cout << k <<"th Ancestor of node "<<node << " is : " << sol1.kthAncestor(root , k ,node) <<endl;



    cout <<"\n"<< k <<"th Ancestor of node "<<node << " is : " << sol1.kthAncestor(root , k ,node) <<endl;

    
    return 0;
}













