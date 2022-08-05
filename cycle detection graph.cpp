// using bfs technique
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int idx,vector<int> adj[],vector<int>&visited){
        queue<pair<int,int>>q;
        q.push({idx,-1});
        visited[idx]=1;
        while(q.size()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto i:adj[node]){
                if(!visited[i]){
                    visited[i]=1;
                    q.push({i,node});
                }
                else if(parent!=i) return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(check(i,adj,visited)) return true;
            }
        }
        return false;
    }
};

//using dfs technique
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int idx,int prev,vector<int> adj[],vector<int>&visited){
         if(!visited[idx]) visited[idx]=1;
            for(auto i:adj[idx]){
                if(!visited[i]){
                    if(dfs(i,idx,adj,visited)) return true;
                }
                else if(prev!=i) return true;
            }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,adj,visited)) return true;
            }
        }
        return false;
    }
};
