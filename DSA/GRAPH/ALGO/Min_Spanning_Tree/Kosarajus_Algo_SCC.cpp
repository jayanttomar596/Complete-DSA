#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;






// T.C. -> 	O(V + E)
// S.C  -> 	O(V + E)

class SCC
{

private :
    void dfs(int node , unordered_map<int , bool> &vis , stack<int> &st , unordered_map<int , list<int>> &adj)
    {
        vis[node] = true ;
        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                dfs(nbr , vis , st , adj) ;
            }
        }

        // Topo Logic
        st.push(node) ;
    }


    void revDfs(int node , unordered_map<int , bool> &vis , unordered_map<int , list<int>> &adj)
    {
        vis[node] = true ;

        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                revDfs(nbr , vis , adj) ;
            }
        }
    }
    

public :
    int stronglyConnectedComponents(int v , vector<vector<int>> &edges)
    {
        // adj
        unordered_map<int , list<int>> adj ;
        for (int i = 0 ; i < edges.size() ; i++)
        {
            int u = edges[i][0] ;
            int v = edges[i][1] ;

            adj[u].push_back(v) ;
        }


        // Topo Sort
        stack<int> st ;
        unordered_map<int , bool> vis ;
        for (int i = 0 ; i < v ; i++)
        {
            if (!vis[i])
            {
                dfs(i , vis , st , adj) ;
            }
        }


        // Create a transpose graph
        unordered_map<int , list<int>> transpose ;
        for (int i = 0 ; i < v ; i++)
        {
            vis[i] = 0 ;
            for (auto nbr : adj[i])
            {
                transpose[nbr].push_back(i) ;
            }
        }


        // DFS call suing above ordering 
        int count = 0 ;
        while(!st.empty())
        {
            int top = st.top() ;
            st.pop() ;
            if (!vis[top])
            {
                count++ ;
                revDfs(top , vis , transpose) ;
            }
        }

        return count ;
    }

};






int main() {


    // Number of nodes
    int V = 5;


    // Edges of the directed graph
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},  
        {2, 0},
        {1, 3},
        {3, 4}
    };


    SCC sccFinder;
    int numSCC = sccFinder.stronglyConnectedComponents(V, edges);

    cout << "\nTotal number of SCCs: " << numSCC << endl;
    
    return 0;
}