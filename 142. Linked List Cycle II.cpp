/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        /*Increment slow pointer by 1 and fast pointer by 2. By doing this, eventually
        the fast pointer will catch up to the slow pointer indicating that there is a
        cycle in the list. Since the slow pointer moves by 1 node at a time, and the
        slow pointer moves by 2 nodes at a time, the fast pointer gets 1 node closer
        to the slow pointer with each iteration of the while loop. If there is a cycle in
        the list, the fast pointer will eventually meet the slow pointer at which point
        they will equal each other indicating a cycle in the list.

        If no cycle exists, eventually fast->next will be null and the while loop will
        exit resulting in the code returning false.*/
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};