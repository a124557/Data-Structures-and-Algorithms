class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstRowZero = false;
        bool firstColumnZero = false;

        // check if first row is zero
        for (int i = 0; i < m; i++)
        {
            if (matrix[0][i] == 0)
            {
                firstRowZero = true;
            }
        }

        // check if first colum is zero
        for (int j = 0; j < n; j++)
        {
            if (matrix[j][0] == 0)
            {
                firstColumnZero = true;
            }
        }

        // set markers in first row for zeros
        for (int a = 1; a < n; a++)
        {
            for (int b = 1; b < m; b++)
            {
                if (matrix[a][b] == 0)
                {
                    matrix[0][b] = 0;
                    matrix[a][0] = 0;
                }
            }
        }

        // set zeros where they need to go based on markers
        for (int a = 1; a < n; a++)
        {
            for (int b = 1; b < m; b++)
            {
                if (matrix[0][b] == 0 || matrix[a][0] == 0)
                {
                    matrix[a][b] = 0;
                }
            }
        }

        // set first row zero if true
        if (firstRowZero)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[0][i] = 0;
            }
        }

        // set first column zero if trye
        if (firstColumnZero)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[j][0] = 0;
            }
        }
    }
};