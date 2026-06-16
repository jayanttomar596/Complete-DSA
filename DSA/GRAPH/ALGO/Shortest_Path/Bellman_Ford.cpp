#include <iostream>
#include <vector>
using namespace std;






// Time Complexity: O(n * m)
// Space Complexity: O(n + m)


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;


    // Run the relaxation step n-1 times
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }


    // Check for negative weight cycle
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
        {
            return -1; // Negative weight cycle detected
        }
    }

    return dist[dest];
}





int main() {


    int n = 5; // number of nodes
    int m = 7; // number of edges
    int src = 1;
    int dest = 5;


    // Each edge: {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 3, 2},
        {2, 3, 3},
        {2, 4, 2},
        {2, 5, 3},
        {3, 2, 1},
        {3, 4, 4}
    };


    int result = bellmonFord(n, m, src, dest, edges);


    if (result == -1)
    {
        cout << "Negative weight cycle detected.\n";
    }
    else if (result == INT_MAX)
    {
        cout << "Destination node is unreachable from the source.\n";
    }
    else
    {
        cout << "Shortest distance from node " << src << " to node " << dest << " is: " << result << endl;
    }

    
    return 0;
}



