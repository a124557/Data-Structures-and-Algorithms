class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int pointer = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[pointer] == 0)
            {
                nums.erase(nums.begin() + pointer);
                nums.push_back(0);
                i++;
            }
            else
            {
                i++;
                pointer++;
            }
        }
    }
};

/*


    0              1                2               3                4
[0,1,0,3,12] => [1,0,3,12,0] => [1,0,3,12,0] => [1,3,12,0,0] => [1,3,12,0,0]

counter = 1
i = 0

[0,0,12]

counter = 2
i = 1

[0,12]

counter = 3
i = 2

[12]

counter = 3
i = 3

End loop and push back i zeros

[12,0,0,0]





*/