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
    void reorderList(ListNode *head)
    {
        // Split the lists in half
        ListNode *linear = head;
        ListNode *even = head->next;

        while (even && even->next)
        {
            linear = linear->next;
            even = even->next->next;
        }

        // Linear is at end of first list. Set Linear = Linear->next so it becomes head of second list. Split the lists.
        ListNode *second = linear->next;
        ListNode *prev = NULL;
        linear->next = NULL;
        ListNode *tmp;

        // Reverse the second half of the list.
        while (second)
        {
            tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // Join both the first and second half of the list. prev is now the head of second list.
        ListNode *first = head;
        second = prev;
        ListNode *tmp1;
        ListNode *tmp2;

        // Create a while loop that exits when prev is NULL because prev can sometimes be shorter than the first list (for example when the list has an odd number of nodes).

        while (second)
        {
            tmp1 = first->next;
            tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};