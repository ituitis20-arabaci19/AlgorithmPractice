class Solution {
public:
    int peakIndex;
    int findPeakElement(vector<int>& nums) {
        binarySearch(nums, 0, nums.size()-1);
        return peakIndex;
    }
    void binarySearch(vector<int>& nums, int left, int right)
    {
        int mid = (left+right)/2;
        if(left>=right)
        {
            peakIndex = mid;
            return;
        }
        if(nums[mid]>nums[mid+1])
            binarySearch(nums, left, mid);
        else if(nums[mid]<nums[mid+1])
            binarySearch(nums, mid+1, right);
    }
};