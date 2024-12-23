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
        // Hash Set approach
        ListNode* listA = headA;
        ListNode* listB = headB;
        unordered_set<ListNode*> hashSet;

        // Building set of visited nodes in 1st list
        while (listA) {
            hashSet.insert(listA);
            listA = listA->next;
        } 

        // Comparing set with 2nd list
        while (listB) {
            if (hashSet.find(listB) != hashSet.end()) {
                return listB;
            }
            listB = listB->next;
        }
        return NULL;
    }
};