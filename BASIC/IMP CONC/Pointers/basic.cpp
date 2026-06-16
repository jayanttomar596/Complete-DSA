
// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int a = 10;
//     cout << "Address of variable a is " << &a << endl;
//     return 0;
// }


// SIZE OF POINTER IS 8 BYTES - does not depend on the datatype of pointer




// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int a = 100;
//     cout << "Value of variable a stored at address " << &a << " is " << (*(&a)) << endl;
//     return 0;
// }







// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int a = 100;
//     int *b = &a;
//     int **c = &b;
//     cout << "Value of variable a is " << a << endl;
//     cout << "Address of variable a is " << b << endl;
//     cout << "Address of pointer b is " << c << endl;
//     return 0;
// }







// int marks[] = {99, 100, 38};
// int *p = marks;
// cout << "The value of marks[0] is " << *p << endl;




// #include<iostream>
// using namespace std;

// int main()
// {
// int marks[] = {99, 100, 38};
// int *p = marks;
// cout << "The value of marks[0] is " << *p << endl;
// cout << "The value of marks[1] is " << *(p + 1) << endl;
// cout << "The value of marks[2] is " << *(p + 2) << endl;

// }








// #include <iostream>
// using namespace std;

// int main() {
//     // int *ptr ;
//          // 
//     // pointer variable
//     // Bad Practive - aise memory jo apke program ki memory bhi nahi hai usse modify karna - dangerous task

//     // intialize kardo direct , kuch nahi hai toh 0 se kardo 

//     int num = 5 ;
//     int *p = &num ;
//     // p ek dabba hoga jiske andar dusre dabbe ka address hoga
//     cout<<p<<endl<<*p<<endl;
//     cout<<(*p)+1<<endl;

//     char ch = 'a';
//     char *ptr = &ch ;
//     // ptr - address and *ptr - value and **ptr se firse address 
//     cout<<ptr<<endl<<*ptr<<endl<<&(*ptr)<<endl<<*(&(*ptr))<<endl;


//     double d = 4.2 ;
//     double *ptr1 = &d ;
//     cout<<ptr1<<endl;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int main() {
    
//     int num = 5 ;

//     cout<<num<<endl;

//     // address of Operator - &

//     cout<<"Address of num is "<<&num<<endl;

//     int *ptr = &num ;

//     cout<<"Address is : "<<ptr<<endl;
//     cout<<"Value is : "<<*ptr<<endl;
//     num++;
//     cout<<"Value is : "<<*ptr<<endl;

//     double d = 4.3 ;
//     double *p2 = &d ;

//     cout<<"Address is : "<<p2<<endl;
//     cout<<"Value is : "<<*p2<<endl;

//     cout<<"Size of integer is "<<sizeof(num)<<endl;
//     cout<<"Size of pointer is "<<sizeof(ptr)<<endl;
//     cout<<"Size of pointer is "<<sizeof(p2)<<endl;

//Size of ptr is always 8 byte which stores address

//     return 0;
// }




// #include <iostream>
// using namespace std;

// int main() {
//     //pointer to int is created , and pointing to some garbage address
//     // int *p ;
//     // int *ptr = nullptr ;  
//     // safe practice

//     // int *p = 0 ; 
//     //segmentation fault - aise memory ka address dena jo exist hi nahi karti 

//     // cout<<*p<<endl;




//     // int i = 5 ;

//     // int *q = &i ;
//     // cout<<q<<endl;
//     // cout<<*q<<endl;

//     // int *p = 0 ;
//     // p = &i ;

//     // cout<<p<<endl;
//     // cout<<*p<<endl;
// // both method are correct or same 
//     return 0;
// }






// #include <iostream>
// using namespace std;

// int main() {
//     int num = 5 ;
//     int a = num ; 
//     a++;

//     cout<<num<<endl;

//     int *p = &num ;
//     cout<<"Before : "<<num<<endl;
//     (*p)++ ;
//     cout<<"After : "<<num<<endl;

//     //copying a pointer 
//     int *q = p ;
//     cout<<p<<" - "<<q<<endl;
//     cout<<*p<<" - "<<*q<<endl<<endl;

//     //important concept

//     int i = 3 ;
//     int *t = &i ;
//     cout<<(*t)++<<endl;
//     cout<<*t<<endl;
//     *t = *t + 1 ;
//     cout<<*t<<endl;

//     cout<<"Before t "<<t<<endl;
//     t = t + 1 ;
//     cout<<"After t "<<t<<endl;

//     // 4 bytes aage khisak gaya 
//     // The size of the pointer depends on the type of data the pointer points to:

//     return 0;
// }






