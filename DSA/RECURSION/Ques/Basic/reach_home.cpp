#include <iostream>
using namespace std;

void reachHome(int src , int dest)
{

    cout<< " Source : "<<src<<" | Destination : "<<dest<<endl;

    //Base Case
    if (src == dest)
    {
        cout<<" Pahuch Gaya "<<endl;
        return ;
    }

    // Processing - ek step aage badhjao
    src ++ ;

    // Recursive Call
    reachHome(src , dest);

}


int main() {
    
    int dest , src ;
    cout<<"Enter the value of src = ";
    cin>>src;

    cout<<"Enter the value of dest = ";
    cin>>dest;

    cout<<endl;

    reachHome(src , dest);
    return 0;
}





