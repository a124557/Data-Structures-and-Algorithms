class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        
        vector<int> numList {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        for(int i = 0; i < numList.size(); i++) {
            if(num/numList[i] >= 1) {
                while(num/numList[i] >= 1) {
                    res += roman[i];
                    num -= numList[i];
                    cout << res << endl;
                }
            }
            
        }
        
        return res;
    }
};