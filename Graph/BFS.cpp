// TC : (V + 2E)
// SC : V



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Your BFS function
void BFS(int V, vector<int> adj[]) {
    vector<bool> visited(V, 0);
    // vector<int> ans;
    queue<int> q;

    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        // ans.push_back(node);
        cout<<node<<" ";

        for(int j = 0; j < adj[node].size(); j++) {
            if(!visited[adj[node][j]]) {
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
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

    

    BFS(V, adj);

   
    return 0;
}
