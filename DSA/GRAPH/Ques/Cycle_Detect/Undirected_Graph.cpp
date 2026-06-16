//  Cycle Detectection in Undirected Graph




// T.C. -> O(N+M)
// S.C. -> O(N+M)


#include <unordered_map>
#include <queue>
#include <list>
#include <iostream>
using namespace std;



bool isCyclicBFS(int src , unordered_map<int , bool> &visited , unordered_map<int , list<int>> adj)
{
    unordered_map<int , int> parent ;

    parent[src] = -1 ;
    visited[src] = 1 ;
    queue<int> q ;
    q.push(src) ;

    while(!q.empty())
    {
        int front = q.front() ;
        q.pop() ;

        for (auto neighbour : adj[front])
        {
            if (visited[neighbour] == true && neighbour != parent[front])
            {
                return true ;
            }
            else if (!visited[neighbour])
            {
                q.push(neighbour) ;
                visited[neighbour] = 1 ;
                parent[neighbour] = front ;
            }
        }
    }

    return false ;
} 



bool isCyclicDFS(int node , int parent , unordered_map<int , bool> &visited , unordered_map<int , list<int>> adj)
{
    visited[node] = true ;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour , node , visited , adj) ;

            if (cycleDetected)
                return true ;
        }
        else if (neighbour != parent)
        {
            // Cycle present
            return true ;
        }
    }
    return false ;
}



bool cycleDetection(vector<vector<int>>& edges , int n , int m)
{
    // Create adjacency list
    unordered_map<int , list<int>> adj ;
    for (int i = 0 ; i < m ; i++)
    {
        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    // To handle disconnected components
    unordered_map<int , bool> visited ;
    for (int i = 0 ; i < n ; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(i , visited , adj) ;

            // bool ans = isCyclicDFS(i , -1 , visited , adj) ;

            if (ans == 1)
                return true ;
        }
    }

    return false ;
}





int main() {

    // Example: Graph with a cycle
    // Edges: (0-1), (1-2), (2-0), (3-4)
    int n = 5; // Number of nodes
    int m = 4; // Number of edges

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {3, 4}
    };

    if (cycleDetection(edges, n, m))
    {
        cout << "\nCycle detected in the graph .\n" << endl;
    }
    else
    {
        cout << "\nNo cycle found in the graph .\n" << endl;
    }
    
    return 0;
}


