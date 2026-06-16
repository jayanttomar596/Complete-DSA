// BFS (Breadth First Search)




#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;





// T.C. -> O(M+N)
// S.C. -> O(M+N)

class BFS_Graph
{

private :
    void prepareAdjList(unordered_map<int , list<int>> &adjList , vector<pair<int , int>> &edges) 
    {
        for (int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i].first ;
            int v = edges[i].second ;

            adjList[u].push_back(v) ;
            adjList[v].push_back(u) ;
        }     
    }


    void bfs(unordered_map<int,list<int>> &adjList , unordered_map<int , bool> &visited , vector<int> &ans , int node)
    {

        queue<int> q ;
        q.push(node) ;
        visited[node] = 1 ;

        while(!q.empty())
        {
            int frontNode = q.front() ;
            q.pop() ;

            // Store frontNode into ans 
            ans.push_back(frontNode) ;

            // Traverse all neighbours of frontnode
            for (auto i : adjList[frontNode])
            {
                if (!visited[i])
                {
                    q.push(i) ;
                    visited[i] = 1 ;
                }
            }
        }
    }


public :
    
    vector<int> BFS(int vertex , vector<pair<int , int>> edges)
    {
        unordered_map<int , list<int>> adjList ;
        vector<int> ans ;
        unordered_map<int , bool> visited ;

        prepareAdjList(adjList , edges) ;

        // Traverse all components of a graph
        for (int i = 0 ; i < vertex ; i++)
        {
            if (!visited[i])
            {
                bfs(adjList , visited , ans , i) ;
            }
        }

        return ans ;
    }
};






int main() {


    // Number of vertices in the graph
    int vertex = 7;

    // Edges in the graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {4, 5},
        {5, 6}
    };

    // Create an object of BFS_Graph
    BFS_Graph g;

    // Call the BFS function
    vector<int> traversal = g.BFS(vertex, edges);

    // Print the BFS traversal
    cout << "BFS Traversal: ";
    for (int node : traversal)
    {
        cout << node << " ";
    }
    cout << endl;



/*
    
🧭 Step-by-Step Traversal
1. Start with Node 0
Queue: [0] → visit 0

Visit neighbors: 1, 2

Queue: [1, 2] → visit 1

Visit 1’s neighbor: 3 (0 already visited)

Queue: [2, 3] → visit 2 (no unvisited neighbors)

Queue: [3] → visit 3 (no unvisited neighbors)

Queue empty

Visited so far: 0 1 2 3

2. Check Nodes 1–3
Already visited → skip.

3. Node 4 is unvisited
Queue: [4] → visit 4

Visit 4’s neighbor: 5

Queue: [5] → visit 5

Visit 5’s neighbor: 6

Queue: [6] → visit 6

Queue empty

Visited now: 4 5 6


    
    */
    

    return 0;
}




/* If AdjList Given



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {4};

    cout << "BFS Traversal: ";
    bfs(0, adj, visited);
    return 0;
}



*/