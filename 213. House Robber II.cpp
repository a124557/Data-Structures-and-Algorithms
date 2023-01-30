class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        return max(maxRob(nums, 0, nums.size() - 1), maxRob(nums, 1, nums.size()));
    }

private:
    int maxRob(vector<int> &nums, int l, int r)
    {
        int pre = 0, curr = 0, temp = 0;
        for (int i = l; i < r; i++)
        {
            temp = max(pre + nums[i], curr);
            pre = curr;
            curr = temp;
        }
        return temp;
    }
};