// REVERSE THE STRING


#include <iostream>
using namespace std;

int getLenght(char name[])
{
    int count = 0 ;
    for (int i = 0 ; name[i] != '\0' ; i++)
    {
        count++;
    }
    return count ;
}

void reverse(char name[] , int n)
{
    int s = 0 ;
    int e = n-1 ;

    while (s<e)
    {
        swap(name[s++] , name[e--]);
    }
}

int main() {
    char name[20] ;
    cout<<"Enter your name : ";
    cin>>name ;

    int len = getLenght(name);
    cout<<"Lenght : "<<len<<endl;

    cout<<"After reversing char array : "<<endl;
    reverse(name ,len);
    cout<<name<<endl;

    return 0;
}
