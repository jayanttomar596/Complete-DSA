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


// Traversing a Linked List Backward
void print_back(Node* tail)
{
    Node* temp = tail ;

    while(temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->prev ;
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


int main() {

    Node* node1 = new Node(8) ;
    Node* head = node1 ;
    Node* tail = node1 ;

    print_back(tail);

    InsertAtHead(head ,tail , 11);
    print_back(tail);

    InsertAtHead(head ,tail , 20);
    print_back(tail);

    InsertAtHead(head ,tail , 31);
    print_back(tail);
    
    return 0;
}




