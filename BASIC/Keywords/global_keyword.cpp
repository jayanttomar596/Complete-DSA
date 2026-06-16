#include <iostream>
using namespace std;

int score = 15 ;
// Scope Global ho gaya 
// Bad Practice - koi bhi function isko change kar sakta hai aur fir har jagah change ho jayega 


void b(int& i);

void a(int& i)
{
    cout<<score << " in a "<<endl;

    char ch = 'a';
    // yeh ch variable sirf iss function walle block tak valid rahega

    cout<<i<<endl;
    b(i);
}

void b(int& i)
{
    cout<<score<<" in b" <<endl;
    cout<<i<<endl;
}



int main() {
    
    int i = 5 ;
    // yeh i main function ke block tak valid rahega 

    a(i);

    {
        int i = 2 ;
        cout << i << endl;
        // yeh i is isi block me valid rahega {}

    }

    return 0;
}