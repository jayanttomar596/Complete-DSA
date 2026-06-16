// Check Linked List given is Circular or not 

/*

1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form a circle i.e. the next pointer of last node points to the first node.

2. An empty linked will also be considered as circular.


Par hum sirf complete circle ke liye solve karenge - bichme koi circle banne wo case nahi le rhe

*/



#include <iostream>
using namespace std;

class Node {
public :
    int data ;
    Node* next ;

    // Constructor
    Node(int d)
    {
        this->data = d ;
        this->next = NULL ;
    }

    ~Node(){
        int value = this->data ;
        if (this->next != NULL )
        {
            delete next ;
            next = NULL ;
        }
        cout<<"Memory is free for node with data "<<value <<endl;
    }
};


void insertNode(Node* &tail , int element , int d)
{

    // Empty List
    if (tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode ;
        newNode -> next = newNode ;
    }
    else
    {
        // Non Empty List
        // Assuming that the element is present in the list

        Node* curr = tail ;

        while(curr -> data != element)
        {
            curr = curr -> next ;
        }

        // Element found -> curr is representing element walla node
        Node* temp = new Node(d);
        temp -> next = curr -> next ;
        curr -> next = temp ;

    }
}


void print(Node* tail)
{
    Node* temp = tail ;

    // Empty List
    if(tail == NULL)
    {
        cout << "List is Empty"<<endl;
        return ;
    }

    do {
        cout << tail -> data <<" ";
        tail = tail -> next ;
    }while(tail != temp);

    cout<<endl;
}


bool isCircularList(Node* head)
{
    // Empty List
    if(head == NULL)
    {
        return true ;
    }

    Node* temp = head -> next ;
    while(temp != NULL && temp != head)
    {
        temp = temp -> next ;
    }

    if(temp == head)
    {
        return true ;
    }

    return false ;
}



int main() {
    
    Node* tail = NULL ;

    // empty list me insert kar rha hu
    insertNode(tail , 5 , 3);

    insertNode(tail , 3 , 5);

    insertNode(tail , 5 , 7);

    insertNode(tail , 7 , 9);
    

    insertNode(tail , 5 , 6);
    // 5 ke baad 6 laga dega

    insertNode(tail , 9 , 10);

    insertNode(tail , 3 , 4);
    print(tail);
    cout<<endl<<endl;


    if(isCircularList(tail))
    {
        cout<<"Linked List is Circular"<<endl;
    }
    else
    {
        cout<<"Linked List is not Circular"<<endl;
    }


    return 0;
}





