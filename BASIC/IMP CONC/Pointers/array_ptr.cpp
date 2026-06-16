// #include <iostream>
// using namespace std;

// int main() {
    
//     int arr[5]={1,2,3,4,5};

//     cout<<"Address of the first memory block is "<< arr <<endl;

//     cout<<"Value at 0 index = "<< arr[0] <<endl;

//     cout<<"Address of first memory block is "<< &arr[0] <<endl;

//     cout<<"Value at 0 index = "<< *arr <<endl;

//     cout<<"-> "<<*(arr+1)<<endl;// value at 1 index
//     cout<<"Value at 1 index = "<<arr[1]<<endl;

//     cout<<"-> *(arr) + 5 = "<< *(arr) + 5 <<endl;// value at 1st position ie 0 index + 5 = 6


//     // cout<<1[arr]<<endl;
//     //aise bhi array ko access kar sakte hai 



//     cout<<sizeof(arr)<<endl;
//     // this prints the size of array and not the size of pointer of 0 index element 

//     int *ptr = &arr[0]; // 5 X 4 = 20
//     cout<<sizeof(ptr)<<endl;
//     cout<<sizeof(*ptr)<<endl;
//     cout<<sizeof(&ptr)<<endl;// pointer ka bhi address

//     return 0;
// }







// #include <iostream>
// using namespace std;

// int main() {
//     int a[20] = {1,2,3,5};
//     cout<< &a[0] << endl;
//     cout<< &a << endl ;
//     cout<< a << endl;

// /*
// In C++, the expression &a[0] gives the address of the first element of the array a, and &a gives the address of the entire array. Since arrays in C++ decay to pointers to their first element when passed to functions or used in expressions, the following happens:

// &a[0] is the address of the first element of the array, which is a pointer to a[0].
// &a is the address of the whole array, but since arrays decay to pointers to their first element, &a is also equivalent to a.
// a (without &) is a pointer to the first element of the array. This is the same as &a[0].
// Thus, when you print &a[0], &a, and a, all of them print the same memory address because they all refer to the address of the first element of the array.
// */

//     int *p = &a[0];
//     cout<< p << endl;
//     cout<< *p << endl;
//     cout<< &p <<endl;

//     cout<<"\n\n";

//     cout<<&a[0]<<endl;
//     cout<< & p <<endl;
//     return 0;
// }







// Symbol Table cannot be changed , Symbol Table means mapping of arr elements with there address

#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0} ;

    // arr = arr + 1 ;
    // uppar walle se error ayega - NOT ASSIGNABLE 

    int *ptr = &arr[0];
    cout<<ptr<<endl;
    ptr = ptr + 1 ;
    cout<<ptr<<endl;

    // Par yeh toh chal gaya - isme humne symbol table ya address change nahi kiya , bus yeh agle block ke address pe move kar jayega 

    

    return 0;
}