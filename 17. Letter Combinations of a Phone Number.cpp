class Solution {
public:
    
    void letterCombinations(string digits, vector<string> &res, vector<string> nums, int i, string s) {
        if(i == digits.length()) {
            res.push_back(s);
            return;
        }
        
        string val = nums[digits[i] - '0'];
        for(int j = 0; j < val.length(); j++) {
            letterCombinations(digits, res, nums, i+1, s+val[j]);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> res {};
        if(digits.length() == 0) {
            return res;
        }
        vector<string> nums {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        letterCombinations(digits, res, nums, 0, "");
        return res;
    }
};