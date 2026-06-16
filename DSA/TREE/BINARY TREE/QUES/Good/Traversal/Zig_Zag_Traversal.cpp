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




class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(node* root)
    {
    	vector<int> result ;
    	if (root == NULL)
    	   return result ;
    	
    	queue<node*> q ;
    	q.push(root) ;
    	
    	bool leftToRight = true ;
    	
    	while(!q.empty())
    	{
    	    int size = q.size() ;
    	    vector<int> ans(size) ;
    	    
    	   // Level Process
    	   for (int i = 0 ; i < size ; i++)
    	   {
    	       node* frontNode = q.front() ;
    	       q.pop() ;
    	       
    	       //Normal insert or reverse insert
    	       int index = leftToRight ? i : size - i - 1 ;
    	       ans[index] = frontNode -> data ;
    	       
    	       if (frontNode -> left)
    	           q.push(frontNode -> left) ;
    	       
    	       if (frontNode -> right)
    	           q.push(frontNode -> right) ;
    	   }
    	   
    	   //Direction change karni hai
    	   leftToRight = !leftToRight ;
    	   
    	   for (auto i : ans)
    	   {
    	       result.push_back(i) ;
    	   }
    	}
    	
    	return result ;
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




int main() {

    node* root = NULL ;

    // Creating a Tree using Recursion
    root = buildTree(root) ;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root) ;


    cout << "\nZig Zag Traversal Vector : ";
    Solution sol ;
    vector<int> zigzag_v = sol.zigZagTraversal(root) ;
    print_vector(zigzag_v) ;

    return 0;
}



