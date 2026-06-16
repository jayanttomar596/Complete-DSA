// Middle find
// Reverse LL after it 
// Compare both halve 
// repeat 2nd step 


// T.C. :- O(n)
// S.C. :- O(1)



#include <iostream>
using namespace std;


class Node {

public:
    int data ;
    Node* next ;

    // Constructor
    Node(int data)
    {
        this -> data = data ;
        this -> next = NULL ;
    }

    // Destructor
    ~Node() {
        int value = this -> data ;
        // memory free
        if(this -> next != NULL)
        {
            delete next ;
            this->next = NULL ;
        }
        cout<<"Memory is free for node with data "<<value << endl;
    }
};


void InsertAtTail(Node* &tail , int d)
{
    // new node create
    Node* temp = new Node(d);

    if (tail == NULL) { // If the list is empty
        // head = temp;
        tail = temp;
        return;
    }
    // Single List me agar list NULL hai toh InsertToHead me koi problem nahi aye sirf InsertToTail me ayegi 

    tail -> next = temp ;
    tail = tail -> next ; 
}


void print(Node* &head)
{
    Node* temp = head ;

    while (temp != NULL)
    {
        cout << temp -> data <<" ";
        temp = temp -> next ;
    } 
    cout << endl ;
}


class Solution{
private:
    Node* getMid(Node* head)
    {
        Node* slow = head ;
        Node* fast = head -> next ;

        while(fast != NULL && fast -> next != NULL)
        {
            fast = fast -> next -> next ;
            slow = slow -> next ; 
        }

        return slow ;
    }

    Node* reverse(Node* head)
    {
        Node* curr = head ;
        Node* prev = NULL ;
        Node* next = NULL ;

        while(curr != NULL)
        {
            next = curr -> next;
            curr -> next = prev ;
            prev = curr ;
            curr = next ;
        }

        return prev ;
    }

public :
    // Function to check whether the list is palindrome
    bool isPalindrome(Node* head)
    {
        if (head == NULL || head -> next == NULL)
        {
            return true ;
        }

        // Step-1 : Find Middle
        Node* middle = getMid(head);

        // Step-2 : Reverse List after middle
        Node* temp = middle -> next ;
        middle -> next = reverse(temp) ;

        // Step-2 : Compare Both Halves
        Node* head1 = head ;
        Node* head2 = middle->next ;

        while(head2 != NULL)
        {
            if (head1 -> data != head2 -> data)
            {
                return false ;
            }
            head1 = head1 -> next ;
            head2 = head2 -> next ;
        }

        // Step-4 : Repeat step 2 (Optional)
        temp = middle -> next ;
        middle -> next = reverse(temp);

        return true ;
    }
         
};



int main() {
    
    
    Node* node1 = new Node(1);
    


    
    Node* head = node1 ;
    
    Node* tail = node1 ;


    InsertAtTail(tail , 0);

    InsertAtTail(tail , 1);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 1);

    InsertAtTail(tail , 0);

    InsertAtTail(tail , 1);

    cout<<"\nLinked List :"<<endl;
    print(head);
    cout<<endl;

    Solution sol ;

    bool result = sol.isPalindrome(head);

    if (result)
    {
        cout<<"Linked List is Palindrome"<<endl;
    }
    else
    {
        cout<<"Linked List is not Palindrome"<<endl;
    }

    return 0;
}





