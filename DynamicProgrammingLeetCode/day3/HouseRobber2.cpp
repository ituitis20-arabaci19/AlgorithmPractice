#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
       return max(robHood(nums,0), robHood(nums,1));
    }
    int robHood(vector<int>& nums, int mode)
    {
        int n = nums.size()-1;
        if(n == 1)
            return nums[mode];
        vector<int>moneys(n,-1);
        for(int i=n-1; i>=0; i--)
        {
            if(i==n-1 || i+1==n-1)
                moneys[i] = nums[i+mode];
            else if(i+2==n-1)
                moneys[i] = nums[i+mode] + moneys[i+2];
            else
                moneys[i] = nums[i+mode] + max(moneys[i+2], moneys[i+3]);
        }
        return max(moneys[0], moneys[1]);
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> cost = {1,2,3,1,4,5};
    int counter = sol.rob(cost); 
    cout << counter << endl;
}