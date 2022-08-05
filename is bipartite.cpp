// checking if a graph is bipartite is same as detecting a graph for cycles
// only difference is just maintain a color vector in place of visited
// unlike visited color will have 0, 1, -1, thats why extra condition on loc 7;
class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph, vector<int>&color){
        if(!color[node]) color[node]=1;
            for(auto it:graph[node]){
                if(!color[it]){
                    color[it]=-color[node];
                    if(!dfs(it,graph,color)) return false;
                }
                else if(color[it]==color[node]) return false;
            }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
       for(int i=0;i<n;i++){
           if(!dfs(i,graph,color)) return false;
       }
        return true;
    }
};
