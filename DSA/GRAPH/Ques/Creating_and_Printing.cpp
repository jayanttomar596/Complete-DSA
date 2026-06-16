// Creating and Printing



/*

You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops present in the graph.



In graph theory, an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph.

*/





#include <iostream>
#include <vector>
using namespace std;





// T.C. -> O(M+N)
// S.C. -> O(M+N)

vector<vector<int>> printAdjacency(int n , int m , vector<vector<int>> &edges )
{
    vector<int> ans[n] ;
    // Ans array will store all adjacent nodes corresponding on indexes .
    for (int i = 0 ; i < m ; i++)
    {
        int u = edges[i][0] ;
        int v = edges[i][1] ;

        ans[u].push_back(v) ;
        ans[v].push_back(u) ;
    }

    vector<vector<int>> adj(n) ;

    for (int i = 0 ; i < n ; i++)
    {
        adj[i].push_back(i) ;

        // Entering neighbours
        for (int j = 0 ; j < ans[i].size() ; j++)
        {
            adj[i].push_back(ans[i][j]) ;
        }
    }

    return adj ;
}




int main() {

    // Sample graph with 5 nodes and 4 edges
    int n = 5; // number of nodes
    int m = 4; // number of edges

    // Define edges as pairs {u, v}
    vector<vector<int>> edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3}
    };

    // vector<vector<int>> edges = {
    //     {4, 3},
    //     {1, 2},
    //     {0, 3},
    //     {2, 3}
    // };


    // Call function
    vector<vector<int>> adjList = printAdjacency(n, m, edges);




    // Print adjacency list

    cout << "Adjacency List:\n";

    for (int i = 0; i < adjList.size(); i++) {
        for (int j = 0; j < adjList[i].size(); j++) {
            cout << adjList[i][j];
            if (j != adjList[i].size() - 1) 
                cout << " -> ";
        }
        cout << endl;
    }
    

    return 0;
}

