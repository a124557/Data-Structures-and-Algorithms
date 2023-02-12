class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

/*

n.size = 5

m.size = 3

n/i = "abcde"

m/j = "ace"

dp =
     a   c   e
a [ [0],[0],[0],[0] ],
b [ [0],[1],[1],[1] ],
c [ [0],[1],[1],[1] ],
d [ [0],[1],[2],[2] ],
e [ [0],[1],[2],[2] ],
  [ [0],[1],[2],[3] ]

If the chars are equal, dp[i][j] equals the value of dp[i-1][j-1] (previous diagonal) + 1
If the chars are not equal, dp[i][j] equals the max value of dp[i-1][j] and dp[i][j-1]



*/