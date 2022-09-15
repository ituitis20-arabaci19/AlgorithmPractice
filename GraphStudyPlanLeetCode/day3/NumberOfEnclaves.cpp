class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid[0].size(),false));
        int totalLandCount = 0, visitedLandCount = 0;
        for(int r=0; r<grid.size(); r++)
        {
            for(int c=0; c<grid[0].size(); c++)
            {
                if(grid[r][c] == 1 && visited[r][c] == false && (r==0 || r==grid.size()-1 || c==0 || c==grid[0].size()-1))
                    visitedLandCount += dfs(grid, visited, r, c);
                if(grid[r][c] == 1)
                    totalLandCount++;
            }
        }
        return totalLandCount - visitedLandCount;
    }
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c)
    {
        int visitedLands = 1;
        visited[r][c] = true;
        
        if(r > 0 && grid[r-1][c]==1 && visited[r-1][c]==false)
            visitedLands += dfs(grid, visited, r-1, c);
        if(r < grid.size()-1 && grid[r+1][c]==1 && visited[r+1][c]==false)
            visitedLands += dfs(grid, visited, r+1, c);
        if(c > 0 && grid[r][c-1]==1 && visited[r][c-1]==false)
            visitedLands += dfs(grid, visited, r, c-1);
        if(c < grid[0].size()-1 && grid[r][c+1]==1 && visited[r][c+1]==false)
            visitedLands += dfs(grid, visited, r, c+1);
        
        return visitedLands;
    }
};