#include "AllInclude.h"

class Solution {
    public:
        void dfs(vector<vector<int>>& image, int r, int c, int old, int newColor)
        {
            if(r < 0 || r > image.size() - 1)
                return;
            if(c < 0 || c > image[0].size() - 1)
                return;
            if(image[r][c] == newColor)
                return;
            if(image[r][c] != old)
                return;
            image[r][c] = newColor;
            if(r > 0)
                dfs(image, r - 1, c, old, newColor);
            if(r < image.size() - 1)
                dfs(image, r + 1, c, old, newColor);
            if(c > 0)
                dfs(image, r, c - 1, old, newColor);
            if(c < image[0].size() - 1)
                dfs(image, r, c + 1, old, newColor);
        }

        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            int old = image[sr][sc];
            dfs(image, sr, sc, old, newColor);       
            return image;
        }
};
