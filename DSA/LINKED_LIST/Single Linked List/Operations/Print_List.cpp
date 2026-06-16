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


void InsertAtHead(Node* &head , int d){

    // New Node Created
    Node* temp = new Node(d);
    temp -> next = head ;
    head = temp ; 
}


void InsertAtTail(Node* &tail , int d)
{
    // new node create
    Node* temp = new Node(d);
    tail -> next = temp ;
    tail = tail -> next ; 
}



// Traversal involves visiting each node in the linked list and performing some operation on the data . A simple traversal function would print or process the data of each node . 
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


int main() {
    
    // Created a new node
    Node* node1 = new Node(10);
    


    // Head Pointed to Node1
    Node* head = node1 ;
    // Tail Pointed to Node1
    Node* tail = node1 ;

    print(head);

    // InsertAtHead(head , 12);
    InsertAtTail(tail , 12);

    print(head);

    // InsertAtHead(head , 12);
    InsertAtTail(tail , 15);

    print(head);




    return 0;
}





