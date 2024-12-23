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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 2-pointer approach
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != tempB) {
            if (!tempA) {
                tempA = headB;
            }
            else {
                tempA = tempA->next;
            }

            if (!tempB) {
                tempB = headA;
            }
            else {
                tempB = tempB->next;
            }
        }
        return tempA;
    }
};