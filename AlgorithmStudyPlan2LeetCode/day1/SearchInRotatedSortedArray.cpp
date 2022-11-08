class Solution {
public:
    int found;
    int search(vector<int>& nums, int target) {
        found = -1;
        binarySearch(nums, target, 0, nums.size()-1);
        return found;
    }
    void binarySearch(vector<int>& nums, int target, int left, int right)
    {
        if(left > right)
            return;
        int mid = (left+right)/2;
        if(target == nums[mid])
        {
            found = mid;
            return;
        }
        binarySearch(nums, target, left, mid-1);
        binarySearch(nums, target, mid+1, right);
    }
};