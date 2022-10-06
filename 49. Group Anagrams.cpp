class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res {};
        
        for(int i = 0; i < strs.size(); i++) {
            vector<int> temp(26, 0);
            for(int j = 0; j < strs[i].length(); j++) {
                temp[int(strs[i][j]) - int('a')]++;
            }
            
            string key = "";
            for(auto a:temp) {
                key += to_string(a) + ",";
            }
            cout << key << endl;
            
            res[key].push_back(strs[i]);
        }
        
        vector<vector<string>> sol {};
        for(auto it = res.begin(); it != res.end(); it++) {
            sol.push_back(it->second);
        }
        return sol;
    }
};