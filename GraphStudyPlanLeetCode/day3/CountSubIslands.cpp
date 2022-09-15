class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<bool>>visited(grid1.size(),vector<bool>(grid1[0].size(),false));
        int count = 0;
        for(int r=0; r<grid2.size(); r++)
        {
            for(int c=0; c<grid2[0].size(); c++)
            {
                if(!visited[r][c] && grid2[r][c] == 1)
                    count += dfs(grid1, grid2, visited, r, c);
            }
        }
        return count;
    }
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int r, int c)
    {
        visited[r][c] = true;
        bool temp;
        bool comp = grid1[r][c]==1;
        if(r>0 && grid2[r-1][c]==1 && !visited[r-1][c])
        {
            temp = dfs(grid1, grid2, visited, r-1, c);
            comp = comp == true ? temp : false;
        }
        if(r<grid2.size()-1 && grid2[r+1][c]==1 && !visited[r+1][c])
        {
            temp = dfs(grid1, grid2, visited, r+1, c);
            comp = comp == true ? temp : false;
        }
        if(c>0 && grid2[r][c-1]==1 && !visited[r][c-1])
        {
            temp = dfs(grid1, grid2, visited, r, c-1);
            comp = comp == true ? temp : false;
        }
        if(c<grid2[0].size()-1 && grid2[r][c+1]==1 && !visited[r][c+1])
        {
            temp = dfs(grid1, grid2, visited, r, c+1);
            comp = comp == true ? temp : false;
        }
        return comp;
    }
};