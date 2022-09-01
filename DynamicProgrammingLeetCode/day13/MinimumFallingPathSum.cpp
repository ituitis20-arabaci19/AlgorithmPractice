class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minRes = INT32_MAX;
        for(int r=matrix.size()-2; r>=0; r--)
        {
            for(int c=0; c<matrix[0].size(); c++)
            {
                vector<int>candidates = {matrix[r+1][c], INT32_MAX, INT32_MAX};
                if(c!=0)
                    candidates[1] = matrix[r+1][c-1];
                if(c!=matrix[0].size()-1)
                    candidates[2] = matrix[r+1][c+1];
                matrix[r][c] += min(candidates[0], min(candidates[1], candidates[2]));
            }
        }
        for(int i=0; i<matrix[0].size(); i++)
            minRes = min(minRes, matrix[0][i]);
        return minRes;
    }
};