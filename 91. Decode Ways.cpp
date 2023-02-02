class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        int n = s.size();
        vector<int> arr(n + 1);
        arr[0] = 1, arr[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0')
                arr[i] = arr[i - 1];
            if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')
                arr[i] += arr[i - 2];
        }
        return arr[n];
    }
};