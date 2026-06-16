// DFS (Depth First Search)



 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;





// T.C. -> O(V+E)
// S.C. -> O(V+E)

class DFS
{
private :
    void dfs(int node , unordered_map<int , bool> &visited , unordered_map<int , list<int>> &adj , vector<int> &component)
    {
        // Ans Store
        component.push_back(node) ;

        // Mark Visited
        visited[node] = true ;

        // har connected node ke liye recursive call
        for (auto i : adj[node])
        {
            if(!visited[i])
            {
                dfs(i , visited , adj , component) ;
            }
        }
    }



public :
    vector<vector<int>> depthFirstSearch(int V , int E , vector<vector<int>> &edges)
    {
        // Prepare AdjList
        unordered_map<int , list<int>> adj ;
        for (int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0] ;
            int v = edges[i][1] ;

            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        vector<vector<int>> ans ;
        unordered_map<int , bool> visited ;

        // for all nodes call DFS , if not visited
        for (int i = 0 ; i < V ; i++)
        {
            if (!visited[i])
            {
                vector<int> component ;
                dfs(i , visited , adj , component) ;
                ans.push_back(component) ;
            }
        }

        return ans ;
    }

};





int main() {


    DFS graph;

    int V = 6;  // Number of nodes (0 to 5)
    int E = 4;  // Number of edges

    // Example: 2 components: {0,1,2} and {3,4}, and node 5 is isolated
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4},
        {2, 0}
    };

    vector<vector<int>> result = graph.depthFirstSearch(V, E, edges);

    cout << "Connected Components in the Graph:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int node : result[i]) {
            cout << node << " ";
        }
        cout << endl;
    }



    return 0;
}





/*



#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);

    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {4};

    cout << "DFS Traversal: ";
    dfs(0, adj, visited);
    return 0;
}



*/