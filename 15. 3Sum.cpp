class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res {};
        int l, r, threeSum;
        sort(nums.begin(), nums.end());
        
        for(int a = 0; a < nums.size(); a++) {
            //Break one iternation if next number is same as previous
            if(a > 0 && nums[a] == nums[a-1]) {
                continue;
            }
            
            l = a+1, r = nums.size()-1;
            while(l < r) {
                threeSum = nums[a]+nums[l]+nums[r];
                if(threeSum > 0) {
                    r--;
                }
                else if(threeSum < 0) {
                    l++;
                }
                else {
                    vector<int> temp {nums[a],nums[l],nums[r]};
                    res.push_back(temp);
                    l++;
                    while(nums[l] == nums[l-1] && l < r) {
                        l++;
                    }
                    
                }
            }
            
        }
        return res;
    }
};