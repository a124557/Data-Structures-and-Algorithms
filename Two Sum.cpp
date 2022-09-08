class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> list{};
        vector<int> res{};

        for (int i = 0; i < nums.size(); i++)
        {
            if (list.find(target - nums[i]) != list.end())
            {
                res.insert(res.end(), {i, list.find(target - nums[i])->second});
            }
            list.insert({nums[i], i});
        }

        return res;
    }
};