class Solution {
public:
    int smallest;
    int findMin(vector<int>& nums) {
        smallest = -1;
        binarySearch(nums, 0, nums.size()-1);
        return smallest;
    }
    void binarySearch(vector<int>& nums, int left, int right)
    {
        int mid = (right+left)/2;
        if(right - left <= 2)
        {
            smallest = min(nums[left], min(nums[right], nums[mid]));
            return;
        }
        if(nums[right] < nums[mid])
            binarySearch(nums, mid, right);
        else
            binarySearch(nums, left, mid);  
    }
};