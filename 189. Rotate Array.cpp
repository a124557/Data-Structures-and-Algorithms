class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> newArr(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            newArr[(i + k) % nums.size()] = nums[i];
        }
        for (int j = 0; j < nums.size(); j++)
        {
            nums[j] = newArr[j];
        }
    }
};
