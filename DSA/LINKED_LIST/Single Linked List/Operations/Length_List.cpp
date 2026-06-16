// Searching in Single Linked List

/*
Searching in a Singly Linked List refers to the process of looking for a specific element or value within the elements of the linked list.


Step-by-step approach:

1) Traverse the Linked List starting from the head.
2) Check if the current node's data matches the target value.
3) If a match is found, return true.
Otherwise, Move to the next node and repeat steps 2.
4) If the end of the list is reached without finding a match, return false.
*/


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
    ~Node(){
        int value = this -> data ;
        // Memory Free
        if (this -> next != NULL)
        {
            delete next ;
            this -> next = NULL ;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void InsertAtTail(Node* &tail , int d)
{
    // New Node Created
    Node* temp = new Node(d) ;
    tail->next = temp ;
    tail = tail -> next ;
}

void print(Node* &head)
{
    Node* temp = head ;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next ;
    }
    cout<<endl;
}

int findLength(Node* &head)
{
    // Initialize a counter for the length
    int length = 0 ;

    // Start from the head of the list
    Node* temp = head ;

    // Traverse the list and increment the length for each node
    while (temp != NULL){
        length++ ;
        temp = temp->next ;
    }

    return length ;
}


int main() {
    // Created a New Node 
    Node* node1 = new Node(10);

    // Head Pointed to Node1
    Node* head = node1 ;
    // Tail Pointed to Node1
    Node* tail = node1 ;

    InsertAtTail(tail , 12);
    InsertAtTail(tail , 6);
    InsertAtTail(tail , 44);
    InsertAtTail(tail , 100);

    cout<<"\n\nLenght of the Linked List = "<<findLength(head)<<"\n"<<endl;
    
    return 0;
}


