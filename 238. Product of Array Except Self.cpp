class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res{};
        int prefix = 1;
        // {}
        // Prefix {1,1,2,6}
        // Postfix {24,12,4,1}

        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(prefix);
            prefix = nums[i] * prefix;
        }

        int postfix = 1;

        for (int j = nums.size() - 1; j >= 0; j--)
        {
            res[j] *= postfix;
            postfix *= nums[j];
        }

        return res;
    }
};