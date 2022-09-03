class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> sums = mat;
        pair<int,int> topLeft, bottomRight;
        int boxSum;
        for(int r=0; r<mat.size(); r++)
        {
            for(int c=0; c<mat[0].size(); c++)
            {
                if(c==0 && r==0) continue;
                if(c>0) sums[r][c] += sums[r][c-1];
                if(r>0) sums[r][c] += sums[r-1][c];
                if(r>0 && c>0) sums[r][c] -= sums[r-1][c-1];
            }
        }
        vector<vector<int>> res(mat.size(),vector<int>(mat[0].size(),0));
        for(int r=0; r<mat.size(); r++)
        {
            for(int c=0; c<mat[0].size(); c++)
            {
                int r_max = mat.size();
                int c_max = mat[0].size();
                bottomRight = {min(r_max-1, r+k), min(c_max-1, c+k)};
                boxSum = sums[bottomRight.first][bottomRight.second];
                
                topLeft.first = max(0, r-k);
                topLeft.second = max(0, c-k);
                
                if(topLeft.first > 0)
                    boxSum -= sums[topLeft.first-1][bottomRight.second];
                if(topLeft.second > 0)
                    boxSum -= sums[bottomRight.first][topLeft.second-1];
                if(topLeft.first > 0 && topLeft.second > 0)
                    boxSum += sums[topLeft.first-1][topLeft.second-1];
                res[r][c] = boxSum;            
            }
        }
        return res;        
    }
};