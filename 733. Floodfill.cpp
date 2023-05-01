class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        dfs(image, sr, sc, color, image[sr][sc]);

        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int oldColor)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] == color || image[sr][sc] != oldColor)
            return;

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, color, oldColor);
        dfs(image, sr - 1, sc, color, oldColor);
        dfs(image, sr, sc + 1, color, oldColor);
        dfs(image, sr, sc - 1, color, oldColor);
    }
};