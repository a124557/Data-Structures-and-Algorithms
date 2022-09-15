class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0,right = height.size()-1, area = 0,length,width;
    
        while(left < right) {
            length = min(height[left], height[right]);
            area = max(length*(right-left), area);
            
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return area;
    }
};
