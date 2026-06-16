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


void InsertAtPosition(Node* &tail , Node* &head , int position , int d)
{
    // Insert at start
    if (position == 1){
        InsertAtHead(head , d);
        return ;
    }

    Node* temp = head ;
    int cnt = 1 ;

    while(cnt < position - 1 )
    {
        temp = temp->next ;
        cnt++ ;
    }

    // Inserting at last position
    if(temp -> next == NULL){
        InsertAtTail(tail,d);
        return ; 
    }

    // Creating a node for d
    Node* nodeToInsert = new Node(d) ;


    nodeToInsert -> next = temp -> next ; 

    temp -> next = nodeToInsert ;
}


void deleteNode(int position , Node* &head , Node* &tail)
{
    // Deleting first or start node 
    if (position == 1)
    {
        Node* temp = head ; 
        head = head -> next ;
        // memory free start node
        temp -> next = NULL ;
        delete temp ;
    }
    else
    {
        // Deleting any middle node or last node
        Node* curr = head ;
        Node* prev = NULL ;

        int cnt = 1 ;
        while(cnt < position)
        {
            prev = curr ;
            curr = curr->next ;
            cnt++ ;
        }

        if(curr->next == NULL)
        {
            tail=prev;
        }

        prev -> next = curr -> next ;
        curr -> next = NULL ;
        delete curr ;
    }
}



int main() {
    
    // Created a new node
    Node* node1 = new Node(10);
    // cout<< node1 -> data << endl; 
    // cout<< node1 -> next << endl;


    // Head Pointed to Node1
    Node* head = node1 ;
    Node* tail = node1 ;
    print(head);

    // InsertAtHead(head , 12);
    InsertAtTail(tail , 12);

    print(head);

    // InsertAtHead(head , 12);
    InsertAtTail(tail , 15);

    print(head);

    InsertAtPosition(tail , head , 4 , 22);
    print(head);

    cout<<"Head "<<head -> data<<endl;
    cout<<"Tail "<<tail -> data << endl;

    deleteNode(4 , head , tail);
    print(head);
    cout<<"Tail "<<tail -> data << endl;

    return 0;
}





