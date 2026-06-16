#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int> nextSmallerElement(vector<int> &arr , int n)
{
    stack<int> s ;
    s.push(-1) ;
    vector<int> ans(n) ;

    for (int i = n-1 ; i >= 0 ; i--)
    {
        int curr = arr[i] ;
        while(s.top() >= curr)
        {
            s.pop() ;
        }

        // ans is stack ka top
        ans[i] = s.top() ;
        s.push(curr);
    }

    return ans ;
}


vector<int> previousSmallerElement(vector<int> &arr , int n)
{
    stack<int> s ;
    s.push(-1) ;
    vector<int> ans(n) ;

    for (int i = 0 ; i < n ;i++)
    {
        int curr = arr[i] ;
        while (s.top() >= curr)
        {
            s.pop() ;
        }

        // ans is stack ka top
        ans[i] = s.top() ;
        s.push(curr) ;
    }

    return ans ;
}


void Print_Vector(vector<int> &v)
{
    int size = v.size() ;
    for (int i = 0 ; i < size ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl ;
}



int main() {

    vector<int> arr = {2,1,4,3} ;
    int size = arr.size() ;


    cout<<"\nNext Smaller Element : "<<endl;

    cout<< "Original Vector : "<<endl;
    Print_Vector(arr);

    vector<int> ans1 = nextSmallerElement(arr , size) ;

    cout << "Answer Vector : "<<endl;
    Print_Vector(ans1) ;




    cout << "\n\nPrevious Smaller Element : "<<endl;

    cout<< "Original Vector : "<<endl;
    Print_Vector(arr);

    vector<int> ans = previousSmallerElement(arr , size) ;

    cout << "Answer Vector : "<<endl;
    Print_Vector(ans) ;
    
    return 0;
}