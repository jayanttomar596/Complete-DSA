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

    if (tail == NULL) { 
        tail = temp;
        return;
    }
    

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


Node * removeDuplicates(Node *head)
{
    // Empty List
    if (head == NULL)
    {
        return NULL;
    }

    // Non Empty List
    Node* curr = head ;

    while(curr != NULL)
    {

        if (curr -> next != NULL && curr -> data == curr -> next -> data)
        {
            Node* next_next = curr -> next -> next ;
            
            Node* nodeToDelete = curr -> next ;

            nodeToDelete -> next = NULL ;

            delete(nodeToDelete);

            curr -> next = next_next ;

        }
        
        else // Not Equal
        {

            curr = curr -> next ;

        }

    }

    return head;
}



int main() {
    
    // Created a new node
    Node* node1 = new Node(1);
    


    // Head Pointed to Node1
    Node* head = node1 ;
    // Tail Pointed to Node1
    Node* tail = node1 ;


    InsertAtTail(tail , 2);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 3);

    InsertAtTail(tail , 3);

    InsertAtTail(tail , 3);

    InsertAtTail(tail , 4);

    InsertAtTail(tail , 5);

    InsertAtTail(tail , 5);

    print(head);

    removeDuplicates(head);

    print(head);

    return 0;
}





