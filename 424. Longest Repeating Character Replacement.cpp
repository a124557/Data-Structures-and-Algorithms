class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> letters{};
        int res, maxLen = 0, len, l = 0;

        for (int r = 0; r < s.length(); r++)
        {

            // Increment letter in hash table
            letters[s[r]]++;

            // Get highest length of letters in table
            for (auto &p : letters)
            {
                len = max(len, p.second);
            }

            // If string length - highest letter count < k
            while ((r - l + 1) - len > k)
            {
                letters[s[l]]--;
                l++;
            }

            /*Return the max length of the string to be equal
            the max value of previous 'maxLen' and current string
            length which is 'r-l+1'*/
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

/*
k=1

AABABBA


*/