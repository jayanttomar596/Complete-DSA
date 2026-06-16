// 1 2 3 4 5 -> ISME MID 3 HONA CHAIYE
// 1 2 3 4 5 6 -> ISME MID 4 HONA CHAIYE


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


Node* findMiddle(Node* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head ;
    }

    // 2 Nodes - Needed or not
    if(head -> next -> next == NULL)
    {
        return head -> next ;
    }

    Node* slow = head ;
    Node* fast = head -> next ;

    while(fast != NULL)
    {
        fast = fast -> next ;
        if (fast != NULL)
        {
            fast = fast -> next ;
        }

        slow = slow -> next ;
    }

    return slow ;
}


int main() {
    
    // Created a new node
    Node* node1 = new Node(10);
    


    // Head Pointed to Node1
    Node* head = node1 ;
    // Tail Pointed to Node1
    Node* tail = node1 ;

    print(head);

    InsertAtTail(tail , 12);
    print(head);
    
    InsertAtTail(tail , 15);
    print(head);

    InsertAtTail(tail , 20);
    print(head);

    InsertAtTail(tail , 50);
    print(head);

    InsertAtTail(tail , 90);
    print(head);
    cout<<endl<<endl;

    Node* middle_node = findMiddle(head);

    cout<<"Middle Node Data = "<<middle_node->data<<endl;
   

    return 0;
}





