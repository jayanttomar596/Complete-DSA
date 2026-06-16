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

int getLength(Node* head)
{

    int len = 0 ;
    while(head != NULL)
    {
        len++ ;
        head = head -> next ;
    }

    return len ;
}


Node* findMiddle(Node* &head)
{
    int len = getLength(head);
    int ans = (len/2) + 1 ;

    Node* temp = head ;
    int cnt = 1 ;
    while(cnt < ans)
    {
        temp = temp -> next ;
        cnt++;
    }

    return temp ;
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





