#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;




// T.C. -> O(N + E)
// S.C. -> O(N + E)


// n - nodes , m - edges , s - starting node , t - target node

vector<int> shortestPath(vector<pair<int,int>> edges , int n , int m , int s , int t)
{
    // Create Adjacency List
    unordered_map<int , list<int>> adj ;
    for (int i = 0 ; i < m ; i++)
    {
        int u = edges[i].first ;
        int v = edges[i].second ;

        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    // Do bfs 
    unordered_map<int , bool> visited ;
    unordered_map<int , int> parent ;
    queue<int> q ;
    q.push(s) ;
    parent[s] = -1 ;
    visited[s] = true ;

    while(!q.empty())
    {
        int front = q.front() ;
        q.pop() ;

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true ;
                parent[i] = front ;
                q.push(i) ;
            }
        }
    }

    // Prepare shortest path 
    vector<int>  ans ;
    int currentNode = t ;
    ans.push_back(t) ;

    while(currentNode != s)
    {
        currentNode = parent[currentNode] ;
        ans.push_back(currentNode) ;
    }

    reverse(ans.begin() , ans.end()) ;

    return ans ;
}





int main() {


    // Example graph:
    // 1 -- 2--5
    // |      /
    // 4 -- 3

    int n = 5; // number of nodes
    int m = 5; // number of edges
    vector<pair<int, int>> edges = {
        {1, 2},
        {3, 4},
        {4, 1},
        {2, 5},
        {5, 3}
    };

    int start = 1;
    int target = 3;

    vector<int> path = shortestPath(edges, n, m, start, target);

    if (path.empty())
    {
        cout << "No path found from " << start << " to " << target << endl;
    }
    else
    {
        cout << "Shortest path from " << start << " to " << target << ": ";
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    
    return 0;
}