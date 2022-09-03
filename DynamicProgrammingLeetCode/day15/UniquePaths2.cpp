class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>pathCount(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        for(int i=0; i<obstacleGrid.size(); i++)
        {
            for(int k=0; k<obstacleGrid[0].size(); k++)
            {
                if(i==0 && k==0 && obstacleGrid[i][k] == 0)
                    pathCount[i][k] = 1;
                else
                {
                    if(k>0 && obstacleGrid[i][k] == 0)
                    pathCount[i][k] += pathCount[i][k-1];
                    if(i>0 && obstacleGrid[i][k] == 0)
                        pathCount[i][k] += pathCount[i-1][k];
                }                
            }
        }
        return pathCount[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};