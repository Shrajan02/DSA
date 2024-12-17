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
    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next) 
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;

        while (curr) {
            forward = curr->next;  
            curr->next = prev;  
            // Move pointers forward
            prev = curr;
            curr = forward;  
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        
        // Find the middle of LL
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Check if first half = reverse of second half
        ListNode* newHead = reverseLL(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while (second) {
            if (first->val != second->val) {
                reverseLL(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverseLL(newHead);
        return true;
    }
};