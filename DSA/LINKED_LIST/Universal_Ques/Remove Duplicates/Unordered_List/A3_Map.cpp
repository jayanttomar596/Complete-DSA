#include <iostream>
#include <unordered_map>
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

    unordered_map<int , bool> visited ;
    Node* curr = head ;
    Node* prev = NULL ;

    while(curr != NULL)
    {
        // If data is already seen , delete the current node
        if (visited[curr->data])
        {
            prev -> next = curr -> next ;
            Node* temp = curr ;
            curr = curr -> next ;
            temp -> next = NULL ; // Avoid recursive deletion
            delete temp ;
        }
        else
        {
            // Mark the value as visited and move forward
            visited[curr -> data] = true ;
            prev = curr ;
            curr = curr -> next ;
        }
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





