class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.empty())
        {
            return result;
        }
        // m are rows, n are columns
        int m = matrix.size();
        int n = matrix[0].size();
        int row_start = 0;
        int row_end = m - 1;
        int col_start = 0;
        int col_end = n - 1;

        while (row_start <= row_end && col_start <= col_end)
        {
            // Traverse left to right
            for (int i = col_start; i <= col_end; i++)
            {
                result.push_back(matrix[row_start][i]);
            }
            // Increment row
            row_start++;

            // Traverse top to bottom
            for (int j = row_start; j <= row_end; j++)
            {
                result.push_back(matrix[j][col_end]);
            }
            // Decrement column length
            col_end--;

            // Traverse right to left
            if (row_start <= row_end)
            {
                for (int k = col_end; k >= col_start; k--)
                {
                    result.push_back(matrix[row_end][k]);
                }
            }
            // Decrement row_end length
            row_end--;

            // Traverse from bottom to top
            if (col_start <= col_end)
            {
                for (int l = row_end; l >= row_start; l--)
                {
                    result.push_back(matrix[l][col_start]);
                }
            }
            col_start++;
        }

        return result;
    }
};
