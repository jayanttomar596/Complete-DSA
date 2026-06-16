// Articulation Point - Trajan's Algorithm


/*

You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.

Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.

*/




// Time Complexity	O(V + E)
// Space Complexity	O(V + E)


#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;



class Solution {
    void dfs(int node, int parent, vector<int> &disc, vector<int> &low,
             unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj,
             vector<int> &ap, int &timer) 
    {
                 
        vis[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;

        for (auto nbr : adj[node]) {
            if (nbr == parent) continue;

            if (!vis[nbr]) {
                dfs(nbr, node, disc, low, vis, adj, ap, timer);
                low[node] = min(low[node], low[nbr]);

                // Check for articulation point
                if (low[nbr] >= disc[node] && parent != -1) {
                    ap[node] = 1;
                }

                child++;
            } else {
                low[node] = min(low[node], disc[nbr]);
            }
        }

        // Special case for root node
        if (parent == -1 && child > 1) {
            ap[node] = 1;
        }

    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>> &edges) 
    {
        unordered_map<int, list<int>> adj;

        // Building the adjacency list
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int timer = 0;
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        unordered_map<int, bool> vis;
        vector<int> ap(V, 0);  // ap[i] = 1 if i is an articulation point

        // Run DFS for all disconnected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, disc, low, vis, adj, ap, timer);
            }
        }

        // Collect the articulation points
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (ap[i] == 1) {
                result.push_back(i);
            }
        }

        if (result.empty()) return {-1};
        return result;
        
    }
};






int main() {


// 🧪 Sample Input
/*
   Graph:
       1
      / \
     0   2
      \ /
       3

   Articulation Point: 0 and 1
*/
    
    // int V = 4;
    // vector<vector<int>> edges = {
    //     {0, 1},
    //     {1, 2},
    //     {2, 3},
    //     {3, 0}
    // };

    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };


    Solution obj;
    vector<int> ans = obj.articulationPoints(V, edges);

    cout << "Articulation Points: ";
    for (int point : ans) {
        cout << point << " ";
    }
    cout << endl;

    
    return 0;
}