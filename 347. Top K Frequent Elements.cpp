class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;

        // Insert numbers in hashmap as key, and their occurence number as a value
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        // Create a vector of nums.size() length + 1 because each number will correspond to the same index in the array. 0 -> 0, 1->1, etc so we need to add an extra spot in the array to do that
        vector<vector<int>> holding(nums.size() + 1);

        // Iterate through the hashmap and pushback keys in the corresponding index in the array which is also equal to the number of time they occur in the nums array
        for (auto it = m.begin(); it != m.end(); it++)
        {
            holding[it->second].push_back(it->first);
        }

        vector<int> result{};

        for (int j = nums.size(); j >= 0; j--)
        {

            if (result.size() >= k)
            {
                break;
            }
            if (!holding[j].empty())
            {
                result.insert(result.end(), holding[j].begin(), holding[j].end());
            }
        }

        return result;
    }
};