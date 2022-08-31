class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int left = 0;
        vector<int>res;
        for(int i=1; i<=rowIndex+1; i++)
        {
            vector<int>row(i,1);
            left = 1;
            int it = max(i-2,0);
            while(it--)
            {
                row[left] = res[left-1]+res[left];
                left++;
            }
            res = row;
        }
        return res;
    }
};