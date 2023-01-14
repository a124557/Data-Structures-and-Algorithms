class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        // Rows and columns size
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, 0, i, j, m, n))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, string word, int index, int i, int j, int m, int n)
    {
        // Checking for out of bounds conditions
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index])
        {
            return false;
        }

        // If the index is equal to the size of the word return true
        if (index == word.size() - 1)
        {
            return true;
        }

        // Change char at current index to '#' indicating it has been visited
        board[i][j] = '#';

        // Check all surrounding letters for matches
        if (dfs(board, word, index + 1, i - 1, j, m, n) ||
            dfs(board, word, index + 1, i + 1, j, m, n) ||
            dfs(board, word, index + 1, i, j - 1, m, n) ||
            dfs(board, word, index + 1, i, j + 1, m, n))
        {
            return true;
        }

        /* Reset letter back to what it was if we don't find a word so it doesn't
        interfere with other checks */
        board[i][j] = word[index];
        return false;
    }
};