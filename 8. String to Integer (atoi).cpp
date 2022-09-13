class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0) {
            return 0;
        }
        
        //Remove leading spaces
        int i = 0;
        while(s[i] == ' ') {
            s.erase(i,1);
        }
        
        
        //Check sign and read it in
        int sign = 0;
        
        if(s[i] == '-') {
            sign = -1;
            s.erase(i,1);
        }
        
        else if(s[0] == '+') {
            sign = 1;
            s.erase(i,1);
        }
        else {
            sign = 1;
        }
        
        //Convert digits into integer
        i = 0;
        int result = 0;    
        while(i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';
            if((result > INT_MAX/10) || (result == INT_MAX/10 && digit > INT_MAX % 10)) {
                return sign == 1
                ? INT_MAX
                : INT_MIN;
                }
            
            //Append current digit to result
            result = 10 * result + digit;
            i++;
        }
        
        
        
        
        
        
        
        cout << s << endl;
        return result * sign;
    }
};