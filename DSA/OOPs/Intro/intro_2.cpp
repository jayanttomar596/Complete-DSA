#include <iostream>
using namespace std;

class Hero 
{
    private :
    int health ;

    public :
    char level ;

    Hero()
    {
        cout<<"Simple Constructor Called ....."<<endl;
    }

    Hero(int health)
    {
        this -> health = health ;
    }

    Hero(int health , char level)
    {
        this -> level = level ;
        this -> health = health ;
    }

    // Copy Constructor
    Hero(Hero& temp)
    {
        cout<<"Copy Constructor Called"<<endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    int gethealth()
    {
        return health ;
    }

    void sethealth(int h)
    {
        health = h ;
    }

    void setlevel(char l)
    {
        level = l ;
    }

    void print()
    {
        cout<<"Health : "<<health<<endl;
        cout<<"Level : "<<level<<endl;
    }

    
    // Destructor
    ~Hero()
    {
        cout<<"Destructor Bhai Called"<<endl;
    }
    // Static ke liye apne aap call hi jata hai par dynamic ke liye manually b - delete object_name ;

};


int main() {

    // Hero tt ;
    /*
    If you had tried to create a Hero object without passing any arguments (e.g., Hero h;), the code would fail to compile because a default constructor is not provided by the compiler when custom constructors are present.
    */

    // Hero ramesh(10) ;
    // cout<<"Address of ramesh "<<&ramesh << endl;
    // cout<<ramesh.gethealth()<<endl;

    // Hero temp(22,'B');






    // Copy Constructor

    Hero suresh(70,'C') ;
    suresh.print();

    // Copy Constructor
    Hero R(suresh);
    R.print();


    // suresh.sethealth(70);
    // suresh.setlevel('C');
    
    return 0;
}