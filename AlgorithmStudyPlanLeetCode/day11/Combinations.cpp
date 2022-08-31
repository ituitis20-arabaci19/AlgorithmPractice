class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>nums(k,0);
        comb(n, k, res, nums, 1);
        return res;
    }
    void comb(int n, int k, vector<vector<int>>&res, vector<int>nums, int start)
    {
        if(k == 0)
        {
            res.push_back(nums);
            return;
        }
        for(int i=start; i<=n; i++)
        {
            nums[nums.size()-k] = i;
            comb(n, k-1, res, nums, i+1);
        }
    }
};