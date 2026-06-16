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


Node* reverseLinkedList(Node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head ;
    }

    Node* prev = NULL ;
    Node* curr = head ;
    Node* forward = NULL ;

    while(curr != NULL)
    {
        forward = curr -> next ;
        curr -> next = prev ;
        curr -> prev = forward ;
        prev = curr ;
        curr = forward ;
    }

    return prev ;
}



int main() {

    Node* node1 = NULL ;
    Node* head = NULL ;
    Node* tail =NULL ;

    InsertAtTail(head ,tail , 11);
    print(head);

    InsertAtTail(head ,tail , 13);
    print(head);

    InsertAtTail(head ,tail, 8);
    print(head);

    InsertAtTail(head , tail , 25);
    print(head);
    cout<<endl<<endl;

    Node* Reverse_Head = reverseLinkedList(head);

    print(Reverse_Head);

    
    return 0;
}




