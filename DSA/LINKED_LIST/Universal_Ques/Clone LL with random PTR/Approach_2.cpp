#include <iostream>
#include <unordered_map>
using namespace std;


class Node {

public:
    int data ;
    Node* next ;
    Node* random ;

    // Constructor
    Node(int data)
    {
        this -> data = data ;
        this -> next = NULL ;
        this -> random = NULL ;
    }

    // Destructor
    ~Node() {
        int value = this -> data ;
        // memory free
        if(this -> next != NULL )
        {
            delete next ;
            delete random;
            this->next = NULL ;
            this -> random = NULL ;
        }
        cout<<"Memory is free for node with data "<<value << endl;
    }
};



class Solution
{
private:
    void insertAtTail(Node* &head , Node* &tail , int d)
    {
        Node* newNode = new Node(d);

        if (head == NULL)
        {
            head = newNode ;
            tail = newNode ;
            return ;
        }
        else
        {
            tail -> next = newNode ;
            tail = newNode ;
        }
    }

public :
    Node* cloneLinkedList(Node* head)
    {
        // Step1: Create a clone list
        Node* cloneHead = NULL ;
        Node* cloneTail = NULL ;

        Node* temp = head ;

        while (temp != NULL)
        {
            insertAtTail(cloneHead , cloneTail , temp->data);
            temp = temp -> next ;
        }


        // Step2 : Create a Map
        unordered_map<Node* , Node*> oldToNewNode ;

        Node* originalNode = head ;
        Node* cloneNode = cloneHead ;

        while(originalNode != NULL && cloneHead != NULL)
        {
            oldToNewNode[originalNode] = cloneNode ;
            originalNode = originalNode -> next ;
            cloneNode = cloneNode -> next ;
        }

        originalNode = head ;
        cloneNode = cloneHead ;

        while(originalNode != NULL)
        {
            cloneNode -> random = oldToNewNode[originalNode -> random];
            originalNode = originalNode -> next ;
            cloneNode = cloneNode -> next ;
        }

        return cloneHead ;
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



void print_random(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node: " << temp->data;
        if (temp->random)
            cout << " (Random: " << temp->random->data << ")";
        cout << endl;
        temp = temp->next;
    }
    cout << endl;
}




int main() {
    
    // Created a new node
    Node* node1 = new Node(1);
    

    Node* head = node1 ;
    
    Node* tail = node1 ;

    InsertAtTail(tail , 2);

    InsertAtTail(tail , 3);

    InsertAtTail(tail , 4);

    InsertAtTail(tail , 5);

    head -> random = head -> next -> next ;

    head -> next -> random = head ;

    head -> next -> next -> random = tail ;

    head -> next -> next -> next -> random = head -> next -> next ;

    tail -> random = head -> next ;

    cout<<"\nOriginal Linked List with random pointers : "<<endl;
    print_random(head);

    Solution sol ;
    Node* clone_head = sol.cloneLinkedList(head) ;

    cout<<endl<<endl;

    cout<<"Clone Linked List with random pointers : "<<endl;
    print_random(clone_head);


    return 0;
}









