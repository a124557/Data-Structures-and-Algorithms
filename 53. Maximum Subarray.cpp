class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int currentSum = 0;
        int maxSum = 0;

        if (nums.size() == 1)
        {
            return nums[0];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            currentSum = currentSum + nums[i];
            if (maxSum == 0 && i == nums.size() - 1)
            {
                sort(nums.begin(), nums.end());
                return nums[nums.size() - 1];
            }
            else if (currentSum < 0)
            {
                currentSum = 0;
            }
            else if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
        }
        return maxSum;
    }
};

/*

[-2,1,-3,4,-1,2,1,-5,(4)]

1. Create a variable to store global maximum. Initialise with most negative number(INT_MIN).
2. Create a variable to store current sum. Initialise with zero.
3. Run a loop from left to right over the array. If current sum has become negative then update it with value 0.
4. Add the current element to current sum and update the global maximum if current sum is greater than global maximum.
5. Return the global maximum.

currentSum = 5;
maxSum = 6






*/

/*

[5,4,-1,7,8]

currentSum = 15;
maxSum = 15;





*/