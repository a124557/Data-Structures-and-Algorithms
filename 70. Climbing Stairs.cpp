class Solution
{
public:
    int climbStairs(int n)
    {
        // 1 way to climb stair 1, 2 ways to climb stair 2
        if (n <= 2)
        {
            return n;
        }
        // a represents 1 way to climb first stair, b represents 2 ways to climb second stair
        // c represents total ways to climb all stairs
        int a = 1, b = 2, c = 0;
        for (int i = 3; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
