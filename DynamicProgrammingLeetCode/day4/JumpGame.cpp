#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastLimitIdx = -1;
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(nums[i] == 0 && lastLimitIdx == -1 && i != nums.size()-1)
            {   
                lastLimitIdx = i; 
                continue;
            }
            if(lastLimitIdx != -1)
            {
                 if(nums[i] + i > lastLimitIdx)
                     lastLimitIdx = -1;
            }
        }
        return lastLimitIdx == -1 ? true : false;  
    }
};
int main()
{   
    Solution sol = Solution();
    vector<int> cost = {3,2,1,0,4};
    int counter = sol.canJump(cost); 
    cout << counter << endl;
}