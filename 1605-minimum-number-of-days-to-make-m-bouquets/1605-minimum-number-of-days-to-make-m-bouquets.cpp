class Solution {
public:
    int calculateBouquets(vector<int>& bloomDay, int day, int m, int k) {
        // Adjacency is taken care by 'streak'
        long long streak = 0, bq = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                streak++;
                if (streak == k) {
                    bq++;
                    streak = 0;
                }
            } else {
                streak = 0;
            }
        }
        return bq;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // Impossible case
        if ((long)m * k > n) {
            return -1;
        }
        // Finding Min & Max element
        int minDay = bloomDay[0], maxDay = bloomDay[0];
        for (int i = 1; i < n; i++) {
            if (bloomDay[i] < minDay) {
                minDay = bloomDay[i];
            }
            if (bloomDay[i] > maxDay) {
                maxDay = bloomDay[i];
            }
        }

        // Binary search approach
        int low = minDay, high = maxDay;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int result = calculateBouquets(bloomDay, mid, m, k);
            if (result >= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};