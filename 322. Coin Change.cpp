class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> num(amount + 1, amount + 1);
        num[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    num[i] = min(num[i], num[i - coins[j]] + 1);
                }
            }
        }
        return num[amount] > amount
                   ? -1
                   : num[amount];
    }
};