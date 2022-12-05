class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        map<char, int> word1{};
        map<char, int> word2{};

        if (s.length() != t.length())
        {
            return false;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (word1.count(s[i]) == 0)
            {
                word1.insert({s[i], 1});
            }
            else
            {
                word1[s[i]]++;
            }

            if (word2.count(t[i]) == 0)
            {
                word2.insert({t[i], 1});
            }
            else
            {
                word2[t[i]]++;
            }
        }

        return word1 == word2
                   ? true
                   : false;
    }
};