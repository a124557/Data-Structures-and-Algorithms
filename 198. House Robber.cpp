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
        vector<int> arr(nums.size());
        // Initialize arr with max we can rob from first house and second house
        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            /* The max we can get from the current house is equal to the
            max we can get from the previous house and the max from the
            house before the previous house and the current house*/
            arr[i] = max(arr[i - 1], arr[i - 2] + nums[i]);
        }

        return arr[nums.size() - 1];
    }
};