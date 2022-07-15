
//this is a bfs approach of getting max area
//using queue
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ma=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    ma=max(ma,bfs(grid,row,col,i,j));
                }
            }
        }
        return ma;
    }
    int bfs(vector<vector<int>>& grid,int m,int n,int row,int col){
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col]=0;
        int area=1;
         vector<int> directions({-1,0,1,0,-1});
        while(q.size()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newrow=r+directions[i],newcol=c+directions[i+1];
                if(newrow>=0&&newrow<m&&newcol<n&&newcol>=0&&grid[newrow][newcol]==1){
                    grid[newrow][newcol]=0;
                    area++;
                    q.push({newrow,newcol});
                }
            }
        }
        return area;
    }
};
// another approach using dfs, which works using recursion , while bfs works with queue
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (grid[i][j] == 1) ans = max(ans, dfs(grid, i, j));
        return ans;
    }
private:
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int m = grid.size(), n = grid[0].size(), area = 1;
        grid[row][col] = 2;
        vector<int> dir({-1,0,1,0,-1});
        for (int i = 0; i < 4; i++) {
            int r = row+dir[i], c = col+dir[i+1];
            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
                area += dfs(grid, r, c);
        }
        return area;
    }
};
