class Solution {
public:
    int numTrees(int n) {
        vector<int>treeCounts(n+1,0);
        treeCounts[0] = 1;
        treeCounts[1] = 1;
        for(int i=2; i<=n; i++)
        {
            for(int k=0; k<i; k++)
                treeCounts[i] += treeCounts[k]*treeCounts[i-k-1];
        }
        return treeCounts[n];
    }
};