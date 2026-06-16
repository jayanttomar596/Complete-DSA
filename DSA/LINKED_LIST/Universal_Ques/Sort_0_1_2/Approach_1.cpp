// Counting and storing no of 0 , 1 and 2s and then replacing the data


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


Node* sortList(Node* &head)
{
    int zeroCount = 0 ;
    int oneCount = 0 ;
    int twoCount = 0 ;

    Node* temp = head ;

    while(temp != NULL)
    {
        if (temp -> data == 0)
            zeroCount++;
        else if (temp -> data == 1)
            oneCount++ ;
        else if (temp -> data == 2)
            twoCount++ ;

        temp = temp -> next ;            
    }

    temp = head ;

    while(temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp -> data = 0 ;
            zeroCount-- ;
        }
        else if (oneCount != 0)
        {
            temp -> data = 1 ;
            oneCount-- ;
        }
        else if (twoCount != 0)
        {
            temp -> data = 2 ;
            twoCount-- ;
        }

        temp = temp -> next ;
    }

    return head ;
}



int main() {
    
    
    Node* node1 = new Node(1);
    


    
    Node* head = node1 ;
    
    Node* tail = node1 ;


    InsertAtTail(tail , 0);

    InsertAtTail(tail , 1);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 0);

    InsertAtTail(tail , 1);


    print(head);
    cout<<endl<<endl;

    sortList(head);

    cout<<"After sorting 0 , 1 and 2 : "<<endl;
    print(head);


    return 0;
}





