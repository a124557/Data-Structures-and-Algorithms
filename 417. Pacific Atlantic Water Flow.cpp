class Solution
{
private:
    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j, int m, int n, int pre, vector<pair<int, int>> &ocean)
    {
        // Check if cell is out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < pre)
        {
            return;
        }
        visited[i][j] = true;
        ocean.push_back({i, j});
        dfs(matrix, visited, i - 1, j, m, n, matrix[i][j], ocean);
        dfs(matrix, visited, i + 1, j, m, n, matrix[i][j], ocean);
        dfs(matrix, visited, i, j - 1, m, n, matrix[i][j], ocean);
        dfs(matrix, visited, i, j + 1, m, n, matrix[i][j], ocean);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> result;
        if (heights.empty())
        {
            return result;
        }
        // Number of rows and columns
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        vector<pair<int, int>> pacific_flows;
        vector<pair<int, int>> atlantic_flows;
        // Iterate through first row and last column of matrix and call dfs function to check for cells that can flow to the 'pacific' and 'atlantic' oceans from the edge of the matrix
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0, m, n, INT_MIN, pacific_flows);
            dfs(heights, atlantic, i, n - 1, m, n, INT_MIN, atlantic_flows);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j, m, n, INT_MIN, pacific_flows);
            dfs(heights, atlantic, m - 1, j, m, n, INT_MIN, atlantic_flows);
        }
        // Iterate through matrix again and check each cell if it can flow to both pacific and atlantic oceans by checking if it's marked in both the 'pacific' and 'atlantic' arrays. If so, add the cell to the final result
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};