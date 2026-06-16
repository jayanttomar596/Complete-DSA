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



void preorder(Node* root)
{
    // base case
    if (root == NULL)
        return ;
    
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}



void postorder(Node* root)
{
    // Base Case
    if (root == NULL) 
        return ;
    
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}




// Function to search a node in BST.
// T.C. -> O(H)
// S.C. -> O(1)
bool search(Node* root, int x) {
    
    Node* temp = root ;
    
    while (temp != NULL)
    {
        if (temp -> data == x)
        {
            return true ;
        }
        
        if (temp -> data > x)
        {
            temp = temp -> left ;
        }
        else
        {
            temp = temp -> right ;
        }
    }
    
    return false ;
}


// Search Using Recursion 
// T.C. -> O(H)
// S.C. -> O(H)
bool  search_recurr(Node* root , int x)
{
    // Base Case
    if (root == NULL)
        return false ;
    
    if (root -> data == x)
        return true ;
    
    if (root -> data > x)
    {
        // left part me 
        return search_recurr(root -> left , x) ;
    }
    else
    {
        // Right part me 
        return search_recurr(root -> right , x) ;
    }
}



Node* minVal(Node* root)
{
    Node* temp = root ;

    while(temp -> left != NULL)
    {
        temp = temp -> left ;
    }

    return temp ;
}



Node* maxVal(Node* root)
{
    Node* temp = root ;

    while(temp -> right != NULL)
    {
        temp = temp -> right ;
    }

    return temp ;
}






/*

Follow the steps below to solve the problem:

If root is NULL then return.
if key is found then
If its left subtree is not null, then predecessor will be the right most child of left subtree or left child itself.
If its right subtree is not null Then The successor will be the left most child of right subtree or right child itself.
If key is smaller than root node set the successor as root search recursively into left subtree.
Otherwise set the predecessor as root search recursively into right subtree.

*/

class Pred_Succ
{

private :

    // Function to find the maximum value in the left subtree (Predecessor)
    Node* rightMost(Node* node)
    {
        while(node -> right != NULL)
        {
            node = node -> right ;
        }
        return node ;
    }

    // Function to find the minimum value in the right subtree (Successor)
    Node* leftMost(Node* node)
    {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    } 



public :
      
     
    //  T.C. -> O(H)
    //  S.C. -> O(1)
    // This function finds predessor and successor of key in BST . It sets pre and suc as predecessor respectively using an iterative approach .
    void findPreSuc(Node* root , Node* &pre , Node* &suc , int key)
    {
        Node* curr = root ;

        while (curr != NULL)
        {
            if (curr -> data < key)
            {
                pre = curr ;
                curr = curr -> right ;
            }
            else if (curr -> data > key)
            {
                suc = curr ;
                curr = curr -> left ;
            }
            else
            {

                // Find the predecessor (maximum value in the left subtree)
                if (curr -> left != NULL)
                    pre = rightMost(curr -> left) ;
                
                // Find the successor (minimum value in the right subtree)
                if (curr -> right != NULL)
                    suc = leftMost(curr -> right) ;
                
                break ;
            }
        }
    }

};




// T.C. -> O(N)
// S.C. -> O(N)

// Function to find the predecessor and successor
// of a given key in BST
void findPreSuc(Node* root, int key, Node*& pre, Node*& suc) {
  
    // If root is null, return
    if (!root)
        return;

    // Traverse the left subtree
    findPreSuc(root->left, key, pre, suc);

    // The first greater value seen is successor
    if (root->data > key) {        
        if (!suc || (suc && suc->data > root->data))
            suc = root;
    }
  
    // The last smaller value seen is predecessor
    else if (root->data < key)
        pre = root;

    // Traverse the right subtree
    findPreSuc(root->right, key, pre, suc);
}




Node* deleteFromBST(Node* root , int val)
{
    // Base Case
    if (root == NULL)
        return root ;
    
    if (root -> data == val)
    {
        // 0 Child
        if (root -> left == NULL && root -> right == NULL)
        {
            delete root ;
            return NULL ;
        }

        // 1 Child

        // Left Child
        if (root -> left != NULL && root -> right == NULL)
        {
            Node* temp = root -> left ;
            delete root ;
            return temp ;
        }

        // Right Child
        if (root -> left == NULL && root -> right != NULL)
        {
            Node* temp = root -> right ;
            delete root ;
            return temp ;
        }

        // 2 Child
        if (root -> left != NULL && root -> right != NULL)
        {
            int mini = minVal(root -> right) -> data ;
            root -> data = mini ;
            root -> right = deleteFromBST(root -> right , mini) ;

            return root ;
        }
    }
    else if (root -> data > val)
    {
        // Left Part me jaao
        root -> left = deleteFromBST(root -> left , val) ;
        return root ;
    }
    else
    {
        // Right Part me jaao
        root -> right = deleteFromBST(root -> right , val) ;
        return root ;
    }
}




int main() {

    Node* root = NULL ;

    cout << "\nEnter data to create BST : " << endl ;
    takeInput(root) ;
    // 10 8 21 7 27 5 4 3 -1


    cout << "\nPrinting the BST : " << endl ; 
    levelOrderTraversal(root) ;

    cout << "\nPrinting Inorder : ";
    inorder(root) ;

    cout << "\nPrinting Preorder : ";
    preorder(root) ;

    cout << "\nPrinting Postorder : ";
    postorder(root) ;
    cout << endl << endl;

    cout << "Min Value is " << minVal(root) -> data << endl;
    cout << "Max Value is " << maxVal(root) -> data << endl;


    Node* pre = NULL ;
    Node* suc = NULL ;
    int key ;
    cout << "\nEnter the key value to find Predecessor and Successor = ";
    cin >> key ;

    Pred_Succ pre_succ ;

    pre_succ.findPreSuc(root , pre , suc , key) ;
    cout << "Predecessor of " << key <<" = " << pre -> data << endl;
    cout << "Successor of " << key <<" = " << suc -> data << endl;







    // DELETION
    root = deleteFromBST(root , 30) ;
    
    cout << "\n\n\nAFTER DELETION : \n\n" << endl;


    cout << "\nPrinting the BST : " << endl ; 
    levelOrderTraversal(root) ;

    cout << "\nPrinting Inorder : ";
    inorder(root) ;

    cout << "\nPrinting Preorder : ";
    preorder(root) ;

    cout << "\nPrinting Postorder : ";
    postorder(root) ;
    cout << endl << endl;

    cout << "Min Value is " << minVal(root) -> data << endl;
    cout << "Max Value is " << maxVal(root) -> data << endl;


    cout << "\nEnter the key value to find Predecessor and Successor = ";
    cin >> key ;


    pre_succ.findPreSuc(root , pre , suc , key) ;
    cout << "Predecessor of " << key <<" = " << pre -> data << endl;
    cout << "Successor of " << key <<" = " << suc -> data << endl;


    return 0;
}





