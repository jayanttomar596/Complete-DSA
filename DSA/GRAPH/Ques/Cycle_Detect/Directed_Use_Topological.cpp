#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;





bool detectCycleInDirectedGraph(int n , vector<pair<int , int>> &edges)
{
    // Create adj list
    unordered_map<int , list<int>> adj ;
    for (int i = 0 ; i < edges.size() ; i++)
    {
        int u = edges[i].first - 1 ;
        int v = edges[i].second - 1 ;

        adj[u].push_back(v) ;
    }


    // Find all indegrees
    vector<int> indegree(n) ;
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++ ;
        }
    }

    // 0 indegree wallo ko push kardo
    queue<int> q ;
    for (int i = 0 ; i < n ; i++)
    {
        if (indegree[i] == 0)
            q.push(i) ;
    }

    // Do bfs
    int cnt = 0 ;
    while(!q.empty())
    {
        int front = q.front() ;
        q.pop() ;

        cnt++ ;

        // Neighbour indegree update 
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]-- ;
            
            if (indegree[neighbour] == 0)
                q.push(neighbour) ;
        }
    }

    if (cnt == n)
        return false ;
    else 
        return true ;  

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