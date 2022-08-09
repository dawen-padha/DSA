// topo sort using bfs
// here we maintained an indegree array, which stores the indegree of each vertex
// we used a queue and stored vertices in it acc. to the indegrees with the minimum first
// whenever we go the neighbour of a vertex, we decrease the indegree by one and check if it equals to 0
// if it equals to 0 , then we insert it in queue and do so until the queue is empty.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   queue<int> q;
	   vector<int> indegree(V,0);
	   for(int i=0;i<V;i++){
	       for(auto it:adj[i]){
	           indegree[it]++;
	       }
	   }
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0) q.push(i);
	   }
	   vector<int> v;
	   while(q.size()){
	       int node=q.front();
	       q.pop();
	       v.push_back(node);
	       for(auto it:adj[node]){
	           indegree[it]--;
	           if(!indegree[it]) q.push(it);
	       }
	   }
	   return v;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends

// depth first search approach 
//
//
//
//
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(stack<int>&s, vector<bool>&visited, vector<int> adj[],int idx){
             visited[idx]=1;
            for(auto i:adj[idx]){
                if(!visited[i]){
                    dfs(s,visited,adj,i);
                }
            }
            s.push(idx);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    stack<int> s;
	    vector<bool> visited(V,0);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            dfs(s,visited,adj,i);
	        }
	    }
	    vector<int> v;
	    while(s.size()){
	        v.push_back(s.top());
	        s.pop();
	    }
	    return v;
	}
};
