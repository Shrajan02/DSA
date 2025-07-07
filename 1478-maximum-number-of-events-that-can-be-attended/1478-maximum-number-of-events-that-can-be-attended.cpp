// Sorting + Set + Lower Bound approach
// TC: O(nlogn + nlogd), d -> maxDay
// SC: O(d)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int count = 0;

        // sort events by end time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // prepopulate all possible days
        set<int> availableDays;
        int maxDay = events.back()[1];
        for (int day = 1; day <= maxDay; day++) {
            availableDays.insert(day);
        }

        // attend each event on the earliest possible day
        for (auto& event : events) {
            int start = event[0], end = event[1];
            auto it = availableDays.lower_bound(start); // find earliest day >= start
            if (it != availableDays.end() && *it <= end) { // check event within range
                availableDays.erase(it); // mark day as used to prevent conflict
                count++;
            }
        }

        return count;
    }
};