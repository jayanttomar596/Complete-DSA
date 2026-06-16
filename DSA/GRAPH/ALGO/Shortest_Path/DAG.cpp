// Shortest Path in DAG(Directed Acyclic Graph)



#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
using namespace std;




// T.C. -> O(N+E)
// S.C. -> O(N+E)

class Graph
{
public :
    unordered_map<int , list<pair<int,int>>> adj ;


    void addEdge(int u , int v , int weight)
    {
        pair<int , int> p = make_pair(v , weight) ;
        adj[u].push_back(p) ;
    }


    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << " , " << j.second << ") , ";
            }
            cout << endl;
        }
    }


    void dfs(int node , unordered_map<int , bool> &vis , stack<int> &topo)
    {
        vis[node] = true ;

        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour.first])
            {
                dfs(neighbour.first , vis , topo) ;
            }
        }
        topo.push(node) ;
    }


    void getShortestPath(int src , vector<int> &dist , stack<int> &topo)
    {
        dist[src] = 0 ;

        while(!topo.empty())
        {
            int top = topo.top() ;
            topo.pop() ;

            if (dist[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second ;
                    }
                }
            }
        }
    }

};





int main() {

    Graph g ;
    g.addEdge(0,1,5) ;
    g.addEdge(0,2,3) ;
    g.addEdge(1,2,2) ;
    g.addEdge(1,3,6) ;
    g.addEdge(2,3,7) ;
    g.addEdge(2,4,4) ;
    g.addEdge(2,5,2) ;
    g.addEdge(3,4,-1) ;
    g.addEdge(4,5,-2) ;


    g.printAdj() ;


    int n = 6 ;
    // Topological sort
    unordered_map<int , bool> visited ;
    stack<int> s ;
    for (int i = 0 ; i < n ; i++)
    {
        if (!visited[i])
        {
            g.dfs(i , visited , s ) ;
        }
    }



    int src = 1 ;
    vector<int> dist(n) ;

    for (int i = 0 ; i < n ; i++)
    {
        dist[i] = INT_MAX ;
    }

    g.getShortestPath(src , dist , s) ;


    cout << "\nShortest Distance Vector : " << endl;

    for (int i = 0 ; i < dist.size() ; i++)
    {
        cout << dist[i] << " " ;
    }
    cout << endl << endl;
    

    return 0;
}









/* ChatGPT Solution Class



#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class Solution {
    unordered_map<int, list<pair<int, int>>> adj;

    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo) {
        vis[node] = true;
        for (auto neighbour : adj[node]) {
            if (!vis[neighbour.first]) {
                dfs(neighbour.first, vis, topo);
            }
        }
        topo.push(node);
    }

public:
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
    }

    void printAdj() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << "(" << j.first << " , " << j.second << ") , ";
            }
            cout << endl;
        }
    }

    vector<int> shortestPath(int n, int src) {
        // Topological sort
        unordered_map<int, bool> visited;
        stack<int> topo;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, topo);
            }
        }

        // Initialize distances
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!topo.empty()) {
            int top = topo.top();
            topo.pop();

            if (dist[top] != INT_MAX) {
                for (auto i : adj[top]) {
                    if (dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    Solution sol;
    sol.addEdge(0, 1, 5);
    sol.addEdge(0, 2, 3);
    sol.addEdge(1, 2, 2);
    sol.addEdge(1, 3, 6);
    sol.addEdge(2, 3, 7);
    sol.addEdge(2, 4, 4);
    sol.addEdge(2, 5, 2);
    sol.addEdge(3, 4, -1);
    sol.addEdge(4, 5, -2);

    sol.printAdj();

    int n = 6;
    int src = 1;

    vector<int> distances = sol.shortestPath(n, src);

    cout << "\nShortest Distance Vector from node " << src << ": " << endl;
    for (int d : distances) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}


*/





