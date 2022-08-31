class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>perms;
        vector<int>onePerm(nums.size(),-11);
        perm(perms,onePerm,-11,nums,0);
        return perms;
    }
    void perm(vector<vector<int>>&perms, vector<int>onePerm, int n, vector<int>&nums, int k)
    {
        if(k == nums.size())
        {
            perms.push_back(onePerm);
            return;
        }
        for(int num : nums)
        {
            if(find(onePerm.begin(), onePerm.end(), num) != onePerm.end()) continue;
            onePerm[k] = num;
            perm(perms, onePerm, num, nums, k+1);
        }
    }
};