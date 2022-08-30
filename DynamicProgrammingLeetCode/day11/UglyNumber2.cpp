class Solution {
public:
    
    int nthUglyNumber(int n) {
        vector<int>nums(1,1);
        vector<int>idx(3,0);
        vector<int>factors={2,3,5};
        unordered_map<int,int>factor = {{0,2},{1,3},{2,5}};
        int counter = 1;
        int least = 1;
        while(counter < n)
        {
            least = min(factors[0],min(factors[1],factors[2]));
            nums.push_back(least);
            for(int i=0; i<3; i++)
            {
                if(factors[i] == least)
                {
                    idx[i]++;
                    factors[i] = nums[idx[i]]*factor[i];
                }
            }
            counter++;
        }
        return least;
    }
};