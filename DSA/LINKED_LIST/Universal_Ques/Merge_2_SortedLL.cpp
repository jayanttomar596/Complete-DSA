// Merge two sorted Linked list


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



Node* solve(Node* first , Node* second)
{

    // if only one element is present in first element
    if (first -> next  == NULL)
    {
        first -> next = second ;
        return first  ;
    }


    Node* curr1 = first ;
    Node* next1 = curr1 -> next ;
    Node* curr2 = second ;
    Node* next2 = curr2 -> next ;

    while(next1 != NULL && curr2 != NULL)
    {

        if ( (curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data) )
        {

            // Add Node in between the first list
            curr1 -> next = curr2 ;
            next2 = curr2 -> next ;
            curr2 -> next = next1 ;
            // Update Pointers
            curr1 = curr2 ;
            curr2 = next2 ;

        }
        else
        {
            // curr1 and next1 ko aage badhana padega
            curr1 = next1 ;
            next1 = next1 -> next ;

            if (next1 == NULL)
            {
                curr1 -> next = curr2 ;
                return first ;
            }
        }
    }

    return first ;
}


Node* MergeTwoLists (Node* first , Node* second)
{
    if (first == NULL)
        return second ;

    if (second == NULL) 
        return first ;

    if (first -> data <= second -> data)
    {
        return solve(first , second);
    }
    else
    {
        return solve(second , first);
    }       
}



int main() {
    
    
    Node* node1 = new Node(1);

    Node* node2 = new Node(2) ;
    

    
    Node* first = node1 ;
    Node* first_tail = node1 ;
    
    Node* second = node2 ;
    Node* second_tail = node2 ;



    InsertAtTail(first_tail , 3);

    InsertAtTail(first_tail , 5);


    InsertAtTail(second_tail , 4);

    InsertAtTail(second_tail , 5);

    cout<<"First List :"<<endl;
    print(first);

    cout<<"Second List :"<<endl;
    print(second);

    Node* merge_head = MergeTwoLists(first , second);

    cout<<"\n\nAfter Merging both Sorted List :"<<endl;
    print(merge_head);


    return 0;
}





