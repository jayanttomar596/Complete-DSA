// Types Of Inheritance :-

// | Single Inheritance
// | Multiple Inheritance
// | Multilevel Inheritance
// | Hierarchical Inheritance
// | Hybrid Inheritance





// 1. Single Inheritance
/*
From single parent to child class inheritance 
*/


// #include <iostream>
// using namespace std;

// class Animal
// {
//     public :
//     int age ;
//     int weight ;

    
//     void speak()
//     {
//         cout<<"Speaking "<<endl;
//     }
// };

// class Dog : public Animal
// {

// };

// int main() {
//     Dog d ;
//     d.speak();
//     cout<<d.age<<endl;
    
//     return 0;
// }





// 2. Multilevel Inheritance
/*
Ek baad ek inheritance hoti jaye - parent se child fir uska bhi child and so on .... 
*/


// #include <iostream>
// using namespace std;

// class Animal
// {
//     public :
//     int age ;
//     int weight ;

    
//     void speak()
//     {
//         cout<<"Speaking "<<endl;
//     }
// };

// class Dog : public Animal{

// };

// class GermanShepherd : public Dog {

// };


// int main() {
//     GermanShepherd g ;
//     g.speak();
    
//     return 0;
// }





// 3. Multiple Inheritance
/*
For one Child Class we have more than two parent class 
*/


// #include <iostream>
// using namespace std;


// class Animal
// {
//     public :
//     int age ;
//     int weight ;

    
//     void Bark()
//     {
//         cout<<"Bark "<<endl;
//     }
// };


// class Human {
//     public :
//     string color ;

//     public :
//     void speak()
//     {
//         cout<<"Speaking "<<endl;
//     }
// };

// // Multiple Inheritance

// class Hybrid : public Animal , public Human {

// };


// int main() {
    
//     Hybrid obj1 ;
//     obj1.speak();
//     obj1.Bark();
    
//     return 0;
// }





// 4. Hierarchical Inheritance
/*
One class serve as Parent class for more than 1 class
*/


// #include <iostream>
// using namespace std;

// class A {

//     public :
//     void func1(){
//         cout<<"Inside function 1"<<endl;
//     }
// };

// class B : public A {
//     public :
//     void func2(){
//         cout<<"Inside function 2"<<endl;
//     }
// };

// class C : public A {
//     public :
//     void func3(){
//         cout<<"Inside function 3"<<endl;
//     }
// };


// int main() {

//     A object1 ;
//     object1.func1();

//     B object2 ;
//     object2.func1();
//     object2.func2();

//     C object3 ;
//     object3.func1();
//     object3.func3();

//     return 0;
// }





// 5. Hybrid Inheritance
/*
Combination of more than one type of inheritance 
*/


// #include <iostream>
// using namespace std;

// class A {
//     public :
//     void funcA()
//     {
//         cout<<"Function A Called ... "<<endl;
//     }
// };

// class D {
//     public :
//     void funcD()
//     {
//         cout<<"Function D Called ... "<<endl;
//     }
// };

// class B : public A {
//     public :
//     void funcB()
//     {
//         cout<<"Function B Called ... "<<endl;
//     }
// };

// class C : public A , public D{
//     public :
//     void funcC()
//     {
//         cout<<"Function C Called ... "<<endl;
//     }
// };


// int main() {
//     cout<<"\n";
//     A a1 ;
//     a1.funcA();
//     cout<<"\n";

//     cout<<"\n";
//     B b1 ;
//     b1.funcA();
//     b1.funcB();
//     cout<<"\n";

//     cout<<"\n";
//     C c1 ;
//     c1.funcA();
//     c1.funcC();
//     c1.funcD();
//     cout<<"\n";

//     cout<<"\n";
//     D d1 ;
//     d1.funcD();
//     cout<<"\n";

//     return 0;
// }





