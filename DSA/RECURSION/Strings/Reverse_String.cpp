#include <iostream>
using namespace std;


void reverse(string &str , int i , int j)
{
    cout<<"Call Recieved for "<<str<<endl;

    // Base Case
    if (i>j)
        return ;

    swap(str[i],str[j]);
    i++;
    j--;    

    // Recursive Call
    reverse(str,i,j);
}


int main() {
    
    string name = "abcde";

    cout<<"Original String : "<<name<<endl<<endl;

    reverse(name , 0 , name.length() - 1);

    cout<<"\nReversed String : "<<name <<endl;

    return 0;
}



