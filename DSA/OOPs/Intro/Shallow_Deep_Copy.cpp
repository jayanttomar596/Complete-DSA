#include <iostream>
using namespace std;

class Hero 
{
    private :
    int health ;

    public :
    char *name ;
    char level ;

    Hero()
    {
        cout<<"Simple Constructor Called ....."<<endl;
        name = new char[100] ;
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
        char *ch = new char [strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this->name = ch ;
        
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
        cout<<"[ Name "<<name<<" , ";
        cout<<"Health : "<<health<<" , ";
        cout<<"Level : "<<level<<" ]\n"<<endl;
    }

    void setName(char name[])
    {
        strcpy(this->name , name);
    }

};


int main() {

    Hero hero1 ;

    hero1.sethealth(12);
    hero1.setlevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

    hero1.print();


    // use default copy constructor

    Hero hero2(hero1);
    // Hero hero2 = hero1 ;
    hero2.print();


    hero1.name[0] = 'G';
    hero1.print();
    // hero2.print();

    return 0;
}


// Shallow Copy - Same Memory Access karega 
