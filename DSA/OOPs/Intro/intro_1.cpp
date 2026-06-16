#include <iostream>
using namespace std;


class khalli
{
    // properties
};


class Hero 
{

    // properties

private : // Private ki properties sirf class ke andar access ki ja sakti hai
    char level ;  


public :

    /* CONSTRUCTORS
    Constructors are methods that are automatically executed every time you create an object. The purpose of a constructor is to construct an object and assign values to the object's members. A constructor takes the same name as the class to which it belongs, and does not return any values.

    By default constructor is already done .
    */

    Hero()
    {
        cout<<"Constructor Called"<<endl;
    }

    int health ;




    // Parameterised Constructor
    Hero(int health)
    {
        cout<<"this -> "<<this <<endl;
        this -> health = health ;
    }

    Hero(int health , char level)
    {
        this -> level = level ;
        this -> health = health ;
    }
    


    void print()
    {
        cout<<level<<endl;
    }

    int getHealth()
    {
        return health ;
    }
    // agar password lagana hai toh andar if ki condition lagake karlo 

    char getLevel()
    {
        return level ;
    }

    void setHealth(int h)
    {
        health = h ;
    }

    void setLevel(char ch)
    {
        level = ch ;
    }

};



int main() {

    // Static Allocation
    khalli k1 ;
    Hero Jayant(10) ;
    Hero  a ;
    
    a.setHealth(80);
    a.setLevel('B');
 
    cout<<"\nHealth is "<<a.health<<endl;
    cout<<"Level is "<<a.getLevel()<<endl;
    cout<<"\n\n";


    // Dynamically Allocation
    Hero *b = new Hero ;
    b->setLevel('A');
    b->setHealth(70);

    cout<<"Level is "<<(*b).getLevel()<<endl;
    cout<<"Health is "<<(*b).health<<endl;

    cout<<"Level is "<<b->getLevel()<<endl;
    cout<<"Health is "<<b->health<<endl;
    cout<<"\n\n";


    cout<<"Ramesh health is "<<Jayant.getHealth()<<endl;


    // Jayant.health = 100 ;
    Jayant.setHealth(100);


    cout<<sizeof(k1)<<endl;
    // Empty class ka size - 1 byte [just for the sake identification or to track class]


    cout<<sizeof(Jayant)<<endl;
    // Ouput : 8
    // Total Size: 4 bytes (health) + 1 byte (level) + 3 bytes (padding) = 8 bytes. -> to ensure proper alignment and improve memory access efficiency 


    cout<<Jayant.health<<endl;
    // cout<<h1.level<<endl;

    // By default - properties are Private[Access Modifiers]

    return 0;
}



