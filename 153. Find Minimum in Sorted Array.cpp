class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // If the mid number is greater than the rightmost (high),
            // the number must be on the right side
            if (nums[mid] > high)
            {
                low = mid + 1;
            }
            // If nums(mid) <= high set high = mid
            else
            {
                high = mid;
            }
        }
        return nums[low];
    }
};