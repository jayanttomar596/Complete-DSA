
/*Problem statement
Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.

Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.
*/

// Three type of ques are asked :
// 1) Detect cycle in LL
// 2) Remove Cycle in LL 
// 3) Beginning / Start node of Loop in LL



#include <iostream>
#include <map>
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


bool detectLoop(Node* head)
{

    if(head == NULL)
    {
        return false ;
    }

    map<Node* , bool> visited ;

    Node* temp = head ;

    while(temp != NULL)
    {

        // Cycle is present
        if(visited[temp] == true)
        {
            cout<<"Present on Element "<<temp->data<<endl;
            return true ;
        }

        visited[temp] = true ;
        temp = temp -> next ;

    }

    return false ;

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


    if(detectLoop(head))
    {
        cout<<"\nLoop is present in LL"<<endl;
    }
    else
    {
        cout<<"\nNo Loop is there in LL"<<endl;
    }

    

    return 0;
}




// Space Complexity :- O(n)
// Time Complexity :- O(N)














