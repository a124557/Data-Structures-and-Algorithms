class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int max_product = nums[0], min_product = nums[0], maxTotal = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(max_product, min_product);
            max_product = max(nums[i], max_product * nums[i]);
            min_product = min(nums[i], min_product * nums[i]);
            maxTotal = max(max_product, maxTotal);
        }
        return maxTotal;
    }
};