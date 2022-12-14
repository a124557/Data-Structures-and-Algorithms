class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int result = nums[0] + nums[1] + nums[nums.size() - 1];
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int start = i + 1;
            int end = nums.size() - 1;

            while (start < end)
            {
                int currentSum = nums[i] + nums[start] + nums[end];

                if (currentSum > target)
                {
                    end--;
                }
                else
                {
                    start++;
                }

                if (abs(target - currentSum) < abs(target - result))
                {
                    result = currentSum;
                }
            }
        }
        return result;
    }
};
