class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int r=0; r<grid.size(); r++)
        {
            for(int c=0; c<grid[0].size(); c++)
            {
                if(grid[r][c] == 1)
                    maxArea = max(dfs(grid,r,c), maxArea);
                grid[r][c] == 2; //means this box is visited
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, int r, int c)
    {
        int size = 0;
        if(grid[r][c] != 1)
            return 0;
        size++;
        grid[r][c] = 2;
        if(r != 0)
            size += dfs(grid,r-1,c);
        if(r != grid.size()-1)
            size += dfs(grid,r+1,c);
        if(c != 0)
            size += dfs(grid,r,c-1);
        if(c != grid[0].size()-1)
            size += dfs(grid,r,c+1);
        return size;
    }
};