class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        sort(intervals.begin(), intervals.end());

        while (i < n - 1)
        {
            if (intervals[i][1] >= intervals[i + 1][0])
            {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
            i++;
        }

        res.push_back(intervals[i]);

        return res;
    }
};