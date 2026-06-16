#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;





// Time Complexity: O(V + E)
// Space Complexity: O(V + E)


void topoSort(int node , unordered_map<int , bool> &visited , stack<int> &s , unordered_map<int , list<int>> &adj)
{
    visited[node] = 1 ;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
            topoSort(neighbour , visited , s , adj) ;
    }

    // Imp
    s.push(node) ;
}




vector<int> topologicalSort(vector<vector<int>> &edges , int v , int e)
{
    // Create adj list
    unordered_map<int , list<int>> adj ;
    for (int i = 0 ; i < e ; i++)
    {
        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj[u].push_back(v) ;
    }


    // Call dfs toplogical sort util function for all components
    unordered_map<int , bool> visited ;
    stack<int> s ;
    for (int i = 0 ; i < v ; i++)
    {
        if (!visited[i])
        {
            topoSort(i , visited , s , adj) ;
        }
    }

    vector<int> ans ;

    while (!s.empty())
    {
        ans.push_back(s.top()) ;
        s.pop() ;
    }

    return ans ;
}





int main() {


    // Sample Input:
    // 6 nodes (0 to 5), 6 edges
    int v = 6, e = 6;
    vector<vector<int>> edges = {
        {5, 0},
        {5, 2},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = topologicalSort(edges, v, e);

    cout << "\nTopological Sort Order: ";
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl << endl;


    // Output : 5 4 2 3 1 0 
    
    return 0;
}