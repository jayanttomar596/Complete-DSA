// Floyd's Cycle Finding Algorithm

/*

Floyd’s cycle finding algorithm or Hare-Tortoise algorithm is a pointer algorithm that uses only two pointers, moving through the sequence at different speeds. This algorithm is used to find a loop in a linked list. It uses two pointers one moving twice as fast as the other one. The faster one is called the fast pointer and the other one is called the slow pointer.

While traversing the linked list one of these things will occur-

The Fast pointer may reach the end (NULL) which shows that there is no loop in the linked list.
The Fast pointer again catches the slow pointer at some time therefore a loop exists in the linked list.

*/

// TIME COMPLEXITY : O(n)
// SPACE COMPLEXITY : O(1)



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


Node* FloydDetectLoop(Node* head)
{

    if(head == NULL)
    {
        return NULL ;
    }

    Node* slow = head ;
    Node* fast = head ;

    while(slow != NULL && fast != NULL)
    {

        fast = fast -> next ;
        if(fast != NULL)
        {
            fast = fast -> next ;
        }

        slow = slow -> next ;

        if(slow == fast)
        {
            // cout<<"Present at "<<slow -> data<<endl;
            return slow ;
        }
    }

    return NULL ;
}


Node* getStartingNode(Node* head)
{

    if(head == NULL)
        return NULL ;

    Node* intersection = FloydDetectLoop(head);

    if (intersection == NULL)
    {
        return NULL ;
    }

    Node* slow = head ;

    while(slow != intersection)
    {
        slow = slow -> next ;
        intersection = intersection -> next ;
    }   

    return slow ;
}


Node* removeLoop(Node* head)
{

    if(head == NULL)
    {
        return NULL;
    }

    Node* startOfLoop = getStartingNode(head);

    if(startOfLoop == NULL)
    {
        return head;
    }

    Node* temp = startOfLoop ;

    while(temp -> next != startOfLoop)
    {
        temp = temp -> next ;
    }
    
    temp -> next = NULL ;
    return head ;
}



int main() {
    
    // Created a new node
    Node* node1 = new Node(10);
    


    // Head Pointed to Node1
    Node* head = node1 ;
    // Tail Pointed to Node1
    Node* tail = node1 ;

    InsertAtTail(tail , 12);

    InsertAtTail(tail , 15);

    InsertAtTail(tail , 22);


    tail -> next = head -> next ;


    if(FloydDetectLoop(head) != NULL)
    {
        cout<<"\nLoop is present in LL"<<endl;
    }
    else
    {
        cout<<"\nNo Loop is there in LL"<<endl;
    }

    Node* loop = getStartingNode(head);

    if(loop != NULL)
    {
        cout<<"\nLoop starts at -> "<<loop -> data << endl;
    }


    removeLoop(head);

    print(head);
    

    return 0;
}








