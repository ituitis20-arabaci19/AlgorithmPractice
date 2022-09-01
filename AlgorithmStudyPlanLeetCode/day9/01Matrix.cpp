#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(),20002));
        
        for(int c=0; c<mat[0].size(); c++)
        {
            for(int r=0; r<mat.size(); r++)
            {
                iterate(mat, dist, r, c);
            }
        }
        for(int c=mat[0].size()-1; c>=0; c--)
        {
            for(int r=mat.size()-1; r>=0; r--)
            {
                iterate(mat, dist, r, c);
            }
        }
        return dist;
    }
    void iterate(vector<vector<int>>& mat, vector<vector<int>>&dist, int r, int c)
    {
        if(mat[r][c] == 0)
            dist[r][c] = 0;
        if(r>0 && mat[r][c] == 1)
            dist[r][c] = min(dist[r][c], dist[r-1][c]+1);
        if(c>0 && mat[r][c] == 1)
            dist[r][c] = min(dist[r][c], dist[r][c-1]+1);
        if(r<mat.size()-1 && mat[r][c] == 1)
            dist[r][c] = min(dist[r][c], dist[r+1][c]+1);
        if(c<mat[0].size()-1 && mat[r][c] == 1)
            dist[r][c] = min(dist[r][c], dist[r][c+1]+1);
    }
};

int main()
{
    Solution sol = Solution();
    vector<vector<int>> arr = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> updateMatrix = sol.updateMatrix(arr);
    cout << " " << endl;
}