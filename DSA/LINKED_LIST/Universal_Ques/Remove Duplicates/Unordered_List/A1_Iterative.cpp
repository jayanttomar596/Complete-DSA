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


Node* removeDuplicates(Node* head)
{

    if (head == NULL)
    {
        return NULL ;
    }

    Node* curr = head ;

    while (curr != NULL && curr -> next != NULL)
    {

        Node* prev = head ;
        Node* temp = curr -> next ;

        while(temp != NULL)
        {
            if (curr -> data == temp -> data)
            {
                prev -> next = temp -> next ;
                Node* nodeToDelete = temp ;
                temp = temp -> next ; // Move temp to next node before deleting
                nodeToDelete -> next = NULL ;
                delete nodeToDelete ; // Delete safely
            }
            else
            {
                prev = temp ;
                temp = temp -> next ;
            }

        }
        
        curr = curr -> next ;
    }

    return head ;
}



int main() {
    
    // Created a new node
    Node* node1 = new Node(4);
    


    // Head Pointed to Node1
    Node* head = node1 ;
    // Tail Pointed to Node1
    Node* tail = node1 ;


    InsertAtTail(tail , 2);

    InsertAtTail(tail , 5);

    InsertAtTail(tail , 4);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 6);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 5);

    print(head);

    removeDuplicates(head);

    print(head);

    return 0;
}





