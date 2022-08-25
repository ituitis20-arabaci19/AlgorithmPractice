#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], minProduct = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            int num = nums[i];
            if(num < 0)
                swap(minProduct, maxProduct);
            minProduct = min(minProduct*num, num);
            maxProduct = max(maxProduct*num, num);
            res = max(maxProduct, res);
        }
        return res;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> arr = {0,1,-2,-3,-4};
    int counter = sol.maxProduct(arr);
    cout << counter << endl;
}