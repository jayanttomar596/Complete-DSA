#include <bits/stdc++.h>
using namespace std;

#define INF 99999 // Large value to denote no direct edge

void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++) { // Intermediate vertex
        for (int i = 0; i < n; i++) { // Source
            for (int j = 0; j < n; j++) { // Destination
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Detect Negative Weight Cycle
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            cout << "⚠ Negative Weight Cycle Detected\n";
            return;
        }
    }

    // Print Output
    cout << "\nAll-Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    
    cout << "Enter adjacency matrix (INF for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string val;
            cin >> val;
            if (val == "INF")
                graph[i][j] = INF;
            else
                graph[i][j] = stoi(val);
        }
    }

    floydWarshall(graph, n);
    return 0;
}
