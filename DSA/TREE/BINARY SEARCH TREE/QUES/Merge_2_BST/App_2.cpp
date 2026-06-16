// Merge Two BSTs



// T.C. -> O(m+n)
// S.C. -> O(h1 + h2)


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
// S.C. -> O(h1+h2)

class Solution {
    private :
        void convertIntoSortedDLL(Node* root , Node* &head)
        {
            // Base Case
            if (root == NULL)
                return  ;
            
            convertIntoSortedDLL(root -> right , head) ;

            root -> right = head ;

            if (head != NULL)
                head -> left = root ;
            
            head = root ;

            convertIntoSortedDLL(root -> left , head) ;

        }



        Node* mergeLinkedList(Node* head1 , Node* head2)
        {
            Node* head = NULL ;
            Node* tail = NULL ;

            while(head1 != NULL && head2 != NULL)
            {
                if (head1 -> data < head2 -> data)
                {
                    if (head == NULL)
                    {
                        head = head1 ;
                        tail = head1 ;
                        head1 = head1 -> right ;
                    }
                    else
                    {
                        tail -> right = head1 ;
                        head1 -> left = tail ;
                        tail = head1 ;
                        head1 = head1 -> right ;
                    }
                }
                else
                {
                    if (head == NULL)
                    {
                        head = head2 ;
                        tail = head2 ;
                        head2 = head2 -> right ;
                    }
                    else
                    {
                        tail -> right = head2 ;
                        head2 -> left = tail ;
                        tail = head2 ;
                        head2 = head2 -> right ;
                    }
                }
            }

            while(head1 != NULL)
            {
                tail -> right = head1 ;
                head1 -> left = tail ;
                tail = head1 ;
                head1 = head1 -> right ;
            }

            while(head2 != NULL)
            {
                tail -> right = head2 ;
                head2 -> left = tail ;
                tail = head2 ;
                head2 = head2 -> right ;
            }

            return head ;
        }


        int countNodes(Node* &head)
        {
            int cnt = 0 ;
            Node* temp = head ;
            while(temp != NULL)
            {
                cnt++ ;
                temp = temp -> right ;
            }
            return cnt ;
        }


        Node* sortedLLToBST(Node* &head , int n)
        {
            // Base Case
            if (n <= 0 || head == NULL)
            {
                return NULL ;
            }

            Node* left = sortedLLToBST(head , n/2) ;

            Node* root = head ;
            root -> left = left ;

            head = head -> right ;

            root -> right = sortedLLToBST(head , n-n/2-1) ;

            return root ;
        }

    public:
      
      Node* merge(Node *root1, Node *root2) {
          
        // Step1 : Convert BST into Sorted DLL in-place
        Node* head1 = NULL ;
        convertIntoSortedDLL(root1 , head1) ;
        head1 -> left = NULL ;

        Node* head2 = NULL ;
        convertIntoSortedDLL(root2 , head2) ;
        head2 -> left = NULL ;


        // Step 2 : Merge sorted Linked List
        Node* head = mergeLinkedList(head1 , head2) ;

        // Step 3 : Convert SLL into BST
        return sortedLLToBST(head , countNodes(head)) ;
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




    
    cout << "\nEnter data to create BST [root2] : " << endl ;
    takeInput(root2) ;
    // 2 9 13 16 85 1 -1

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root2) ;

    cout << "\nInorder Traversal : " ;
    inorder(root2) ; 




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





