class Solution {
public:
    int romanToInt(string s) {
        vector<string> roman1 {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int res = 0;
       unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;
        
        for(int i = 0; i < s.size(); i++) {
            if(i != s.size() - 1 && roman[s[i]] < roman[s[i + 1]]) {
                res -= roman[s[i]];
            }
            else {
                res += roman[s[i]];
            }
        }
        
        return res;
    }
};