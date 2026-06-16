// Add 2 Numbers


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



class Solution
{
private:

    Node* reverse(Node* head)
    {
        Node* curr = head ;
        Node* prev = NULL ;
        Node* next = NULL ;

        while(curr != NULL)
        {
            next = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = next ;
        }

        return prev ;
    }


    void insertAtTail(Node* &head , Node* &tail , int val)
    {
        Node* temp = new Node(val) ;

        // Empty List
        if (head == NULL)
        {
            head = temp ;
            tail = temp ;
            return ;
        }
        else
        {
            tail -> next = temp ;
            tail = temp ;
        }
    }


    Node* add(Node* first , Node* second)
    {
        int carry = 0 ;

        Node* ansHead = NULL ;
        Node* ansTail = NULL ;

        while(first != NULL && second != NULL)
        {
            int sum = carry + first->data + second->data ;

            int digit = sum%10 ;

            // Create node and add in answer Linked List
            insertAtTail(ansHead , ansTail , digit);

            carry = sum/10 ;
            first = first -> next ;
            second = second -> next ;
        }


        while(first != NULL)
        {
            int sum = carry + first -> data ;
            int digit = sum%10 ;
            // Create node and add in answer Linked List
            insertAtTail(ansHead , ansTail , digit);
            carry = sum/10 ;
            first = first -> next ;
        }


        while(second != NULL)
        {
            int sum = carry + second -> data ;
            int digit = sum%10 ;
            // Create node and add in answer Linked List
            insertAtTail(ansHead,ansTail,digit);
            carry = sum/10 ;
            second = second -> next ;
        }

        while(carry != 0)
        {
            int sum = carry ;
            int digit = sum%10 ;
            // create node and add in answer Linked List
            insertAtTail(ansHead , ansTail , digit);
            carry = sum/10 ;
        }

        return ansHead ;
    }

public:
    // Function to add two numbers represented by linked list
    Node* addTwoLists(Node* first , Node* second)
    {
        // Step 1 : Raverse Input LL
        first = reverse(first);
        second = reverse(second);

        // Step 2 : Add 2 LL
        Node* ans = add(first , second);

        // Step 3
        ans = reverse(ans);

        return ans ;
    }
};



int main() {
    
    
    Node* node1 = new Node(4);

    Node* node2 = new Node(3) ;
    

    
    Node* first = node1 ;
    Node* first_tail = node1 ;
    
    Node* second = node2 ;
    Node* second_tail = node2 ;



    InsertAtTail(first_tail , 5);


    InsertAtTail(second_tail , 4);

    InsertAtTail(second_tail , 5);

    cout<<"First List :"<<endl;
    print(first);

    cout<<"Second List :"<<endl;
    print(second);


    Solution sol ;

    Node* newhead = sol.addTwoLists(first , second);

    cout<<"\n\nAfter adding both Linked List :"<<endl;
    print(newhead);

    return 0;
}





