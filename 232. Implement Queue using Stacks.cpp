#include <vector>

using namespace std;

class MyQueue
{
public:
    // declaring stack
    vector<int> stack1;
    vector<int> stack2;
    int front;
    MyQueue()
    {
        // assigning a value to stack
        stack1 = {};
        stack2 = {};
    }

    void push(int x)
    {
        if (stack1.empty())
        {
            front = x;
        }
        stack1.push_back(x);
    }

    int pop()
    {
        if (stack2.empty())
        {
            for (int i = stack1.size() - 1; i > -1; i--)
            {
                stack2.push_back(stack1[i]);
                stack1.pop_back();
            }
        }
        int popped = stack2[stack2.size() - 1];
        stack2.pop_back();

        return popped;
    }

    int peek()
    {
        if (!stack2.empty())
        {
            return stack2[stack2.size() - 1];
        }
        else
        {
            return front;
        }
    }

    bool empty()
    {
        return stack1.empty() && stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */