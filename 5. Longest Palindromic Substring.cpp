class Solution
{
public:
    string longestPalindrome(string s)
    {
        string res = "";
        int resLen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            // odd strings
            int l = i;
            int r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r])
            {
                if ((r - l + 1) > resLen)
                {
                    resLen = r - l + 1;
                    res = s.substr(l, resLen);
                }
                l--;
                r++;
            }

            // even strings
            int left = i;
            int right = i + 1;

            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if ((right - left + 1) > resLen)
                {
                    resLen = right - left + 1;
                    res = s.substr(left, resLen);
                }
                left--;
                right++;
            }
        }
        return res;
    }
};