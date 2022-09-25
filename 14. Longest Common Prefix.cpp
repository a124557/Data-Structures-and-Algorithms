class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
        //Edge case
        if(strs.size() == 0) {
            return "";
        }
        
        string res = strs[0];

        for(int i = 1; i < strs.size(); i++) {
            while(strs[i].find(res) != 0) {
                res.erase(res.end()-1);
            }
        }

        
        return res;
        
    }
};


