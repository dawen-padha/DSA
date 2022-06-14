// code for bfs traversal using adjacency list




#include<bits/stdc++.h>
using namespace std;
void bfsofGraph(int V, vector<int> adj[],vector<bool> &visited,int se) {
       queue<int> q;
        visited[se] = true;
        q.push(se);
        while(!q.empty()){
            int u=q.front();
            q.pop();
           cout<<u<<" ";
            sort(adj[u].begin(),adj[u].end());
            for(int i:adj[u]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
// { Driver Code Starts.
int main() {
        int V, E;
        cin >> V >>E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            // 		adj[v].push_back(u);
        }
     vector<bool> visited(V,0);
       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           {
               bfsofGraph(V,adj,visited,i);
           }
       }
    return 0;
}  
