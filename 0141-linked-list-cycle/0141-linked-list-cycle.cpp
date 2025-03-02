/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == nullptr)
            return false;

        // Floyd's Cycle Detection Algo (Tortoise-Hare Algo)
        ListNode* slow = head, *fast = head;
        while (fast != NULL && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) 
                return true;
        }
        return false;
    }
};