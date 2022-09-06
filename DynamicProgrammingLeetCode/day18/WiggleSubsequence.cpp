class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int numSize = nums.size();
        int count = 1;
        bool firstFound = false;
        if(numSize == 1)
            return count;
        if(nums[1]!=nums[0])
        {
            firstFound = true;
            count++;
        }
        bool lastDiff = nums[1]>nums[0]; //true : positive, false : negative
        for(int i=1; i<=numSize-2; i++)
        {
            if((nums[i+1]>nums[i] != lastDiff || !firstFound) && nums[i+1]!=nums[i])
            {
                firstFound = true;
                lastDiff = nums[i+1]>nums[i];
                count++;
            }
        }
        return count;
    }
};