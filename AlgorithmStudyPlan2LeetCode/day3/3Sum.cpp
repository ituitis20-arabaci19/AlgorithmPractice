class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int mid = 1;
        while(mid < nums.size()-1)
        {
            int left;
            if(nums[mid] == nums[mid-1])
                left = mid-1;
            else 
                left = 0; 
            int right = nums.size()-1;
            while(left < mid && mid < right)
            {
                int sum = nums[left]+nums[right]+nums[mid];
                if(sum < 0)
                    left++;
                else if(sum > 0)
                    right--;
                else 
                {
                    vector<int>cand = {nums[left], nums[mid], nums[right]};
                    int last = res.size()-1;
                    if(res.empty() || !(res[last][0]==cand[0] && res[last][1]==cand[1] && res[last][2]==cand[2]))
                        res.push_back(cand);
                    do
                    {
                        left++;
                        right--;
                    }while(left < mid && mid < right && nums[left]==nums[left-1] && nums[right]==nums[right+1]);   
                }                    
            }
            mid++;
        }
        return res;
    }
};
