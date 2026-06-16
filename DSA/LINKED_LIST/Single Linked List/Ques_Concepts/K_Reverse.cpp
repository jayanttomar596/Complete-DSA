// Reverse consecutive nodes of k groups

/*
You are given a linked list of 'n' nodes and an integer 'k' , where 'k' is less than or equal to 'n' .

Your task is to reverse the order of each group of 'k' consecutive nodes , if 'n' is not divisible by 'k' , then the last group of nodes should remain unchanged .

For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.



Implement a function that performs this reversal, and returns the head of the modified linked list.

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


Node* kReverse(Node* head , int k)
{
    // Base Call
    if(head == NULL)
    {
        return NULL ;
    }

    // Count the number of nodes
    Node* temp = head ;
    int count = 0 ;

    while(temp)
    {
        count++;
        temp = temp -> next ;
    }


    // If less than k nodes remain , return head as it is 
    if(count < k)
    {
        return head ;
    }

    // step1 : reverse first k nodes
    Node* next = NULL ;
    Node* curr = head ;
    Node* prev = NULL ;
    int nodecount = 0 ;

    while(curr != NULL && nodecount < k)
    {
        next = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = next ;
        nodecount++;
    }


    // Step 2 : Recursion dekhlega aage ka 
    if(next != NULL)
    {
        head -> next = kReverse(next , k);
    }

    // Step3 : Return head of reversed list
    return prev ;
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

    InsertAtTail(tail , 20);

    InsertAtTail(tail , 50);

    cout<<"Linked List before K Reverse : "<<endl;
    print(head);
    cout<<endl<<endl;


    int k ;
    cout<<"Enter the value of k = ";
    cin>>k;

    Node* newhead = kReverse(head , k);

    print(newhead);

    return 0;
}





