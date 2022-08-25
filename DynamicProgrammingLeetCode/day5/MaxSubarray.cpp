#include <iostream>
#include <vector>

using namespace std;

//Without Kadane's Algorithm
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], sum = nums[0];
        bool flag = false;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1]>0 && nums[i]<0 && sum<=0)
            {
                if(nums[i+1]>best)
                {
                    best = nums[i+1];
                    sum = nums[i+1];
                    flag = false;
                }
                else
                {
                    flag = true;
                    sum = nums[i+1];
                }
            }
            else if(nums[i+1]>0 && sum>=0)
            {
                if(flag)
                {
                    if(best>sum+nums[i+1])
                    {
                        sum += nums[i+1];
                    }
                    else
                    {
                        best = sum+nums[i+1];
                        sum += nums[i+1];
                        flag = false;
                    }
                }
                else
                {
                    best+=nums[i+1]; 
                    sum+=nums[i+1];
                }
            }
            else if(nums[i+1]<0)
            {
                if(nums[i+1] > best)
                {
                    best = nums[i+1];
                    sum = nums[i+1];
                }
                else
                {
                    flag = true;
                    sum += nums[i+1];
                }
            }
            else if(nums[i+1] == 0)
            {
                if(nums[i+1] > best)
                {
                    best = nums[i+1];
                    sum = nums[i+1];
                }
            }
            else continue;
        }
        return best;    
    }
};
*/

//Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prevMax = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            prevMax = max(nums[i]+prevMax, nums[i]);
            maxSum = max(maxSum, prevMax);
        }
        return maxSum;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> arr = {1,2,-1,-2,2,1,-2,1,4,-5,4};
    int counter = sol.maxSubArray(arr);
    cout << counter << endl;
}