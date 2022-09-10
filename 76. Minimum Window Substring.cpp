class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> str{};
        unordered_map<char, int> temp{};
        int l = 0, count = 0;
        vector<int> arr = {0, 0, -1};

        // Edge case
        if (t.length() > s.length())
        {
            return "";
        }

        // Place all letters in string 't' into hashmap 'str'
        for (int i = 0; i < t.size(); i++)
        {
            str[t[i]]++;
        }

        for (int r = 0; r < s.length(); r++)
        {

            if (str.find(s[r]) != str.end())
            {
                temp[s[r]]++;

                if (str[s[r]] == temp[s[r]])
                {
                    count++;
                }

                while (count == str.size())
                {
                    if (arr[2] == -1 || (r - l + 1) < arr[2])
                    {
                        arr.erase(arr.begin());
                        arr.insert(arr.begin(), l);

                        arr.erase(arr.begin() + 1);
                        arr.insert(arr.begin() + 1, r);

                        arr.erase(arr.begin() + 2);
                        arr.insert(arr.begin() + 2, r - l + 1);
                    }

                    if (str.find(s[l]) != str.end())
                    {
                        temp[s[l]]--;
                        if (temp[s[l]] < str[s[l]])
                        {
                            count--;
                        }
                    }
                    l++;
                }
            }
        }

        return arr[2] == -1
                   ? ""
                   : s.substr(arr[0], arr[1] - arr[0] + 1);
    }
};