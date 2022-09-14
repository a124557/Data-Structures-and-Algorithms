class Solution {
public:
    bool isPalindrome(int x) {
        string original = to_string(x);
        string output = "";
        for(int i = 0; i < original.length(); i++) {
            output = original[i] + output;
        }
        if(output == original) {
            return true;
        }
        else {
            return false;
        }
    }
};