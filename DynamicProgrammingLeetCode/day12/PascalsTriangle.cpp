class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int left = 0;
        vector<vector<int>>res;
        for(int i=1; i<=numRows; i++)
        {
            vector<int>row(i,1);
            left = 1;
            int it = max(i-2,0);
            while(it--)
            {
                row[left] = res[res.size()-1][left-1]+res[res.size()-1][left];
                left++;
            }
            res.push_back(row);
        }
        return res;
    }
};