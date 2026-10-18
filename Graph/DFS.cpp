#include <iostream>
#include <vector>

using namespace std;

void DFS(int node, vector<int> adj[], vector<int>& visited) {
    visited[node] = 1;
    cout << node << " ";

    for (int j = 0; j < adj[node].size(); j++) {
        int neighbor = adj[node][j];
        
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited); 
        }
    }
}

int main() {
    int V = 5; 
    vector<int> adj[V];

    
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    
    adj[1].push_back(0);
    adj[1].push_back(3);
    
    adj[2].push_back(0);
    adj[2].push_back(4);
    
    adj[3].push_back(1);
    adj[4].push_back(2);

    vector<int> visited(V, 0);

    cout << "DFS Traversal starting from node 0: " << endl;
    
    DFS(0, adj, visited); 

    cout << endl;
    return 0;
}
