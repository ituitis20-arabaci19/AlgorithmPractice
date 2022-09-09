class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int biggest = nums[0], total = nums[0];
        int res = kadane(nums);
        nums[0] *= -1;
        for(int i=1; i<nums.size(); i++)
        { 
            biggest = max(biggest,nums[i]); 
            total += nums[i];
            nums[i] *= -1; 
        }
        if(biggest <= 0)
            return biggest;
        return max(res, total + kadane(nums));
        
    }
    int kadane(vector<int>& nums)
    {
        int localMax = nums[0], globalMax = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            localMax = max(nums[i]+localMax, nums[i]);
            globalMax = max(globalMax, localMax);
        }
        return globalMax;
    }
};