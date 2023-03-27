class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int num = 0, n = intervals.size(), i = 0;
        sort(intervals.begin(), intervals.end());

        while (i < n - 1)
        {
            if (intervals[i][1] > intervals[i + 1][0])
            {
                intervals[i + 1][0] = max(intervals[i][0], intervals[i + 1][0]);
                intervals[i + 1][1] = min(intervals[i][1], intervals[i + 1][1]);
                num++;
            }
            i++;
        }

        return num;
    }
};