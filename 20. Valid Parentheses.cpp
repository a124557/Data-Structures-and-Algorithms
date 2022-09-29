class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> list = { {')','('}, {']','['}, {'}','{'} };
        stack<char> openBrackets = {};
        
        if(s.length() % 2 != 0) {
            return false;
        }
        
        for(auto i:s) {
            if(list.find(i) == list.end()) {
                openBrackets.push(i);
            }
            else if(openBrackets.size() != 0 && list[i] == openBrackets.top()) {
                openBrackets.pop();
            }
            else {
                return false;
            }

        }
        
        return openBrackets.size() == 0
            ? true
            : false;
        
    }
};