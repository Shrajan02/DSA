// Sorting approach
// TC: O(nlogn)
// SC: O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());  // based on start time

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            vector<int>& lastMerged = mergedIntervals.back();  // reference to previous interval
            if (lastMerged[1] < intervals[i][0]) {
                mergedIntervals.push_back(intervals[i]);
            }
            else {
                lastMerged[1] = max(intervals[i][1], lastMerged[1]);  // merging 
            }
        }
        return mergedIntervals;
    }
};