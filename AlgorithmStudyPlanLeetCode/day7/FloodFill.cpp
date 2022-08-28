#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>>visited(image.size(),vector<bool>(image[0].size(),false));
        int startColor = image[sr][sc];
        queue<pair<int,int>>bfsQ;
        bfsQ.push(pair<int,int>(sr,sc));
        while(!bfsQ.empty())
        {
            pair<int,int>box = bfsQ.front();
            sr = box.first;
            sc = box.second;
            bfsQ.pop();
            if(image[sr][sc] != startColor || visited[sr][sc] == true )
                continue;
            visited[sr][sc] = true;
            image[box.first][box.second] = color;
            if(sr != image.size()-1)
                bfsQ.push(pair<int,int>(sr+1,sc));
            if(sr != 0)
                bfsQ.push(pair<int,int>(sr-1,sc));
            if(sc != image[0].size()-1)
                bfsQ.push(pair<int,int>(sr,sc+1));
            if(sc != 0)
                bfsQ.push(pair<int,int>(sr,sc-1));
        }     
        return image;
    }
};
int main()
{
    Solution sol = Solution();
    vector<vector<int>> arr = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> counter = sol.floodFill(arr,1,1,2);
    cout << " " << endl;
}