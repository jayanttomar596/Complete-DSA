// If data replacement not allowed for Approach 1


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


void insertAtTail(Node* &tail , Node* curr )
{

    tail -> next = curr ;
    tail = curr ;
    tail -> next = NULL ;

}


Node* sortList(Node* &head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head ;
    }

    Node* zeroHead = new Node(-1) ;
    Node* zeroTail = zeroHead ;

    Node* oneHead = new Node(-1) ;
    Node* oneTail = oneHead ;

    Node* twoHead = new Node(-1) ;
    Node* twoTail = twoHead ;

    Node* curr = head ;



    // Create separate list 0s , 1s and 2s 

    while(curr != NULL)
    {
        Node* nextNode = curr -> next ;

        int value = curr -> data ;

        if (value == 0)
        {
            insertAtTail(zeroTail , curr);
        }
        else if (value == 1)
        {
            insertAtTail(oneTail , curr);
        }
        else if (value == 2)
        {
            insertAtTail(twoTail , curr);
        }

        curr = nextNode ;

    }

    // Merge 3 sublist

    // 1s list not empty
    if (oneHead -> next != NULL)
    {
        zeroTail -> next = oneHead -> next ;
    }
    else
    {
        // 1s List -> Empty
        zeroTail -> next = twoHead -> next ;
    }

    oneTail -> next = twoHead -> next ;
    twoTail -> next = NULL ;


    // Setup Head
    head = zeroHead -> next ;


    // delete dummy nodes
    zeroHead -> next = NULL ;
    oneHead -> next = NULL ;
    twoHead -> next = NULL ;

    delete zeroHead ;
    delete oneHead ;
    delete twoHead ;


    return head ;
}



int main() {
    
    
    Node* node1 = new Node(1);
    
    
    Node* head = node1 ;
    
    Node* tail = node1 ;


    InsertAtTail(tail , 0);

    InsertAtTail(tail , 1);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 0);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 1);


    print(head);
    cout<<endl<<endl;

    sortList(head);

    cout<<"\nAfter sorting 0 , 1 and 2 : "<<endl;
    print(head);


    return 0;
}





