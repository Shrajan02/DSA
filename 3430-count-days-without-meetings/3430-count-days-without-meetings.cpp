// Sorting approach
// TC: O(n * log(n))
// SC: O(1)
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());  // based on start time

        int noMeetDays = 0;
        int end = 0;
        for (auto& meet: meetings) {
            if (meet[0] > end) {
                noMeetDays += meet[0] - end - 1;
            }
            end = max(meet[1], end);  // merge overlapping meetings
        }

        // remaining days
        if (days > end) {
            noMeetDays += (days - end);
        }

        return noMeetDays;
    }
};