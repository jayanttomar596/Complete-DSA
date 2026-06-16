#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution
{

private :
    bool knows(vector<vector<int>> &M , int a , int b , int n)
    {
        if (M[a][b] == 1)
            return true ;
        else
            return false ;    
    }

public :
    // Function to find if there is a celebrity in the party or not
    int celebrity(vector<vector<int>> &M , int n)
    {
        stack<int> s ;

        // Step1 : Push all element in stack
        for (int i = 0 ; i < n ; i++)
        {
            s.push(i) ;
        }

        // Step2 : Get 2 elements and compare them
        while(s.size() > 1)
        {
            int a = s.top() ;
            s.pop() ;

            int b = s.top() ;
            s.pop() ;

            if (knows(M,a,b,n))
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int ans = s.top() ;


        // Step3 : Single Element in stack is potential celeb so verify it

        // Row Check
        int zeroCount = 0 ;

        for (int i = 0 ; i < n ; i++)
        {
            if (M[ans][i] == 0)
                zeroCount++ ;
        }

        if (zeroCount != n)
            return -1 ;
        
        
        // Column Check
        int oneCount = 0 ;

        for (int i = 0 ; i < n ; i++)
        {
            if (M[i][ans] == 1)
                oneCount++ ;
        }

        if (oneCount != n-1)
            return -1 ;
        
        
        return ans ;   
    } 
};


void Print_2D_Vector(vector<vector<int>> v , int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        cout<<"[ ";
        for (int j = 0 ; j < n ; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
}



int main() {

    vector<vector<int>> v = {{0,1,0},{0,0,0},{0,1,0}} ;

    cout << "Square Matrix used to represent people at party : "<<endl;
    Print_2D_Vector(v , 3) ;

    Solution sol ;

    int celebrity = sol.celebrity(v,3) ;

    cout << "\nCelebrity Index = "<<celebrity << endl;

    return 0;
}




