#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;




// T.C. -> O(N+E)
// S.C. -> O(N+E)

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


    // Find all indegrees
    vector<int> indegree(v) ;
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++ ;
        }
    }

    // 0 indegree wallo ko push kardo
    queue<int> q ;
    for (int i = 0 ; i < v ; i++)
    {
        if (indegree[i] == 0)
            q.push(i) ;
    }

    // Do bfs
    vector<int> ans ;
    while(!q.empty())
    {
        int front = q.front() ;
        q.pop() ;

        // Ans store
        ans.push_back(front) ;

        // Neighbour indegree update 
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]-- ;
            
            if (indegree[neighbour] == 0)
                q.push(neighbour) ;
        }
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