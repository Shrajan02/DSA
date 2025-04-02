// Sliding Window approach
// TC: O(k)
// SC: O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        // compute sum of first k elements (from left)
        int leftSum = 0;
        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        if (k == n) return leftSum;  // edge case
        
        int maxSum = leftSum;
        int rightSum = 0;
        // replace from the right side
        for (int i = k - 1; i >= 0; i--) {
            rightSum += cardPoints[n + i - k];  // add right-side card
            leftSum -= cardPoints[i];           // remove left-side card
            maxSum = max(leftSum + rightSum, maxSum);
        }
        return maxSum;
    }
};
