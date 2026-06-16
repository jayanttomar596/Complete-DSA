// Minimum Spanning Tree || Prim's Algorithm





#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;





vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adj list
    unordered_map<int , list<pair<int,int>>> adj ;

    /*
    g format -> ({u , v} , w)
    */

    for (int i = 0 ; i < g.size() ; i++)
    {
        int u = g[i].first.first ;
        int v = g[i].first.second ;
        int w = g[i].second ;

        adj[u].push_back(make_pair(v,w)) ;
        adj[v].push_back(make_pair(u,w)) ;
    }

    vector<int> key(n+1 , INT_MAX) ;
    vector<bool> mst(n+1 , false) ;
    vector<int> parent(n+1 , -1) ;

    // Let's start the algo
    key[1] = 0 ;
    parent[1] = -1 ;

    for (int i = 1 ; i < n ; i++)
    {
        int mini = INT_MAX ;
        int u ;
        
        // find the min wali node
        for (int v = 1 ; v <= n ; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v ;
                mini = key[v] ;
            }
        }

        // Mark min node as true ;
        mst[u] = true ;

        // Check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first ;
            int w = it.second ;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u ;
                key[v] = w ;
            }
        }
    }

    vector<pair<pair<int , int> , int>> result ;
    for (int i = 2 ; i <= n ; i++)
    {
        result.push_back({{parent[i] , i} , key[i]}) ;
    }
    
    return result ;
}





int main() {

    int n = 5; // Number of nodes
    int m = 6; // Number of edges

    // Edges: ({u, v}, w)
    vector<pair<pair<int, int>, int>> g = {
        {{1, 2}, 2},
        {{1, 3}, 3},
        {{2, 3}, 1},
        {{2, 4}, 4},
        {{3, 5}, 5},
        {{4, 5}, 7}
    };

    vector<pair<pair<int, int>, int>> mst = calculatePrimsMST(n, m, g);

    cout << "Edges in MST:\n";
    int totalWeight = 0;
    for (auto edge : mst)
    {
        cout << edge.first.first << " - " << edge.first.second << " with weight " << edge.second << endl;
        totalWeight += edge.second;
    }

    cout << "Total Weight of MST: " << totalWeight << endl;
    
    return 0;
}








