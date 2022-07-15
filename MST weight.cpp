// program to return weight of MST




typedef pair<int, int> p;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> distance(v,INT_MAX);
        vector<bool>visited(v,false);
        
        key[0]=0;
        
        priority_queue< p, vector <p> , greater<p> > pq;
        
        pq.push({0,0});
        
        while (!pq.empty())
        {
            int u = pq.top().second;
            
            pq.pop();
            
            visited[u]=true;
            
            for (auto it:adj[u])
            {
                int x = it[0];
                int weight = it[1];
                
                if (visited[x]==false && weight<distance[x])
                {
                    distance[x] = weight;
                    pq.push({weight, x});
                }
            }
        }

        return accumulate(distance.begin(), distance.end(), 0);
    }
};
