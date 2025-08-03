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

// Priority Queue approach
// TC: O(n*logk)
// SC: O(k)
class Solution {
private:
    struct Compare {
        bool operator() (ListNode* a, ListNode* b) { 
            return a->val > b->val;  // if 'a' is greater (true), 'b' rises to top 
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* result = new ListNode(0); // dummy node
        ListNode* tail = result; // traversal node
        std::priority_queue<ListNode*, vector<ListNode*>, Compare> minH; 

        // only push the head of linked list
        for (int i = 0; i < k; i++) {
            if (lists[i]) {
                minH.push(lists[i]);
            }
        }

        while (!minH.empty()) {
            ListNode* smallest = minH.top();
            minH.pop();
            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {  
                minH.push(smallest->next);
            }
        }

        return result->next;
    }
};