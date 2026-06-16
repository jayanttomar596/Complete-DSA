#include <iostream>
using namespace std;


class Node {
public :
    int data ;
    Node* prev ;
    Node* next ;

    // Constructor
    Node(int d)
    {
        this -> data = d ;
        this -> prev = NULL ;
        this -> next = NULL ;
    }

    ~Node()
    {
        int val = this -> data ;
        if(next != NULL)
        {
            delete next ;
            next = NULL ;
        }
        cout<<"Memory free for node with data "<<val<<endl;
    }
};


// Traversing a Linked List
void print(Node* head)
{
    Node* temp = head ;

    while(temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next ;
    }
    cout<<endl;
}



void InsertAtHead(Node* &head , Node* & tail ,int d)
{
    // Empty List
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp ;
        tail = temp ;
        return ;
    }
    // Create a new node
    Node* temp = new Node(d);

    temp->next = head ;
    head->prev = temp ;
    head = temp ;

}


void InsertAtTail(Node* &head , Node* &tail , int d)
{
    if (tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp ;
        tail = temp ;
        return ;
    }

    // Create a new node
    Node* temp = new Node(d);

    tail->next = temp ;
    temp->prev = tail ;
    tail = temp ;
}


void InsertAtPosition(Node* &tail , Node* &head , int position , int d)
{
    // Insert at Start
    if(position == 1)
    {
        InsertAtHead(head , tail ,d);
        return ;
    }

    Node* temp = head ;
    int cnt = 1 ;

    while(cnt < position - 1)
    {
        temp = temp->next ;
        cnt++;
    }

    // Inserting at Last Position
    if (temp -> next == NULL)
    {
        InsertAtTail(head , tail ,d);
        return ;
    }

    // Creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next ;
    temp -> next -> prev = nodeToInsert ;
    temp -> next = nodeToInsert ;
    nodeToInsert -> prev = temp ;
}


int main() {

    Node* node1 = NULL ;
    Node* head = NULL ;
    Node* tail =NULL ;

    InsertAtHead(head ,tail , 11);
    print(head);

    InsertAtHead(head ,tail , 13);
    print(head);

    InsertAtHead(head ,tail, 8);
    print(head);

    InsertAtTail(head , tail , 25);
    print(head);

    InsertAtPosition(tail , head , 2 , 100);
    print(head);

    InsertAtPosition(tail , head , 1 , 101);
    print(head);

    InsertAtPosition(tail , head , 7 , 102);
    print(head);
    
    return 0;
}




