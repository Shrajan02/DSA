// Sliding Window over Gaps approach
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        // calculate free times between events
        vector<int> freeTimes(n + 1, 0);
        freeTimes[0] = startTime[0]; // before first event
        for (int i = 1; i < n; i++) {
            freeTimes[i] = startTime[i] - endTime[i - 1];
        }
        freeTimes[n] = eventTime - endTime.back(); // after last event

        // since gaps need to be continuous
        // k shifts merge (k + 1) gaps
        // apply sliding window on (k + 1) gaps
        // [1, 1] ; k = 1
        int len = freeTimes.size();
        int maxFreeTime = 0, currSum = 0;
        int start = 0;
        for (int end = 0; end < len; end++) {
            currSum += freeTimes[end];
            if (end - start + 1 > k + 1) {
                currSum -= freeTimes[start];
                start++;
            }
            maxFreeTime = std::max(currSum, maxFreeTime);  // update for all valid windows (≤ k shifts), as fewer reschedulings may give max
        }

        return maxFreeTime;
    }
};