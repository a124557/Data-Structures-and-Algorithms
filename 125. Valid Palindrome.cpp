class Solution
{
public:
    bool isPalindrome(string s)
    {
        string modded;
        string reversed;

        // Filter the string
        for (auto i : s)
        {
            if (int(i) >= 97 && int(i) <= 122 || int(i) >= 48 && int(i) <= 57)
            {
                modded += i;
            }
            else if (int(i) >= 65 && int(i) <= 90)
            {
                modded += tolower(i);
            }
        }

        // Reverse string
        for (int j = modded.size() - 1; j >= 0; j--)
        {
            reversed += modded[j];
        }

        // Compare
        return modded == reversed
                   ? true
                   : false;
    }
};