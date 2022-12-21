class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (lower.empty())
        {
            lower.push(num);
            return;
        }

        if (lower.size() > higher.size())
        {
            if (lower.top() > num)
            {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            }
            else
            {
                higher.push(num);
            }
        }
        else
        {
            if (num > higher.top())
            {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            }
            else
            {
                lower.push(num);
            }
        }
    }

    double findMedian()
    {
        double result = 0.0;

        // If both heaps are same size, add lower.top() and higher.top() together and divide by 2
        if (lower.size() == higher.size())
        {
            result = (lower.top() + higher.top()) / 2.0;
            return result;
        }
        // If lower > higher, return lower.top() since it will have the median
        else if (lower.size() > higher.size())
        {
            return lower.top();
        }
        // Otherwise, return higher.top()
        else
        {
            return higher.top();
        }
    }

private:
    // Max heap
    priority_queue<int> lower;
    // Min heap
    priority_queue<int, vector<int>, greater<int>> higher;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */