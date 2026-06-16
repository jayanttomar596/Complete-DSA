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


int list_length(Node* tail)
{
    Node* temp = tail ;
    int len = 0 ;
    // Empty List
    if(tail == NULL)
    {
        cout << "List is Empty"<<endl;
        return 0 ;
    }

    do {
        len++;
        tail = tail->next ;
    }while(tail != temp);

    return len ;   
}


int main() {
    
    Node* tail = NULL ;

    // empty list me insert kar rha hu
    insertNode(tail , 5 , 3);
    print(tail);

    insertNode(tail , 3 , 5);
    print(tail);

    insertNode(tail , 5 , 7);
    print(tail);

    insertNode(tail , 7 , 9);
    print(tail);

    insertNode(tail , 5 , 6);
    // 5 ke baad 6 laga dega
    print(tail);

    cout<<"Length of Linked List = "<<list_length(tail)<<endl;

    return 0;
}





