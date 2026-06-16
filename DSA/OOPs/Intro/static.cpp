#include <iostream>
using namespace std;

class Hero 
{
    private :
    int health ;

    public :
    char *name ;
    char level ;
    static int timeToComplete ;

    Hero()
    {
        cout<<"Simple Constructor Called ....."<<endl;
    }

    static int random()
    {
        return timeToComplete ;
    }
    // Static function ka this keyword nahi hota aur vo sirf static member ko access kar sakta hai

};


int Hero :: timeToComplete = 5 ;


int main() {

    cout<<Hero::timeToComplete<<endl;
    cout<<Hero::random()<<endl;

    Hero a ;

    cout<<a.timeToComplete<<endl;
    // above method is not recommended because static member does not belong to class


    Hero b ;
    b.timeToComplete = 10 ;
    cout<<a.timeToComplete<<endl;
    cout<<b.timeToComplete<<endl;





    // Hero hero1 ;

    // hero1.sethealth(12);
    // hero1.setlevel('D');
    // char name[7] = "Babbar";
    // hero1.setName(name);

    return 0;
}


 
