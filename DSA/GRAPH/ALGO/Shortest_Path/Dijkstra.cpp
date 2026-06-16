#include <iostream>
#include <list>
#include <set>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;






// Using Set

// Time = O((V + E) * log V)
// Space = O(V + E)


vector<int> dijkstra(vector<vector<int>> &vec , int vertices , int edges , int source)
{
    // Create adjacency list
    unordered_map<int , list<pair<int , int>>> adj ;
    for (int i = 0 ; i < edges ; i++)
    {
        int u = vec[i][0] ;
        int v = vec[i][1] ;
        int w = vec[i][2] ;

        adj[u].push_back(make_pair(v , w)) ;
        adj[v].push_back(make_pair(u , w)) ;
    }


    // Creation of distance array with infinite value initially
    vector<int> dist(vertices) ;
    for (int i = 0 ; i < vertices ; i++)
        dist[i] = INT_MAX ;


    // Creation of set on basis (distance , node) 
    set<pair<int , int>> st ;


    // Initialize distance and set with source node
    dist[source] = 0 ;
    st.insert(make_pair(0,source)) ;


    while(!st.empty())
    {
        // fetch top record
        auto top = *(st.begin()) ;

        int nodeDistance = top.first ;
        int topNode = top.second ;

        // Remove top record now
        st.erase(st.begin()) ;

        // Traverse on neighbours
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first] , neighbour.first)) ;
                if (record != st.end())
                {
                    st.erase(record) ;
                }


                // Distance update
                dist[neighbour.first] = nodeDistance + neighbour.second ;

                // Record push in set
                st.insert(make_pair(dist[neighbour.first] , neighbour.first)) ;
            }
        }
    }

    return dist ;
}







// Using Priority_Queue

// Time = O(E * log V)
// Space = O(V + E)


vector<int> Dijkstra(vector<vector<int>> &vec , int vertices , int edges , int source)
{
    // Create adjacency list
    unordered_map<int , list<pair<int , int>>> adj ;
    for (int i = 0 ; i < edges ; i++)
    {
        int u = vec[i][0] ;
        int v = vec[i][1] ;
        int w = vec[i][2] ;

        adj[u].push_back(make_pair(v , w)) ;
        adj[v].push_back(make_pair(u , w)) ;
    }


    // Creation of distance array with infinite value initially
    vector<int> dist(vertices) ;
    for (int i = 0 ; i < vertices ; i++)
        dist[i] = INT_MAX ;


    // Creation of priority_queue on basis (distance , node) 
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;


    // Initialize distance and set with source node
    dist[source] = 0 ;
    pq.push({0,source}) ;


    while(!pq.empty())
    {
        int dis = pq.top().first ;
        int node = pq.top().second ;
        pq.pop() ;

        for (auto it : adj[node])
        {
            int edgeWeight = it.second ;
            int adjNode = it.first ;

            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight ;
                pq.push({dist[adjNode] , adjNode}) ;
            }
        }
    }

    return dist ;
}





int main() {

    // Example graph
    /*
        0 --(4)-- 1
        |       / |
       (1)   (3) (2)
        |   /     |
        2 ------- 3
    */

    int vertices = 4;
    int edges = 5;
    int source = 0;

    vector<vector<int>> edgesList = {
        {0, 1, 4},
        {0, 2, 1},
        {1, 2, 3},
        {1, 3, 2},
        {2, 3, 5}
    };

    vector<int> result = dijkstra(edgesList, vertices, edges, source);

    cout << "\nShortest distances from source node " << source << ":\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Node " << i << " : " << result[i] << endl;
    }
    
    
    return 0;
}