class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<int,int>>bfsQueue;
        int remaining = 0;
        for(int r=0; r<grid.size(); r++)
        {
            for(int c=0; c<grid[0].size(); c++)
            {
                if(grid[r][c] == 1)
                    remaining++;
                else if(grid[r][c] == 2)
                {
                    bfsQueue.push(pair<int,int>(r,c));
                    visited[r][c] = true;
                }
            }
        }
        if(remaining==0)
            return 0;
        int time = 0;
        while(!bfsQueue.empty())
        {
            vector<pair<int,int>>currRottens;
            while(!bfsQueue.empty())
            {
                currRottens.push_back(bfsQueue.front());
                bfsQueue.pop();
            }
            time++;
            for(pair<int,int> p : currRottens)
            {
                int r = p.first;
                int c = p.second;
                int newRow, newCol;
                grid[r][c]==2;
                vector<vector<int>>nextDir = {{-1,0},{1,0},{0,-1},{0,1}};
                for(vector<int> direction : nextDir)
                {
                    newRow = r+direction[0];
                    newCol = c+direction[1];
                    if(!(newRow>=0 && newRow<=grid.size()-1 && newCol>=0 &&                                                                                         newCol<=grid[0].size()-1))
                        continue;
                    
                    if(!visited[newRow][newCol] && grid[newRow][newCol]==1)
                    {
                        bfsQueue.push(pair<int,int>(newRow,newCol));
                        visited[newRow][newCol] = true;
                        remaining--;
                    }
                }
            }
        }
        if(remaining)
            return -1;
        return time-1;
    }
};