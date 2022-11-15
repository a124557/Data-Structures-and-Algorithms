class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int l = 0, r = 1, maxProfit = 0;

        while (r < prices.size())
        {
            if (prices[l] < prices[r])
            {
                maxProfit = max(prices[r] - prices[l], maxProfit);
                r++;
            }
            else
            {
                l = r;
                r++;
            }
        }
        return maxProfit;
    }
};