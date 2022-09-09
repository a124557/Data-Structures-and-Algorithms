/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int v1 = 0;
        int v2 = 0;
        int val = 0;

        ListNode *result = new ListNode;
        ListNode *curr = result;

        while (l1 || l2 || carry)
        {
            l1 ? v1 = l1->val : v1 = 0;
            l2 ? v2 = l2->val : v2 = 0;

            // new digit
            val = v1 + v2 + carry;
            carry = val / 10; // divide by 10 because C++ rounds floats down to the lowest whole number
            val = val % 10;
            ListNode *newNode = new ListNode(val);
            curr->next = newNode;

            // update ptrs
            curr = curr->next;
            cout << "Val = " << val << endl;
            l1 ? l1 = l1->next : NULL;
            l2 ? l2 = l2->next : NULL;
        }

        return result->next;
    }
};