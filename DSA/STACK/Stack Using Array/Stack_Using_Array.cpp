// IMPLEMENTING STACK USING ARRAY



#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int top ;

public :
    int a[MAX]; // Maximum size of stack

    Stack() {
        top = -1 ;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};


bool Stack::push(int x)
{
    if (top >= (MAX -1))
    {
        cout << "Stack Overflow";
        return false ;
    }
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true ;
    }
}


int Stack::pop()
{
    if (top < 0)
    {
        cout<<"Stack Underflow";
        return 0 ;
    }
    else
    {
        int x = a[top--];
        return x ;
    }
}


int Stack::peek()
{
    if (top < 0)
    {
        cout<<"Stack is Empty";
        return 0 ;
    }
    else
    {
        int x = a[top];
        return x ;
    }
}


bool Stack::isEmpty()
{
    return (top < 0);
}



int main() {
    
    class Stack s ;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << " \nPopped from stack\n";

    // Print top element of stack after poping
    cout << "\nTop element is : "<<s.peek() << endl;

    // Print all elements in stack : 
    cout<<"\nElements present is stack : ";
    while(!s.isEmpty())
    {
        // Printing top element in stack
        cout<<s.peek()<<" ";
        // Remove top element in stack ;
        s.pop();
    }
    cout<<endl;

    return 0;
}
