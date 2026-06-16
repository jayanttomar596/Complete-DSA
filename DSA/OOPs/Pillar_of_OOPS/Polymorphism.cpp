// POLYMORPHISM
/*
The word “polymorphism” means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. A real-life example of polymorphism is a person who at the same time can have different characteristics. A man at the same time is a father, a husband, and an employee. So the same person exhibits different behavior in different situations. This is called polymorphism. Polymorphism is considered one of the important features of Object-Oriented Programming.

Types of Polymorphism ;-
    Compile-time Polymorphism - 
    This type of polymorphism is achieved by function overloading or operator overloading.
    
    Runtime Polymorphism - 
    This type of polymorphism is achieved by Function Overriding. Late binding and dynamic polymorphism are other names for runtime polymorphism. The function call is resolved at runtime in runtime polymorphism. In contrast, with compile time polymorphism, the compiler determines which function call to bind to the object after deducing it at runtime.

*/






// 1. COMPILE TIME POLYMORPHISM - Static Polymorphism




// A) Function Overloading

/*
When there are multiple functions with the same name but different parameters, then the functions are said to be overloaded, hence this is known as Function Overloading. Functions can be overloaded by changing the number of arguments or/and changing the type of arguments. In simple terms, it is a feature of object-oriented programming providing many functions that have the same name but distinct parameters when numerous tasks are listed under one function name. There are certain Rules of Function Overloading that should be followed while overloading a function.
*/


// #include <iostream>
// using namespace std;

// class A {

//     public :
//     void sayHello() {
//         cout<<"Hello Jayant"<<endl;
//     }

//     int sayHello(char name) {
//         cout<<"Hello Jayant"<<endl;
//         return 1 ;
//     }

//     void sayHello(string name)
//     {
//         cout<<"Hello "<<name<<endl;
//     }

// };


// int main() {

//     A obj ;
//     obj.sayHello();
    
//     return 0;
// }




// B) Operator Overloading

/*
C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can make use of the addition operator (+) for string class to concatenate two strings. We know that the task of this operator is to add two operands. So a single operator ‘+’, when placed between integer operands, adds them and when placed between string operands, concatenates them. 
*/


// #include <iostream>
// using namespace std;

// class B {

//     public :
//     int a ;
//     int b ;

//     public :
//     int add() {
//         return a+b ;
//     }

//     void operator+ (B &obj)
//     {
//         int value1 = this -> a ;
//         int value2 = obj.a ;
//         cout<<"Output : "<<value2 - value1 << endl;

//         // cout << "Hello Babbar "<<endl;
//     }

//     void operator() () {
//         cout<<"Main Bracket Hu "<<this->a<<endl;
//     }

// };


// int main() {

//     B obj1 , obj2 ;

//     obj1.a = 4 ;
//     obj2.a = 7 ;

//     obj1 + obj2 ;    
//     obj1();
    
//     return 0;
// }








// 2. Runtime Polymorphism - Dynamic Polymorphism




// A) Function Overriding

/*
Function Overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.
*/

// #include <iostream>
// using namespace std;

// class Animal {
//     public:
//     void speak(){
//         cout<<"Speaking"<<endl;
//     }
// };

// class Dog : public Animal{

//     public :
//     void speak() {
//         cout<<"Barking"<<endl;
//     }
// };


// int main() {

//     Dog obj ;
//     obj.speak();
    
//     return 0;
// }




// B) Virtual Function

/*
A virtual function is a member function that is declared in the base class using the keyword virtual and is re-defined (Overridden) in the derived class.

Some Key Points About Virtual Functions:
Virtual functions are Dynamic in nature. 
They are defined by inserting the keyword “virtual” inside a base class and are always declared with a base class and overridden in a child class
A virtual function is called during Runtime
*/


// #include <iostream>
// using namespace std;

// // Declaring a Base class
// class GFG_Base {

// public:
//     // virtual function
//     virtual void display()
//     {
//         cout << "Called virtual Base Class function"
//              << "\n\n";
//     }

//     void print()
//     {
//         cout << "Called GFG_Base print function"
//              << "\n\n";
//     }
// };

// // Declaring a Child Class
// class GFG_Child : public GFG_Base {

// public:
//     void display()
//     {
//         cout << "Called GFG_Child Display Function"
//              << "\n\n";
//     }

//     void print()
//     {
//         cout << "Called GFG_Child print Function"
//              << "\n\n";
//     }
// };

// int main()
// {
//     // Create a reference of class GFG_Base
//     GFG_Base* base;

//     GFG_Child child;

//     base = &child;

//     // This will call the virtual function
//     base->display();

//     // This will call the non-virtual function
//     base->print();
// }


// Example 2

// #include <iostream>
// using namespace std;

// class base {
// public:
//     virtual void print()
//     {
//         cout << "print base class" << endl;
//     }

//     void show() { cout << "show base class" << endl; }
// };

// class derived : public base {
// public:
//     // print () is already virtual function in
//     // derived class, we could also declared as
//     // virtual void print () explicitly
//     void print() { cout << "print derived class" << endl; }

//     void show() { cout << "show derived class" << endl; }
// };

// // Driver code
// int main()
// {
//     base* bptr;
//     derived d;
//     bptr = &d;

//     // Virtual function, binded at
//     // runtime (Runtime polymorphism)
//     bptr->print();

//     // Non-virtual function, binded
//     // at compile time
//     bptr->show();

//     return 0;
// }





