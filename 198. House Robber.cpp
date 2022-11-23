class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int rob1 = 0;
        int rob2 = 0;
        int temp;

        //[rob1, rob2, n, n+1...]
        for (int i : nums)
        {
            temp = max(i + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};