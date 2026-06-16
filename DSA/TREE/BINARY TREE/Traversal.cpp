#include <iostream>
#include <queue>
#include <stack>
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




void reverseLevelOrderTraversal(node* root) {
    if (root == nullptr) 
        return;

    queue<node*> q;
    stack<node*> s;
    
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            s.push(NULL);

            if (!q.empty())
            {
                // queue still have some child nodes
                q.push(NULL);
            }
        }
        else
        {
            // Push the node to stack
            s.push(temp);

            // Enqueue right child first, then left (to reverse order)
            if (temp->right) {
                q.push(temp->right);
            }
            if (temp->left) {
                q.push(temp->left);
            }
        }
    }
    

    // Print stack contents (which is reverse order)
    while (!s.empty()) {
        if (s.top() == NULL)
        {
            cout << endl;
            s.pop();
            continue;
        }

        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}



void inorder(node* root)
{
    // base case
    if (root == NULL)
        return ;
    
    inorder(root -> left );
    cout << root -> data << " ";
    inorder(root -> right);
}



void preorder(node* root)
{
    // base case
    if (root == NULL)
        return ;
    
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}



void postorder(node* root)
{
    // Base Case
    if (root == NULL) 
        return ;
    
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}




int main() {

    node* root = NULL ;

    // Creating a Tree
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


    // Level Order
    cout << "\n\nPrinting the Level Order Traversal Output : "<<endl; 
    levelOrderTraversal(root);


    cout << "\nPrinting the Reverse Level Order Traversal Output : ";
    reverseLevelOrderTraversal(root);


    cout << "\nInorder Traversal : "<<endl;
    inorder(root) ;
    cout << endl;


    cout << "\nPreOrder Traversal : "<<endl;
    preorder(root) ;
    cout << endl;


    cout << "\nPostOrder Traversal : "<<endl;
    postorder(root) ;
    cout << endl;

    return 0;
}



