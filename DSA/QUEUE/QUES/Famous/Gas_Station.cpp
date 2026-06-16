// GAS STATION


/* PROBLEM STATEMENT

There are some gas stations along a circular route. You are given two integer arrays gas[] denoted as the amount of gas present at each station and cost[] denoted as the cost of travelling to the next station. You have a car with an unlimited gas tank. You begin the journey with an empty tank from one of the gas stations. Return the index of the starting gas station if it's possible to travel around the circuit without running out of gas at any station in a clockwise direction. If there is no such starting station exists, return -1.
Note: If a solution exists, it is guaranteed to be unique.





Examples:

Input: gas[] = [4, 5, 7, 4], cost[]= [6, 6, 3, 5]
Output: 2

Explanation: It is possible to travel around the circuit from station at index 2.
Amount of gas at station 2 is (7 - 3) 4.
Amount of gas at station 3 is (4 + 4 - 5) 3.
Amount of gas at station 0 is (3 + 4 - 6) 1.
Amount of gas at station 1 is (1 + 5 - 6) 0.

*/





#include <iostream>
#include <vector>
using namespace std;


int startStation(vector<int> &gas, vector<int> &cost) 
{

    int deficit = 0 ;
    int balance = 0 ;
    int start = 0 ;
    int n = gas.size() ;
    
    for (int i = 0 ; i < n ; i++)
    {

        balance += gas[i] - cost[i] ;

        if (balance < 0)
        {
            deficit += balance ;
            start = i + 1 ;
            balance = 0 ;
        }
    }
    
    if (deficit + balance >= 0)
        return start ;
    else
        return -1 ;

}


void print_vector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}



int main() {

    vector <int> gas = {4,5,7,4} ;
    vector <int> cost = {6,6,3,5} ;

    cout << "\nGas Array : "<<endl;
    print_vector(gas);

    cout<<"\nCost Array : " << endl;
    print_vector(gas) ;


    int start_station = startStation(gas , cost) ;

    cout << "\nPossible Start Station Index : " << start_station << endl << endl;
    
    return 0;
}



