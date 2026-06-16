#include <iostream>
using namespace std;

int getSum(int *arr , int n)
{
    int sum = 0 ;
    for (int i = 0 ; i < n ; i++)
    {
        sum += arr[i];
    }
    return sum ;
}


int main() {
    
    // int n ;
    // cin>>n ;
    // int arr[n] ;

    // Bad Practice - Runtime pe patah chal rha hai ki kitne size ka array hai
    // Program Start -> Stack and Heap - Stack memory allot hoti hai and If we want Heap memory to allot use Keyword - "new"

    // int* arr = new int[5] ;




    // char ch = 'q';
    // cout<< sizeof(ch)<<endl;
    // Size of character is 1 .

    // char* c = &ch ;
    // cout<<sizeof(c)<<endl;
    // Size of pointer is 8 .



    int n ;
    cout<<"Enter the size of array = ";
    cin>>n;

    // variable size array
    int* arr = new int[n];

    //taking input in array
    cout<<"Enter value of each element separately : "<<endl;
    for (int i = 0 ; i < n ; i++)
    {
        cin>>arr[i];
    }

    int ans = getSum(arr,n);

    cout<<"Sum of the array = "<<ans<<endl;


    return 0;
}


// Static me apne aap memory free ho jaati hai par dynamic me free karni padti hai with 

// int* i = new int ;
// delete i ;

// int* arr = new int[50] ;
// delte []arr;




/*

What is the Heap?

The heap is a region of memory used for dynamic memory allocation.
Memory is allocated and deallocated manually by the programmer using functions like malloc, calloc, realloc, and free in C/C++, or using new and delete in C++.
In languages like Python or Java, memory allocation and deallocation on the heap are managed automatically by the garbage collector.
Key Characteristics:

Memory on the heap is persistent until explicitly deallocated.
It is slower compared to stack memory allocation because managing heap memory involves more overhead.
Suitable for large and complex data structures (e.g., linked lists, trees, graphs).
How the Heap Works:

When a program requests memory, the heap manager searches for a block of sufficient size, allocates it, and returns a pointer to the allocated memory.
The program uses the memory via the pointer.
The programmer must free the memory explicitly to avoid memory leaks (in unmanaged languages).
If the heap becomes fragmented (scattered free spaces), it can lead to inefficient memory usage.
2. Stack
What is the Stack?

The stack is a region of memory used for managing function calls, local variables, and control flow.
It operates on the Last-In-First-Out (LIFO) principle.
Memory on the stack is automatically allocated and deallocated.
Key Characteristics:

Allocation and deallocation are fast since they follow a strict order.
Memory is limited in size compared to the heap.
Stack memory is temporary and tied to the function call it belongs to.
How the Stack Works:

When a function is called, a "stack frame" is created, containing:
Function parameters.
Local variables.
Return address (address to return to after the function ends).
When the function finishes execution, its stack frame is popped off, and the memory is deallocated.
If the stack exceeds its allocated size (e.g., due to deep recursion), a stack overflow occurs.

*/






