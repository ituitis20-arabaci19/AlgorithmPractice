class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int r=grid.size()-1; r>=0; r--)
        {
            for(int c=grid[r].size()-1; c>=0; c--)
            {
                if(c==grid[r].size()-1 && r==grid.size()-1)
                    continue;
                int choice = INT32_MAX;
                if(c<grid[r].size()-1)
                    choice = min(choice, grid[r][c+1]);
                if(r<grid.size()-1)
                    choice = min(choice, grid[r+1][c]);
                grid[r][c] += choice;
            }
        }
        return grid[0][0];
    }
};