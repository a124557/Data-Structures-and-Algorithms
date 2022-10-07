class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> items {};
        
        for(int i:nums) {
            if(items.find(i) != items.end()) {
                return true;
            }
            items.insert(i);
        }
        return false;
    }
};