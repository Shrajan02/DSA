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
private:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;  // first half
        ListNode* fast = head;  // second half
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeLL(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = new ListNode(0);
        ListNode* tail = head;  // Tracks end of the merged list

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        // Attach remaining nodes
        tail->next = l1 ? l1 : l2; 

        return head->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        // Merge Sort approach: O(n*logn)
        if (!head || !head->next) return head; // Base case

        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = nullptr;  // Breaks the list
        
        // Recursively split and sort both halves
        left = sortList(left);
        right = sortList(right);

        // Merge the sorted halves
        ListNode* result = mergeLL(left, right);
        return result;
    }
};