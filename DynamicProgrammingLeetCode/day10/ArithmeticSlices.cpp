class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int lastEnd = 0, lastDiff = 0;
        vector<bool>isArithmetic(nums.size(),false);
        vector<int>arithmeticCount(nums.size(),0);  
        for(int i=nums.size()-3; i>=0; i--)
        {
            if(!isArithmetic[i+1])
            {
                lastDiff = nums[i+1]-nums[i];
                if(nums[i+2]-nums[i+1] == lastDiff)
                {
                    isArithmetic[i] = true;
                    arithmeticCount[i] += arithmeticCount[i+1]+1;
                    lastEnd = i+2;
                }
                else
                    arithmeticCount[i] = arithmeticCount[i+1];
            }   
            else
            {
                if(nums[i+1]-nums[i] == lastDiff)
                {
                    isArithmetic[i] = true;
                    arithmeticCount[i] += arithmeticCount[i+1]+(lastEnd-i-1);
                }
                else
                    arithmeticCount[i] = arithmeticCount[i+1];
            }
        }
        return arithmeticCount[0];
    }
};