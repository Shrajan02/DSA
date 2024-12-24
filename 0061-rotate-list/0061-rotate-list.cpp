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
    ListNode* reverseLL(ListNode* head, ListNode* prev = NULL) {
        if (!head) return prev;
        ListNode* next = head->next;
        head->next = prev;
        return reverseLL(next, head);
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;

        // Calculate length of list
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        k = k % length;
        if (k == 0)
            return head;

        // Reversal Algorithm
        head = reverseLL(head);
        ListNode* first = head;
        ListNode* second = nullptr;
        temp = head;
        while (temp && k > 1) {
            temp = temp->next;
            k--;
        }
    
        second = temp->next; // head of remaining nodes
        temp->next = nullptr;  // disconnect both parts

        first = reverseLL(first);
        second = reverseLL(second);

        temp = first;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = second;
        return first;
    }
};