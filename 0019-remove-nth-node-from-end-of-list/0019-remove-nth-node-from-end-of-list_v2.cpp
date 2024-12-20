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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 2-pass solution
        // 1. Find the length of LL
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            count++;
        }

        // 2. Traverse to the position from start -> previous node 
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        temp = dummy;
        int k = (count - n);  // (5 - 2) = 3 traversals: dummy -> 1(head) -> 2 -> 3
        while (k--) {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return dummy->next;
    }
};
