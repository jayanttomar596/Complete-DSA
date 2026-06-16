// #include <iostream>
// using namespace std;


// class Human {

//     protected:
//     int hello ;

// public :
//     int height ;
//     int weight ;
//     int age ;

//     public :
//     int getAge()
//     {
//         return this->age ;
//     }
//     void setWeight(int w)
//     {
//         this -> weight = w ;
//     }
// };


// class Male : public Human{

//     public :
//     string color ;

//     void sleep(){
//         cout<<"Male Sleeping"<<endl;
//     }
    
//     void print()
//     {
//         cout<<hello<<endl;
//     }

//     int getHeight()
//     {
//         return this->height ;
//     }
// };


// int main() {

//     Male Object1 ;
//     cout<<"hatt"<<endl;
    
//     cout<<Object1.age<<endl;
//     cout<<Object1.weight<<endl;
//     cout<<Object1.height<<endl;

//     cout<<Object1.color<<endl;

//     Object1.setWeight(84);
//     cout<<Object1.weight<<endl;
//     Object1.sleep();
    
//     return 0;
// }






/* ACCESS MODIFIERS AND INHERITANCE
There are three Access specifiers in C++ :


public – members are accessible from outside the class, and members can be accessed from anywhere.

private – members cannot be accessed (or viewed) from outside the class, i.e members are private to that class only.

protected – members cannot be accessed from outside the class, but, they can be accessed in inherited classes or derived classes.




Public , Protected and Private Inheritance in C++

public inheritance makes public members of the base class public in the derived class, and the protected members of the base class remain protected in the derived class.

protected inheritance makes the public and protected members of the base class protected in the derived class.

private inheritance makes the public and protected members of the base class private in the derived class.

*/




// 1. C++ Public Inheritance

// C++ program to demonstrate the working of public inheritance

/*
In this example, public inheritance is demonstrated. Since private and protected members will not be directly accessed from main( ) so we have had to create functions name getPVT( ) to access the private variable and getProt( ) to access the protected variable from the inherited class.
*/


// #include <iostream>
// using namespace std;

// class Base {
// private:
//     int pvt = 1;

// protected:
//     int prot = 2;

// public:
//     int pub = 3;

//     // function to access private member
//     int getPVT() { return pvt; }
// };


// class PublicDerived : public Base {
// public:
//     // function to access protected member from Base
//     int getProt() { return prot; }
// };


// int main()
// {
//     PublicDerived object1;

//     cout << "Private = " << object1.getPVT() << endl;
//     cout << "Protected = " << object1.getProt() << endl;
//     cout << "Public = " << object1.pub << endl;

//     return 0;
// }





// 2. C++ Protected Inheritance

/*
In this example, public inheritance is demonstrated. Since private and protected members will not be directly accessed from main( ) so we have had to create functions name getPVT( ) to access the private variable and getProt( ) to access the protected variable from the inherited class.
*/


// C++ program to demonstrate the working of protected inheritance

// #include <iostream>
// using namespace std;


// class Base {
// private:
//     int pvt = 1;

// protected:
//     int prot = 2;

// public:
//     int pub = 3;

//     // function to access private member
//     int getPVT() { return pvt; }
// };


// class ProtectedDerived : protected Base {
// public:
//     // function to access protected member from Base
//     int getProt() { return prot; }

//     // function to access public member from Base
//     int getPub() { return pub; }
      
//       // function to get access to private members from Base
//       int try_getPVT() {Base::getPVT(); }
// };


// int main()
// {

//     ProtectedDerived object1;
//     cout << "Private = " << object1.try_getPVT() << endl;
//     cout << "Protected = " << object1.getProt() << endl;
//     cout << "Public = " << object1.getPub() << endl;

//     return 0;
// }





// 3. C++ Private Inheritance

/*
We know that private members cannot be accessed from the Derived class. These members cannot be directly accessed from outside the class. So we cannot use getPVT() from PrivateDerived. So we need to create the getPub() function in PrivateDerived in order to access the pub variable.
*/


// C++ program to demonstrate the working of private inheritance

// #include <iostream>
// using namespace std;


// class Base {
// private:
//     int pvt = 1;

// protected:
//     int prot = 2;

// public:
//     int pub = 3;

//     // function to access private member
//     int getPVT() { return pvt; }
// };


// class PrivateDerived : private Base {
// public:
//     // function to access protected member from Base
//     int getProt() { return prot; }

//     // function to access public member
//     int getPub() { return pub; }
  
//       // function to get access to private members from Base
//       int try_getPVT() { Base::getPVT(); }
// };


// int main()
// {
//     PrivateDerived object1;
//     cout << "Private = " << object1.try_getPVT() << endl;
//     cout << "Protected = " << object1.getProt() << endl;
//     cout << "Public = " << object1.getPub() << endl;

//     return 0;
// }











