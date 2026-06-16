// Solve the Sudoku



/*

Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.

*/





#include <iostream>
#include <vector>
using namespace std;





// T.C. -> O(9^empty) [WORST O(9^81)]
// S.C. -> O(1) [WORST O(81)]

class Solution 
{
private :
    bool isSafe(int row , int col , vector<vector<int>> &board , int val)
    {
        for (int i = 0 ; i < board.size() ; i++)
        {
            // Row Check
            if (board[row][i] == val)
                return false ;
            
            // Col Check
            if (board[i][col] == val)
                return false ;
            
            // 3*3 matrix check
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
                return false ;
        }

        return true ;
    }

    
    bool solve(vector<vector<int>> &board)
    {
        int n = board[0].size() ;

        for (int row = 0 ; row < n ; row++)
        {
            for (int col = 0 ; col < n ; col++)
            {
                // Cell Empty
                if (board[row][col] == 0)
                {
                    for (int val = 1 ; val <= 9 ; val++)
                    {
                        if(isSafe(row , col , board , val))
                        {
                            board[row][col] = val ;

                            // Recursive Call
                            bool aageSolutionPossible = solve(board) ;

                            if (aageSolutionPossible)
                                return true ;
                            else
                            {
                                // backtrack
                                board[row][col] = 0 ;
                            }    
                        }
                    }

                    return false ;
                }
            }
        }

        return true ;
    }



public : 

    void solveSudoku(vector<vector<int>> &board) {
        solve(board) ;
    }

};




int main() {

    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };


    cout << "\nUnSolved Sudoku Board:\n\n";
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    Solution solver;
    solver.solveSudoku(board);

    // Print the solved Sudoku board
    cout << "\n\nSolved Sudoku Board:\n\n";
    for (const auto& row : board) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    
    return 0;
}

