// greedy sorting approach
// TC: O(nlogn + n)
// SC: O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        std::sort(intervals.begin(), intervals.end());  // sort by start time

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            vector<int>& lastMergedInterval = mergedIntervals.back();
            if (lastMergedInterval[1] >= intervals[i][0]) {
                // merge
                lastMergedInterval[1] = std::max(intervals[i][1], lastMergedInterval[1]);
            }
            else {
                // simply push without merging
                mergedIntervals.push_back(intervals[i]);
            }
        }

        return mergedIntervals;
    }
};