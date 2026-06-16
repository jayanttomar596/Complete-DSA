// N - Queen Problem 



/*

The N Queens puzzle is the problem of placing N chess queens on an N * N chessboard such that no two queens attack each other.

Given an integer ‘N’, print all distinct solutions to the ‘N’ queen puzzle.

Two queens on the same chessboard can attack each other if any of the below condition satisfies:  
1. They share a row. 
2. They share a column. 
3. They share a diagonal. 

*/






#include <iostream>
#include <vector>
using namespace std;




class Solution
{
private :

    void addSolution(vector<vector<int>> &ans , vector<vector<int>> &board , int n)
    {
        vector<int> temp ;
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < n ; j++)
            {
                temp.push_back(board[i][j]) ;
            }
        }

        ans.push_back(temp) ;
    }


    bool  isSafe(int row , int col , vector<vector<int>> &board , int n)
    {
        int x = row ;
        int y = col ;

        // check for same row
        while(y >= 0)
        {
            if (board[x][y] == 1)
            {
                return false ;
            }
            y-- ;
        }

        
        x = row ;
        y = col ;
        // check for diagnol
        while(x >= 0 && y >= 0)
        {
            if(board[x][y] == 1)
            {
                return false ;
            }
            y-- ;
            x-- ;
        }


        x = row ;
        y = col ;
        // check for diagnol
        while(x < n && y >= 0)
        {
            if(board[x][y] == 1)
            {
                return false ;
            }
            y-- ;
            x++ ;
        }

        return true ;
    }


    void solve(int col , vector<vector<int>> &ans , vector<vector<int>> &board , int n)
    {
        // Base Case
        if (col == n)
        {
            addSolution(ans , board , n) ;
            return ;
        }


        // Solve 1 case and rest Recursion will take care

        for (int row = 0 ; row < n ; row++)
        {
            if (isSafe(row , col , board , n))
            {
                // if placing queen is safe
                board[row][col] = 1 ;
                solve(col+1 , ans , board , n) ;

                // backtrack
                board[row][col] = 0 ;
            }
        }
    }



public :

    vector<vector<int>> nQueens(int n)
    {
        vector<vector<int>> board(n , vector<int>(n , 0)) ;
        vector<vector<int>> ans ;

        solve(0 , ans , board , n) ;

        return ans ;
    } 
};



void print_2d_vector(vector<vector<int>> v) 
{
    for (const auto& row : v) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}



int main() {

    cout << "\nTo Place N Queen on a chess board of N x N size : " << endl;
    int n ;
    cout << "Enter the value of N = ";
    cin >> n ;


    Solution sol ;

    vector<vector<int>>  ans = sol.nQueens(n) ;

    cout << "\nPositioning will be " << endl;
    print_2d_vector(ans) ;

    return 0;
}
