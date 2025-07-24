// Heap approach
// TC: O(n.logk)
// SC: O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // kth largest -> use min heap of size k
        std::priority_queue<int, std::vector<int>, std::greater<int>> minH;

        for (int num: nums) {
            minH.push(num);
            if (minH.size() > k) {
                minH.pop();
            }
        }

        int kMax = minH.top();
        return kMax;
    }
};
