class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<int> nums = {};
        int l = 0, res = 0;

        for (int r = 0; r < s.length(); r++)
        {
            while (nums.find(s[r]) != nums.end())
            {
                nums.erase(s[l]);
                l++;
            }
            nums.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
