class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;
        if(n == 0)
            return 0;
        while(n != 0)
        {
            if((n&(n-1))==(n-1))
                counter++;
            n = n>>1;
        }
        return counter;
    }
};