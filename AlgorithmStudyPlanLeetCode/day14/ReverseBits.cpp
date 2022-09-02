class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int bitCount = 32;
        if(n==0)
            return 0;
        while(true)
        {
            if( (n&(n-1)) == n-1)
                res++;
            n = n>>1;
            bitCount--;
            if(n<=0)
                break;
            res = res<<1;     
        }
        res <<= bitCount;
        return res;
    }
};