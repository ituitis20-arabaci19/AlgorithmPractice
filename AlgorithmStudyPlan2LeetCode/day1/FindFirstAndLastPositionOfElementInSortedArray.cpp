class Solution {
public:
    vector<int>limits;
    vector<int> searchRange(vector<int>& nums, int target) {
        limits = vector<int>(2,-1);
        binarySearch(nums, target, 0, nums.size()-1);
        return limits;
    }
    void binarySearch(vector<int>& nums, int target, int left, int right)
    {
        if(left > right)
            return;
        int mid = (left+right)/2;
        if(nums[mid] > target)
            binarySearch(nums, target, left, mid-1);
        else if(nums[mid] < target)
            binarySearch(nums, target, mid+1, right);
        else
        {
            if(limits[0] == -1 && limits[1] == -1)
                limits = vector<int>(2,mid);
            else if(mid > limits[1])
                limits[1] = mid;
            else if(mid < limits[0])
                limits[0] = mid;
            binarySearch(nums, target, left, mid-1);
            binarySearch(nums, target, mid+1, right);
        }
    }
};