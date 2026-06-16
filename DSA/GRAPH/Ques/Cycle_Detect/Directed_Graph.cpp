#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;




// T.C. -> O(N+E)
// S.C. -> O(N+E)

bool checkCycleDFS(int node , unordered_map<int , bool> &visited , unordered_map<int , bool> &dfsVisited , unordered_map<int , list<int>> &adj)
{
    visited[node] = true ;
    dfsVisited[node] = true ;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = checkCycleDFS(neighbour , visited , dfsVisited , adj) ;
            
            if (cycleDetected)
                return true ;
        }
        else if (dfsVisited[neighbour])
        {
            return true ;
        }
    }

    dfsVisited[node] = false ;

    return false ;
}




bool detectCycleInDirectedGraph(int n , vector<pair<int , int>> &edges)
{
    // Create adj List
    unordered_map<int , list<int>> adj ;
    for (int i = 0 ; i < edges.size() ; i++)
    {
        int u = edges[i].first ;
        int v = edges[i].second ;

        adj[u].push_back(v) ;
    }


    // Call dfs for all components
    unordered_map<int , bool> visited ;
    unordered_map<int , bool> dfsvisited ;
    for (int i = 1 ; i <= n ; i++)
    {
        if(!visited[i])
        {
            bool cycleFound = checkCycleDFS(i , visited , dfsvisited , adj) ;
            if (cycleFound)
                return true ;
        }
    }

    return false ;
}





int main() {

    // Number of nodes
    int n = 4;

    // Edges in the graph (directed)
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2} // Cycle: 2 -> 3 -> 4 -> 2
    };

    bool hasCycle = detectCycleInDirectedGraph(n, edges);


    if (hasCycle)
        cout << "\nCycle detected in the directed graph!" << endl;
    else
        cout << "\nNo cycle in the directed graph." << endl;
    
    return 0;
}