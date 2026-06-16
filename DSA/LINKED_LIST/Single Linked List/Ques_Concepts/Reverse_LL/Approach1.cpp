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


Node* reverseLinkedList(Node *head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head ;
    }

    Node* prev = NULL ;
    Node* curr = head ;
    Node* forward = NULL; 

    while(curr != NULL)
    {
        forward = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = forward ;
    }

    return prev ;
}



int main() {
    
    // Created a new node
    Node* node1 = new Node(10);
    


    // Head Pointed to Node1
    Node* head = node1 ;
    // Tail Pointed to Node1
    Node* tail = node1 ;

    print(head);

    InsertAtTail(tail , 12);
    print(head);
    
    InsertAtTail(tail , 15);
    print(head);

    InsertAtTail(tail , 20);
    print(head);

    InsertAtTail(tail , 50);
    print(head);
    cout<<endl<<endl;



    Node* reverse_head = reverseLinkedList(head);

    print(reverse_head);

    return 0;
}





