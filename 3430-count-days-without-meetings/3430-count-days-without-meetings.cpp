// Sorting approach
// TC: O(n * log(n))
// SC: O(n)
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());  // based on start time

        // merge overlapping meetings
        vector<vector<int>> mergedMeetings;
        mergedMeetings.push_back(meetings[0]);
        for (int i = 1; i < n; i++) {
            vector<int>& lastMerged = mergedMeetings.back();  // reference to last meeting
            if (lastMerged[1] >= meetings[i][0]) {
                lastMerged[1] = max(lastMerged[1], meetings[i][1]);  // check for overlap
            }
            else {
                mergedMeetings.push_back(meetings[i]);
            }
        }

        // calculate days with no meetings
        int noMeetDays = days;
        for (auto& interval: mergedMeetings) {
            noMeetDays -= (interval[1] - interval[0] + 1);
        }

        return noMeetDays;
    }
};